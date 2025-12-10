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

    node(int data)
    {
        this->data = data;
        left = right = nullptr; // keep style consistent
    }
};

struct BST
{
    node* root;

    BST()
    {
        root = nullptr;
    }

    node* insert(node* root, int data)
    {
        if(!root)
        {
            node* n = new node;
            n->data = data;
            root = n;
            return root;
        }

        if(data > root->data)
        {
            root->right = insert(root->right, data);
        }

        else if(data < root->data)
        {
            root->left = insert(root->left, data);
        }

        return root;
    }

    void insert(int data)
    {
        root = insert(root, data);
    }

    void display(node* root)
    {
        if(!root) return;

        cout << root->data << " ";

        display(root->left);
        display(root->right);
    }

    node* deleteNode(node* root, int data)
    {
        if(!root)
        {
            return nullptr;
        }

        if(data > root->data)
        {
            root->right = deleteNode(root->right, data);
        }

        else if(data < root->data)
        {
            root->left = deleteNode(root->left, data);
        }
        
        else
        {
            // no child
            if(!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }

            // no left child
            else if(!root->left)
            {
                node* temp = root->right;
                delete root;
                return temp;
            }

            // no right child
            else if(!root->right)
            {
                node* temp = root->left;
                delete root;
                return temp;
            }

            // both children
            else
            {
                node* temp = root->right;
                while(temp->left) temp = temp->left; // inorder successor
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data); // assign back
            }
        }

        return root;
    }
};

int main()
{
    BST t1;

    t1.insert(10);
    t1.insert(20);
    t1.insert(30);
    t1.insert(-20);
    t1.insert(-30);

    cout << "Original BST: ";
    t1.display(t1.root);
    cout << endl;

    t1.root = t1.deleteNode(t1.root, 10); // update root
    cout << "After deleting 10: ";
    t1.display(t1.root);
    cout << endl;

    t1.root = t1.deleteNode(t1.root, 20);
    cout << "After deleting 20: ";
    t1.display(t1.root);
    cout << endl;

    t1.root = t1.deleteNode(t1.root, -30);
    cout << "After deleting -30: ";
    t1.display(t1.root);
    cout << endl;

    return 0;
}
