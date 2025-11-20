#include <iostream>
using namespace std;

struct BST
{
	int data;
	BST* left;
	BST* right;

	BST()
	{
		data = 0;
		left = right = nullptr;
	}

	BST* insert(BST* root, int data)
	{
		if (!root)
		{
			BST* t = new BST;
			t->data = data;
			root = t;
		}

		if (data < root->data)
		{
			root->left = insert(root->left, data);
		}

		if (data > root->data)
		{
			root->right = insert(root->right, data);
		}

		return root;
	}

	void inOrder(BST* root)
	{
		if (!root)
		{
			return;
		}

		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}

	void preOrder(BST* root)
	{
		if (!root)
		{
			return;
		}

		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}

	void postOrder(BST* root)
	{
		if (!root)
		{
			return;
		}

		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}

	void search(BST* root, int data)
	{
		if (!root)
		{
			cout << "Value not Found" << endl;
			return;
		}

		if (data == root->data)
		{
			cout << "Found: " << root->data << endl;
			return;
		}
		else if (data < root->data)
		{
			search(root->left, data);
		}
		else
		{
			search(root->right, data);
		}
	}

	int LowestValue(BST* root)
	{
		if (!root)
		{
			cout << "Tree is Empty" << endl;
			return -1;
		}

		BST* current = root;

		while (current->left)
		{
			current = current->left;
		}

		return current->data;
	}

	int GreatestValue(BST* root)
	{
		if (!root)
		{
			cout << "Tree is Empty" << endl;
			return -1;
		}

		BST* current = root;

		while (current->right)
		{
			current = current->right;
		}

		return current->data;
	}

};

int main()
{
	BST* rootT1 = nullptr;
	BST t1;

	rootT1 = t1.insert(rootT1, 10);

	t1.insert(rootT1, 8);
	t1.insert(rootT1, 6);
	t1.insert(rootT1, 4);
	t1.insert(rootT1, 2);

	t1.insert(rootT1, 12);
	t1.insert(rootT1, 14);
	t1.insert(rootT1, 16);
	t1.insert(rootT1, 18);

	t1.insert(rootT1, 9);
	t1.insert(rootT1, 7);
	t1.insert(rootT1, 5);
	t1.insert(rootT1, 3);

	t1.insert(rootT1, 9);
	t1.insert(rootT1, 7);
	t1.insert(rootT1, 5);
	t1.insert(rootT1, 3);

	t1.insert(rootT1, 11);
	t1.insert(rootT1, 13);
	t1.insert(rootT1, 15);
	t1.insert(rootT1, 17);


	cout <<   "PreOrder  : " << endl;
	t1.preOrder(rootT1);

	cout << "\nPostOrder : " << endl;
	t1.postOrder(rootT1);

	cout << "\ninOrder   : " << endl;
	t1.inOrder(rootT1);

	cout << endl << endl;

	t1.search(rootT1, 10);
	t1.search(rootT1, 15);
	t1.search(rootT1, 99);

	cout << endl << endl;

	cout << "Greatest Value is : " << t1.GreatestValue(rootT1) << endl;
	cout << "Lowest Value is   : " << t1.LowestValue(rootT1)   << endl;


	return 0;
}
