//LEO GENOTA
//COSC 214 - DR. STONE
//LAB 11 - STACKS
#include<iostream>
using namespace std;
#include "linkedStack.h"

void displayFIFO(linkedStackType & stack, linkedStackType & stack2);

int main() {
	linkedStackType stack;
	linkedStackType stack2;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	// since stacks are FILO, we use this to diplay the stack FIFO style
	displayFIFO(stack, stack2); 
	system("PAUSE");
	return 0;
}
void displayFIFO(linkedStackType & stack, linkedStackType & stack2) {
	while (!stack.isEmptyStack()) {
		stack2.push(stack.top());
		stack.pop();
	}
	while (!stack2.isEmptyStack()) {
		stack.push(stack2.top());
		cout << stack2.top() << " ";
		stack2.pop();
	}
	cout << endl;
} 