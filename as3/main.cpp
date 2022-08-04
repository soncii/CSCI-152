#include "queue.h"
#include <iostream>

void output(const queue& q) {
	std::cout << q.size() << " " << q.empty() << " " << q << std::endl;
}

// This is a minimal testing file.... we will use something more complete
// for grading!!!
int main() {

	queue q1;
	output(q1);
	try {
		q1.peek();
	}
	catch (std::invalid_argument e) {
		std::cout<<e.what()<<std::endl;
	}
	queue q2 = {11, 22, 33, 44};
	queue q9 = {123,153,65,26};
	output(q2);
	q9=q2;
	q9.push(5);
	std::cout<<"HEY ";
	output(q9);
	queue q3(q2);

	for (int i = 111; i < 222; i = i + 11) {
		q2.push(i);
	}

	output(q2); output(q3);

	q1 = q2;

	for (int x = 0; x < 10; ++x) {
		std::cout << q2.peek() << " ";
		q2.pop();
	}
	std::cout << std::endl;

	output(q1); output(q2);

	q1.clear();
	output(q1); output(q2);

	while (!q2.empty()) {
		std::cout << q2.peek() << " ";
		q2.pop();
	}
	std::cout << std::endl;

	output(q2);
}



