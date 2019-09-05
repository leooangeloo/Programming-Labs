//LEO GENOTA
//COSC 214 - DR.STONE
//LAB 12 - QUEUES
#include<iostream>
#include"arrayQueue.h"
using namespace std;

void moveNthFront(queueType & queue, queueType & queue2, queueType & queue3, int n);
void displayQueue(queueType queue3);

int main() {
	queueType queue, queue2, queue3;
	int n;

	queue.addQueue(5);
	queue.addQueue(11);
	queue.addQueue(34);
	queue.addQueue(67);
	queue.addQueue(43);
	queue.addQueue(55);

	cout << "Enter an number (n) such that n is the location of an element." << endl;
	cin >> n;

	moveNthFront(queue, queue2, queue3, n);
	displayQueue(queue3);

	system("PAUSE");
	return 0;
}
void moveNthFront(queueType & queue, queueType & queue2, queueType & queue3, int n) {
	int count = 1;
	while (!queue.isEmptyQueue()) {
		if (count != n) {
			queue2.addQueue(queue.front());
			queue.deleteQueue();
		}
		else if (count == n) {
			queue3.addQueue(queue.front());
			queue.deleteQueue();
		}
		count++;
	}
	while (!queue2.isEmptyQueue()) {
		queue3.addQueue(queue2.front());
		queue2.deleteQueue();
	}
} 
void displayQueue(queueType queue3) {
	while (!queue3.isEmptyQueue()) {
		cout << queue3.front() << " ";
		queue3.deleteQueue();
	}
	cout << endl;
}
