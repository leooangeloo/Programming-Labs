//LEO GENOTA
//COSC 214 - DR. STONE
//LAB 19 - DELETING NODE 
#include<iostream>
#include<string>

using namespace std;
#include"binaryTree.h"

int main()
{
	binaryTreeType tree;
	int num, del;
	int i;

	for (i = 0; i<10; i++)
	{
		cout << "Enter a #: ";
		cin >> num;
		tree.insert(num);
	}
	cout << endl;

	tree.inorderTrav();
	cout << endl;

	cout << "Enter the item you would like to delete: " << endl;
	cin >> del;

	cout << endl;
	tree.delNode(del);
	cout << endl;

	tree.inorderTrav();
	cout << endl;

	system("PAUSE");
	return 0;
}
