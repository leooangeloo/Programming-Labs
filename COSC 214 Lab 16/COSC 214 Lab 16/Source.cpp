#include<iostream>
#include<string> // in Bloodshed, remove this line

using namespace std;
#include"binaryTreeHeader.h"

int main()
{
	binaryTreeType tree;
	int num;
	int i;

	for (i = 0; i<7; i++)
	{
		cout << "Enter a #: ";
		cin >> num;
		tree.insert(num);
	}
	cout << endl;

	cout << "Tree nodes inorder: ";
	tree.inorderTrav();

	cout << endl;
	cout << "Tree nodes preorder: ";
	tree.preorderTrav();

	cout << endl;
	cout << "Tree nodes postorder: ";
	tree.postorderTrav();
	cout << endl;

	tree.nodeCount();

	system("PAUSE");
	return 0;
}
