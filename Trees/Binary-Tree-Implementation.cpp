#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree* left;
    tree* right;

    tree()
    {
        data = 0;
        left = right = nullptr;
    }

    tree* insert(tree* root, int data)
    {
        if (!root)
        {
            tree* t = new tree;
            t->data = data;
            root = t;
        }

        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }

        else
        {
            root->left = insert(root->left, data);
        }

        return root;
    }

    void inOrder(tree* root)
    {
        if (!root)
        {
            return;
        }

        inOrder(root->left);
        cout << root->data << endl;
        inOrder(root->right);

    }

    void preOrder(tree* root)
    {
        if (!root)
        {
            return;
        }

        cout << root->data << endl;
        preOrder(root->left);
        preOrder(root->right);

    }

    void postOrder(tree* root)
    {
        if (!root)
        {
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << endl;

    }

};

int main()
{
    tree t1;
    tree* t1root = nullptr;

    t1root = t1.insert(t1root, 10);

    t1.insert(t1root, 5);
    t1.insert(t1root, 6);
    t1.insert(t1root, 2);
    t1.insert(t1root, 15);
    t1.insert(t1root, 20);
    t1.insert(t1root, 25);

    t1.insert(t1root, 14);
    t1.insert(t1root, 13);
    t1.insert(t1root, 18);

    cout << "InOrder:" << endl;
    t1.inOrder(t1root);

    cout << "\nPreOrder:" << endl;
    t1.preOrder(t1root);

    cout << "\nPostOrder:" << endl;
    t1.postOrder(t1root);

    return 0;
}
