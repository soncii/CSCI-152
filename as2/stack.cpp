#include "stack.h"

stack::stack(const stack& stk):
    stack_size(stk.stack_size),
    array_capacity(stk.array_capacity),
    values(new int[stk.array_capacity])
{
    for (size_t i=0; i<stack_size; i++) {
        values[i]=stk.values[i];
    }
}

stack::stack(std::initializer_list<int> ilist):
    values(new int[ilist.size()*2]),
    stack_size(ilist.size()),
    array_capacity(stack_size*2)
{
    size_t i=0;
    for (auto item:ilist) {
        values[i]=item;
        i++;
    }
}

stack& stack::operator=(const stack& stk)
{
    if (array_capacity!=stk.array_capacity) {
        delete[] values;
        array_capacity=stk.array_capacity;
        values=new int[stk.array_capacity];
    }
    stack_size=stk.stack_size;
    for (size_t i=0; i<stack_size; i++) {
        values[i]=stk.values[i];
    }
    return *this;
}

// Insert an item at the top of the stack
void stack::push(int val) {
    if (stack_size==array_capacity) {
        int* newvalues= new int[array_capacity*2];
        array_capacity*=2;
        for (size_t i=0; i<stack_size; i++) {
            newvalues[i]=values[i];
        }
        delete[] values;
        values=newvalues;
    }
    values[stack_size]=val;
    stack_size++;
}

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const {
    if (stack::empty()) {
        throw std::invalid_argument("cannot peek from an empty stack");
    }
    return values[stack_size-1];
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop() {
    if (stack::empty()) {
        throw std::invalid_argument("cannot pop from an empty stack");
    } 
    stack_size--;
};

// Remove everything from the stack
void stack::clear() {
    stack_size=0;
}


size_t stack::size() const {
    return stack_size;
}

bool stack::empty() const {
    return stack_size==0;
}

stack::~stack() {
    delete[] values;
}