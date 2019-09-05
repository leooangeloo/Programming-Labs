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
	void intNodeCt();
	void insert(int& insertItem);
	void delNode(const int& delItem);
	binaryTreeType();//default

protected:
	binaryTreeNode *root;
	int nodeCounter = 0;

private:
	int leafCount(binaryTreeNode  * p);
	int nodeCount(binaryTreeNode * p);
	int internalCt(binaryTreeNode * p);
	void inorder(binaryTreeNode *p);
	void preorder(binaryTreeNode *p);
	void postorder(binaryTreeNode *p);
	void deleteFromTree(binaryTreeNode *& p);

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

void binaryTreeType::intNodeCt() {
	cout << "The No. of Internal Nodes: " << internalCt(root) << endl;
}

int binaryTreeType::internalCt(binaryTreeNode * p) {
	if (p == NULL)
		return 0;
	else if ((p->llink == NULL) && (p->rlink == NULL))
		return 0;
	else
		return 1 + (internalCt(p->llink) + internalCt(p->rlink));
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

void binaryTreeType::delNode(const int& delItem) {
	binaryTreeNode * current = NULL, *tc = NULL;
	bool found = false;

	if (root == NULL)
		cout << "Cannot delete from empty tree." << endl;
	else {
		current = root;
		tc = root;

		while (current != NULL && !found) {
			if (current->info == delItem)
				found = true;
			else {
				tc = current;

				if (current->info > delItem)
					current = current->llink;
				else
					current = current->rlink;
			}// end ELSE
		}// end WHILE
		
		if (current == NULL)
			cout << "The delete item is not int the tree." << endl;
		else if (found) {
			if (current == root)
				deleteFromTree(root);
			else if (tc->info > delItem)
				deleteFromTree(tc->llink);
			else
				deleteFromTree(tc->rlink);
		}
	}
}

void binaryTreeType::deleteFromTree(binaryTreeNode *& p) {
	binaryTreeNode * curr = NULL, *tc, *temp = NULL;

	if (p == NULL)
		cerr << "Error: The node to be deleted is NULL" << endl;
	else if (p->llink == NULL && p->rlink == NULL) {
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->llink == NULL) {
		temp = p;
		p = temp->rlink;
		delete temp;
	}
	else if (p->rlink = NULL) {
		temp = p;
		p = temp->llink;
		delete temp;
	}
	else {
		curr = p->llink;
		tc = NULL;

		while (curr->rlink != NULL) {
			tc = curr;
			curr = curr->rlink;
		}

		p->info = curr->info;

		if (tc = NULL)
			p->llink = curr->llink;
		else
			tc->rlink = curr->llink;

		delete curr;
	}
}
