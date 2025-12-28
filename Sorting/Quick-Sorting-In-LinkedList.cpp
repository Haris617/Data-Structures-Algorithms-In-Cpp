#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Swap values of two nodes
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Partition function for linked list
Node* partition(Node* start, Node* end) {
    int pivot = start->data;
    Node* i = start;
    Node* j = start->next;

    while (j != end->next) {
        if (j->data < pivot) {
            i = i->next;
            swap(i, j);
        }
        j = j->next;
    }
    swap(i, start);
    return i;
}

// QuickSort function for linked list
void QuickSort(Node* start, Node* end) {
    if (start == end || start == nullptr || end == nullptr)
        return;

    Node* pivotIndex = partition(start, end);

    // Recursively sort the left part
    if (pivotIndex != start) {
        Node* temp = start;
        while (temp->next != pivotIndex)
            temp = temp->next;
        QuickSort(start, temp);
    }

    // Recursively sort the right part
    if (pivotIndex != end)
        QuickSort(pivotIndex->next, end);
}

// Helper function to print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a new node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

int main() {
    // Creating linked list: 5->10->9->1->5->4->3->2->8->7
    Node* head = newNode(5);
    head->next = newNode(10);
    head->next->next = newNode(9);
    head->next->next->next = newNode(1);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->next = newNode(3);
    head->next->next->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->next->next->next = newNode(8);
    head->next->next->next->next->next->next->next->next->next = newNode(7);

    // Finding last node
    Node* end = head;
    while (end->next != nullptr)
        end = end->next;

    QuickSort(head, end);

    printList(head);

    return 0;
}
