#include <iostream>
using namespace std;

struct node {
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
        node* n = new node(data);

        if (!root)
        {
            return n;
        }

        if (data <= root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }

        return root;
    }

    node* insert(int data) // Wrapper for Insert Function
    {
        root = insert(root, data);
        return root;
    }

    // Display
    void preorder(node* root)
    {
        if (!root)
        {
            return;
        }

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(node* root)
    {
        if (!root)
        {
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(node* root)
    {
        if (!root)
        {
            return;
        }

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    node* deleteNode(node* root, int data)
    {
        if (!root)
        {
            return nullptr;
        }

        if (data < root->data)
        {
            root->left = deleteNode(root->left, data);  
        }
        else if (data > root->data)
        {
            root->right = deleteNode(root->right, data);
        }
        else
        {
            // No Child
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }

            // No Left Child
            else if (!root->left)
            {
                node* temp = root->right;
                delete root;
                return temp;
            }

            // No Right Child
            else if (!root->right)
            {
                node* temp = root->left;
                delete root;
                return temp;
            }

            // Both Children
            else
            {
                node* temp = root->right;

                while (temp->left)  // Find InOrder Successor Node 
                {
                    temp = temp->left;
                }

                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data); // Delete Successor Node
            }
        }

        return root;
    }

    node* deleteNode(int data) // Wrapper for Delete Function
    {
        root = deleteNode(root, data);
        return root;
    }

    // Search BST
    bool search(node* root, int data)
    {
        if (!root)
        {
            return false;
        }

        if (data == root->data)
        {
            return true;
        }

        else if (data < root->data)
        {
            return search(root->left, data);
        }

        else
        {
            return search(root->right, data);
        }
    }

    bool search(int data) // Wrapper for Search Function
    {
        return search(root, data);
    }

    // Greatest Value in BST
    int greatestValue(node* root)
    {
        if (!root)  // Handle empty tree
        {
            cout << "Tree is empty! ";
            return -1;
        }

        node* temp = root;

        while (temp->right)
        {
            temp = temp->right;
        }

        return temp->data;
    }

    // Smallest Value in BST
    int smallestValue(node* root)
    {
        if (!root)  // Handle empty tree
        {
            cout << "Tree is empty! ";
            return -1;
        }

        node* temp = root;

        while (temp->left)
        {
            temp = temp->left;
        }

        return temp->data;
    }
};

int main()
{
    BST t1;

    t1.insert(1);
    t1.insert(3);
    t1.insert(5);
    t1.insert(7);
    t1.insert(9);
    t1.insert(2);
    t1.insert(4);
    t1.insert(6);
    t1.insert(9);
    t1.insert(10);

    cout << "\nInOrder : ";
    t1.inorder(t1.root);

    cout << "\nPreOrder : ";
    t1.preorder(t1.root);

    cout << "\nPostOrder : ";
    t1.postorder(t1.root);

    cout << "\nGreatestValue : " << t1.greatestValue(t1.root);

    cout << "\nSmallestValue  : " << t1.smallestValue(t1.root);

    t1.deleteNode(1);
    t1.deleteNode(3);
    t1.deleteNode(5);

    cout << "\n\nDELETING NODES 1, 3, 5" << endl;

    cout << "\nInOrder : ";
    t1.inorder(t1.root);

    cout << "\n\nSearching 9...  : ";

    if (t1.search(9))
    {
        cout << "Found" << endl;
    }

    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}
