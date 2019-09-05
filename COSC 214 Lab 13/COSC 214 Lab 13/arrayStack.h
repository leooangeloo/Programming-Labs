#include<iostream>
using namespace std;

class stackType {
public:
	bool isFullStack() const;
	bool isEmptyStack() const;
	void push(const int & newItem);
	int top() const;
	void pop();
	stackType(int stackSize = 110);
private:
	int maxStackSize;
	int stackTop;
	int * list;

};

bool stackType::isFullStack() const {
	return(stackTop == maxStackSize);
}
bool stackType::isEmptyStack() const {
	return(stackTop == 0);
}
void stackType::push(const int & newItem) {
	if (!isFullStack()) {
		list[stackTop] = newItem;
		stackTop++;
	}
	else
		cout << "Cannot add to FULL list" << endl;
}
int stackType::top() const {
	if (stackTop != 0)
		return list[stackTop - 1];
}
void stackType::pop() {
	if (!isEmptyStack())
		stackTop--;
	else
		cout << "Cannot remove from EMPTY list" << endl;
}
stackType::stackType(int stackSize) {
	if (stackSize <= 0) {
		cout << "Size of the array to hold the stack must "
			<< "be positive." << endl;

		maxStackSize = 100;
	}
	else
		maxStackSize = stackSize;
	stackTop = 0;
	list = new int[maxStackSize];
}
