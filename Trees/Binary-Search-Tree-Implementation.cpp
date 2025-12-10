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
        left = right = nullptr;
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
            node* n = new node(data);
            return n;
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
        if(!root) return nullptr;

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

    // Traversals
    void inOrder(node* root)
    {
        if(!root) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void preOrder(node* root)
    {
        if(!root) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(node* root)
    {
        if(!root) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    // Search
    void search(node* root, int data)
    {
        if(!root)
        {
            cout << "Value not Found" << endl;
            return;
        }

        if(data == root->data)
        {
            cout << "Found: " << root->data << endl;
        }

        else if(data < root->data)
        {
            search(root->left, data);
        }
        
        else
        {
            search(root->right, data);
        }
    }

    // Lowest value
    int LowestValue(node* root)
    {
        if(!root)
        {
            cout << "Tree is empty" << endl;
            return -1;
        }

        node* current = root;
        while(current->left) current = current->left;
        return current->data;
    }

    // Greatest value
    int GreatestValue(node* root)
    {
        if(!root)
        {
            cout << "Tree is empty" << endl;
            return -1;
        }

        node* current = root;
        while(current->right) current = current->right;
        return current->data;
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

    cout << "Original BST (PreOrder): ";
    t1.display(t1.root);
    cout << endl;

    t1.root = t1.deleteNode(t1.root, 10);
    cout << "After deleting 10: ";
    t1.display(t1.root);
    cout << endl;

    cout << "InOrder traversal: ";
    t1.inOrder(t1.root);
    cout << endl;

    cout << "PostOrder traversal: ";
    t1.postOrder(t1.root);
    cout << endl;

    t1.search(t1.root, 20);
    t1.search(t1.root, 100);

    cout << "Lowest Value: " << t1.LowestValue(t1.root) << endl;
    cout << "Greatest Value: " << t1.GreatestValue(t1.root) << endl;

    return 0;
}
