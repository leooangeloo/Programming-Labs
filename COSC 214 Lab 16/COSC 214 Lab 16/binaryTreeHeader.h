struct binaryTreeNode
{
	int info;
	binaryTreeNode *llink;
	binaryTreeNode *rlink;
};

class binaryTreeType
{
public:
	//const binaryTreeTypeint& operator= (const binaryTreeTypeint&);
	bool isEmpty() const;
 	void inorderTrav();
	void preorderTrav();
	void postorderTrav();
	void nodeCount(binaryTreeNode * p);
	void insert(int& insertItem);
	binaryTreeType();//default

protected:
	binaryTreeNode *root;
private:
	void inorder(binaryTreeNode *p);
	void preorder(binaryTreeNode *p);
	void postorder(binaryTreeNode *p);

};

bool binaryTreeType::isEmpty() const
{
	return(root == NULL);
}

binaryTreeType::binaryTreeType()
{
	root = NULL;

}

void binaryTreeType::inorderTrav()
{
	inorder(root);
}

void binaryTreeType::preorderTrav()
{
	preorder(root);
}

void binaryTreeType::postorderTrav()
{
	postorder(root);
}

void nodeCount(binaryTreeNode * p) {
	int counter = 0;
	if (p != NULL) {
		inorder(p->llink);
		counter++;
		inorder(p->rlink);
	}
	cout << "The Tree has " << counter << " nodes." << endl;
}

void binaryTreeType::inorder(binaryTreeNode *p)
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}//end if
}

void binaryTreeType::preorder(binaryTreeNode *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}//end if
}

void binaryTreeType::postorder(binaryTreeNode *p)
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}//end if
}

void binaryTreeType::insert(int& insertItem)
{
	binaryTreeNode *current;
	binaryTreeNode *trailCurrent = nullptr;
	binaryTreeNode *newNode;

	newNode = new binaryTreeNode;
	//assert(newNode!=NULL);
	newNode->info = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (root == NULL)
		root = newNode;
	else
	{
		current = root;

		while (current != NULL)
		{
			trailCurrent = current;

			if (current->info == insertItem)
			{
				cerr << "The insert item is already in the tree, no duplicates " << insertItem << endl;
				return;
			}
			else if (current->info>insertItem)
				current = current->llink;
			else
				current = current->rlink;
		}//end while

		if (trailCurrent->info>insertItem)
			trailCurrent->llink = newNode;
		else
			trailCurrent->rlink = newNode;
	}//end else
}//end insert
