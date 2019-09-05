//LEO GENOTA
//COSC 214 - DR. STONE
//LINKED LIST IMPLEMENTATION
//OF QUEUES
#include<iostream>
using namespace std;

#include"LinkedQueueType.h"

int main() {
	LinkedQueueType queue;
	int x, y;

	x = 4;
	y = 5;
	queue.addQueue(x);
	queue.addQueue(y);
	x = queue.front();
	queue.deleteQueue();
	queue.addQueue(x + 5);
	queue.addQueue(16);
	queue.addQueue(x);
	queue.addQueue(y - 3);

	cout << "Queue Elements: ";
	while (!queue.isEmptyQueue()) {
		cout << queue.front() << " ";
		queue.deleteQueue();
	}
	cout << endl;

	system("PAUSE");
	return 0;
}