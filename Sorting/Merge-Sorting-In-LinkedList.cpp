#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int val)
{
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    return n;
}

// Split list into two halves
Node* split(Node* head)
{
    if (!head || !head->next)
        return NULL;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = slow->next;
    slow->next = NULL;

    return second;
}

// Merge two sorted lists
Node* merge(Node* a, Node* b)
{
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data)
    {
        a->next = merge(a->next, b);
        return a;
    }
    else
    {
        b->next = merge(a, b->next);
        return b;
    }
}

// Merge Sort
Node* mergeSort(Node* head)
{
    if (!head || !head->next)
        return head;

    Node* second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}

// Print list
void print(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = newNode(5);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(6);
    head->next->next->next->next = newNode(7);
    head->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->next = newNode(1);
    head->next->next->next->next->next->next->next = newNode(8);

    head = mergeSort(head);

    print(head);
}
