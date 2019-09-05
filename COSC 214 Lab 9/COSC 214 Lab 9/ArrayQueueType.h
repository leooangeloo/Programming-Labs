class queueType {
public:
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	int front() const;
	int back() const;
	void addQueue(const int& newElement);
	void deleteQueue();
	queueType(int queueSize = 10);
	void initializeQueue();
private:
	int maxQueueSize;
	int count;
	int queueFront;
	int queueRear;
	int * list;
};

bool queueType::isEmptyQueue() const {
	return (count == 0);
}
bool queueType::isFullQueue() const {
	return (count == maxQueueSize);
}
int queueType::front() const {
	if (!isEmptyQueue())
		return list[queueFront];
}
int queueType::back() const {
	if (!isEmptyQueue())
		return list[queueRear];
}
void queueType::addQueue(const int& newElement) {
	if (!isFullQueue()) {
		queueRear = (queueRear + 1) % maxQueueSize;

		count++;
		list[queueRear] = newElement;
	}
	else
		cout << "Cannot add to an empty queue" << endl;
}
void queueType::deleteQueue() {
	if (!isEmptyQueue()) {
		count--;
		queueFront = (queueFront + 1) % maxQueueSize;
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
}
queueType::queueType(int queueSize) {
	if (queueSize <= 0) {
		cout << "The size of the array to hold the queue must "
			<< "be posititve." << endl;
		cout << "Creating an array of size 100." << endl;
		maxQueueSize = 10;
	}
	else
		maxQueueSize = queueSize;

	queueFront = 0; // queueFront starts at 0
	queueRear = maxQueueSize - 1; // queueRear starts as this
	count = 0; // count starts at 0
	list = new int[maxQueueSize];
}
void queueType::initializeQueue() {
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
}