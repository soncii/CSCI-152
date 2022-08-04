#include "queue.h"
#include <iostream>
queue::queue(const queue& q):
queue_size(q.queue_size),
front(new node(q.front->value))
{
    node* qit = q.front;
    node* it=front;
    while (qit->next) {
        qit=qit->next;
        it->next=new node(qit->value);
        it=it->next;
    }
    back=it;
}

queue::queue(std::initializer_list<int> ilist):
queue_size(ilist.size())
{
    node* iter=new node(0);
    int i=0;
    for (auto it:ilist) {
        if (i==0) {
            front=new node(it);
        } else if (i==1) {
            iter->value=it;
            front->next=iter;
        } else {
            iter->next=new node(it);
            iter=iter->next;
        }
        back=iter;
        i++;
    }
}

queue& queue::operator=(const queue& q) {
    if (queue_size==q.queue_size) {
        node* it=front;
        node* qit=q.front;
        while(it) {
            it->value=qit->value;
            it=it->next;
            qit=qit->next;
        }
    } else {
        queue_size=q.queue_size;
        while (front) {
            node* temp=front;
            front=front->next;
            delete temp;
        }
        front=new node(q.front->value);
        node* it=front;
        node *qit=q.front;
        while(qit->next) {
            qit=qit->next;
            it->next=new node(qit->value);
            it=it->next;
        }
        back=it;
    }
    return *this;
}

void queue::push(int val) {
    if (queue_size==0) {
        back=new node(val);
        front=back;
        queue_size++;
        return;
    }
    back->next=new node(val);
    back=back->next;
    queue_size++;
}

// Returns the value of the front-most item of the queue;
// throws an exception if the queue is empty
int queue::peek() const {
    if (empty()) {
        throw std::invalid_argument("Cannot peek from empty queue");
    }
    return front->value;
}

// Remove the front-most item from the queue
// throws an exception if the queue is empty
void queue::pop() {
    if (empty()) {
        throw std::invalid_argument("Cannot pop from empty queue");
    }
    node* temp=front;
    front=front->next;
    delete temp;
    queue_size--;
}

// Remove everything from the queue
void queue::clear() {
    while (front) {
            node* temp=front;
            front=front->next;
            delete temp;
        }
    queue_size=0;
}

// Returns the number of items on the queue
size_t queue::size() const {
    return queue_size;
}

// Returns whether or not the queue is currently empty
bool queue::empty() const {
    return queue_size==0;
}

queue::~queue() {
    while (front) {
        node* temp = front;
        front=front->next;
        delete temp;
    }
}