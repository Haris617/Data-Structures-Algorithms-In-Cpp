#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;

	node()
	{
		data = 0;
		left = right = nullptr;
	}
};

struct tree
{
	node* root;

	tree()
	{
		root = nullptr;
	}

	node* insert(node *root, int val)
	{
		if (!root)
		{
			node* n = new node;
			n->data = val;
			root = n;
		}

		else if (val >= root->data)
		{
			root->right = insert(root->right, val);
		}

		else if (val < root->data)
		{
			root->left = insert(root->left, val);
		}

		return root;
	}

	void insert(int val)
	{
		root = insert(root, val);
	}

};



int main()
{
	tree t;

	t.insert(20);
	t.insert(10);
	t.insert(30);

	cout << t.root->data << endl;
	cout << t.root->left->data << endl;
	cout << t.root->right->data << endl;


	return 0;
}
