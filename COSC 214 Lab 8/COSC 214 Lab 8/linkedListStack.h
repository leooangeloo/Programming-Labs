struct node {
	int num;
	node * link;
};

class linkedStackType {
public:
	bool isFullStack() const;
	bool isEmptyStack() const;
	void push(const int & newElement);
	int top() const;
	void pop();
	linkedStackType();
private:
	node * stackTop;
};

bool linkedStackType::isFullStack() const {
	return false;
}
bool linkedStackType::isEmptyStack() const {
	return (stackTop == NULL);
}
void linkedStackType::push(const int & newElement) { // ADD STACKTOP
	node * newNode = NULL;
	newNode = new node;
	newNode->num = newElement;
	newNode->link = stackTop;
	stackTop = newNode; // updates stackTop to the top of stack
}
int linkedStackType::top() const { // RETURNS VALUE OF STACKTOP
	if (!isEmptyStack())
		return stackTop->num;
}
void linkedStackType::pop() { // DELETE STACKTOP
	node * temp = NULL;
	if (stackTop != NULL) {
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
	else
		cout << "EMPTY STACK" << endl;
}
linkedStackType::linkedStackType() {
	stackTop = NULL;
}