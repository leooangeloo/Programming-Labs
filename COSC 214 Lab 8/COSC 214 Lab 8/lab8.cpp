#include<iostream>
using namespace std;

#include"linkedListStack.h"

int main() {
	linkedStackType stack;
	int x = 4, y = 0;

	stack.push(7);
	stack.push(x);
	stack.push(x + 5);
	y = stack.top();
	stack.pop();
	stack.push(x + y);
	stack.push(y - 2);
	stack.push(3);
	x = stack.top();
	stack.pop();
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	while (!stack.isEmptyStack()) {
		cout << stack.top() << endl;
		stack.pop();
	}
	system("PAUSE");
	return 0;
}