//Leo Genota
//COSC 214 
//LAB 2 and 3 Linked List
// Dr. Stone
#include<iostream>
using namespace std;

struct node {
	int num;
	node * link;
};


void insert(node*& first, node *& last, int var);
void divideAt(node*& first, node*& last, node*& first2, node*& last2, int var);
void display(node* first);

int main() {
	node * first = NULL, *last = NULL, *first2 = NULL, *last2 = NULL;

	insert(first, last, 37);
	insert(first, last, 14);
	insert(first, last, 68);
	insert(first, last, 47);
	insert(first, last, 73);
	insert(first, last, 24);
	insert(first, last, 35);
	insert(first, last, 63);
	display(first);
	divideAt(first, last, first2, last2, 47);
	display(first);
	display(first2);

	system("PAUSE");
	return 0;
}

void insert(node*& first, node *& last, int var) {
	node* newNode = NULL, *current = NULL, *trailcurrent = NULL;
	newNode = new node;
	newNode->num = var;
	newNode->link = NULL;

	bool found;

	if (first == NULL) {
		first = newNode;
		last = newNode;
	}
	else {
		current = first;
		found = false;

		while (current != NULL && !found) {
			if (current->num >= var)
				found = true;
			else {
				trailcurrent = current;
				current = current->link;
			}
		}
		if (current == first) {
			newNode->link = first;
			first = newNode;
		}
		else {
			trailcurrent->link = newNode;
			newNode->link = current;

			if (current == NULL) {
				last = newNode;
			}
		}
	}
}

void divideAt(node*& first, node*& last, node*& first2, node*& last2, int var) {
	node * current = NULL, *trailcurr = NULL;
	current = first;

	while (current->num != var) {
		trailcurr = current;
		current = current->link;
	}
	first2 = current;
	last2 = last;
	last = trailcurr;
	last->link = NULL;
}

void display(node* first) {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	node * current = NULL;
	current = first;
	while (current != NULL) {
		cout << current->num << endl;
		current = current->link;
	}
}