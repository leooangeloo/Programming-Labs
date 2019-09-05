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
	void lCount();
	void nCount();
	void insert(int& insertItem);
	binaryTreeType();//default

protected:
	binaryTreeNode *root;
	int nodeCounter = 0;

private:
	int leafCount(binaryTreeNode  * p);
	int nodeCount(binaryTreeNode * p);
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

void binaryTreeType::lCount() {
	cout << "The No. of Leaves: " << leafCount(root) << endl;
}

int binaryTreeType::leafCount(binaryTreeNode  * p) {
	if (p == NULL)
		return 0;
	else {
		if (p->llink == NULL && p->rlink == NULL)
			return 1;
		else
			return leafCount(p->llink) + leafCount(p->rlink);
	}
}

void binaryTreeType::nCount() {
	cout << "The No. of Nodes: " << nodeCount(root) << endl;
}

int binaryTreeType::nodeCount(binaryTreeNode * p) {
	if (p == NULL) {
		return 0;
	}
	else
		return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
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
