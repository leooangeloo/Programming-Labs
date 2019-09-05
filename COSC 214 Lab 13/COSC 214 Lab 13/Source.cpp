//LEO GENOTA
//COSC 214 - DR. STONE
//LAB 13 - STACK AND QUEUE (COMBINED)
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include"arrayStack.h"
#include"arrayQueue.h"
using namespace std;

int compare(stackType & stack, queueType & queue);

int main() {
	stackType stack;
	queueType queue;
	int num, i = 0;

	while (i <= 100) {
		num = ((rand() + time(0)) % 101) + 1;
		if ((num % 2) == 0)
			queue.addQueue(num);
		else
			stack.push(num);
		i++;
	}

	cout << "There were " << compare(stack, queue) << " occurences"
		<< " where the stack and queue numbers were within 10." << endl;

	system("PAUSE");
	return 0;
}
int compare(stackType & stack, queueType & queue) {
	int counter = 0;
	cout << "S:" << " " << "Q:" << endl;
	while (!stack.isEmptyStack() && !queue.isEmptyQueue()) {
		cout << stack.top() << " " << queue.front() << endl;
		if (abs(stack.top() - queue.front()) <= 10)
			counter++;
		stack.pop();
		queue.deleteQueue();
	}
	return counter;
}