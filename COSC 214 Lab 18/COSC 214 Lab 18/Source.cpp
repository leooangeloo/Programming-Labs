//LEO GENOTA
//COSC 214 - DR. STONE
//LAB 18 - INTERNAL NODES COUNT
#include<iostream>
#include<string>

using namespace std;
#include"binaryTree.h"

int main()
{
	binaryTreeType tree;
	int num;
	int i;

	for (i = 0; i<10; i++)
	{
		cout << "Enter a #: ";
		cin >> num;
		tree.insert(num);
	}
	cout << endl;

	tree.intNodeCt();

	system("PAUSE");
	return 0;
}
