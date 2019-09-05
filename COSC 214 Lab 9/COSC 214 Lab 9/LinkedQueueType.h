struct node {
	int info;
	node * link;
};

class LinkedQueueType {
public:
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	int front() const;
	int back() const;
	void addQueue(const int& newElement);
	void deleteQueue();
	LinkedQueueType();
private:
	node * queueFront;
	node * queueRear;
};

bool LinkedQueueType::isEmptyQueue() const {
	return (queueFront == NULL);
}
bool LinkedQueueType::isFullQueue() const {
	return false;
}
int LinkedQueueType::front() const {
	if (queueFront != NULL)
		return queueFront->info;
}
int LinkedQueueType::back() const {
	if (queueRear != NULL)
		return queueRear->info;
}
void LinkedQueueType::addQueue(const int& newElement) {
	node * newNode = NULL;
	newNode = new node;
	newNode->info = newElement;
	newNode->link = NULL;
	if (queueFront == NULL) {
		queueFront = newNode;
		queueRear = newNode;
	}
	else {
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}
}
void LinkedQueueType::deleteQueue() {
	node * temp;
	if (!isEmptyQueue()) {
		temp = queueFront;
		queueFront = queueFront->link;

		delete temp;

		if (queueFront == NULL) // resets the linked queue back to NULL
			queueRear = NULL;
	}
	else
		cout << "Cannot remove from an empty queue." << endl;
}
LinkedQueueType::LinkedQueueType() {
	queueFront = NULL;
	queueRear = NULL;
}