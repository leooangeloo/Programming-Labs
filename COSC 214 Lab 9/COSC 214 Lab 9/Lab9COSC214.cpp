//LEO GENOTA
//COSC 214 - DR. STONE
//ARRAY IMPLEMENTATION OF
//QUEUES
#include<iostream>
using namespace std;

#include"ArrayQueueType.h"

int main() {
	queueType queue;
	int x, y;

	queue.initializeQueue();
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