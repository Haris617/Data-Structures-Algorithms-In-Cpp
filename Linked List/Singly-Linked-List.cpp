#include<iostream>
using namespace std;

// 1. Create Single LinkedList

struct node
{
	int data;
	node* next;

	node(int x)
	{
		data = x;
		next = nullptr;
	}
};

// 2. Insert at Head

node* insertAtHead(node* head, int data)
{
	node* n = new node(data);
	n->next = head;
	return n; // handles both cases
}


// 3. Insert at End

node* insertAtEnd(node* head, int data)
{
	node* n = new node(data);
	
	if (!head)
	{
		return n;
	}

	node* temp = head;

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = n;
	return head;
}

// 4. Delete at Head

node* deleteAtHead(node* head)
{
	if (!head)
	{
		return nullptr;
	}

	node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

// 5. Delete At End

node* deleteAtEnd(node* head)
{
	if (!head)
	{
		return nullptr;
	}

	if (!head->next)
	{
		delete head;
		return nullptr;
	}

	node* temp = head;
	while (temp->next->next)
	{
		temp = temp->next;
	}

	delete temp->next;
	temp->next = nullptr;
	return head;
}	

//6. Delete Nth Node

node* deleteNthNode(node* head, int index)
{
	if (!head)
	{
		return nullptr;
	}

	if (index < 0)
	{
		return head;
	}

	if (index == 0)
	{
		node* temp = head;
		head = head->next;
		delete temp;
		return head;
	}

	node* prev = head;

	for (int i = 0; i < index - 1; i++)
	{
		if (!prev->next)
		{
			return head;
		}

		prev = prev->next;
	}

	node* current = prev->next;

	if (!current)
	{
		return head;
	}

	prev->next = current->next;
	delete current;

	return head;
}

// 7. Find Middle Node

node* middleNode(node* head)
{
	if (!head)
	{
		return nullptr;
	}

	node* slow = head;
	node* fast = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

// 8. Detect Cycle (Floyd's Algorithm)

bool hasCycle(node* head)
{
	node* slow = head;
	node* fast = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return true;
		}
	}

	return false;
}

// 9. Merging 2 Sorted List using Recursion

node* merge2SortedListRecursion(node* head1, node* head2)
{
	if (!head1)
	{
		return head2;
	}

	if (!head2)
	{
		return head1;
	}

	node* temp = nullptr;

	if (head1->data <= head2->data)
	{
		temp = head1;
		temp->next = merge2SortedListRecursion(head1->next, head2);
	}

	else
	{
		temp = head2;
		temp->next = merge2SortedListRecursion(head1, head2->next);
	}

	return temp;
}

// 10. Merging 2 Sorted List

node* merge2SortedList(node* head1, node* head2)
{
	if (!head1)
	{
		return head2;
	}

	if (!head2)
	{
		return head1;
	}

	node* head = nullptr;
	node* current = nullptr;

	if (head1->data <= head2->data)
	{
		head = head1;
		current = head1;
		head1 = head1->next;
	}

	else
	{
		head = head2;
		current = head2;
		head2 = head2->next;
	}

	while (head1 && head2)
	{
		if (head1->data <= head2->data)
		{
			current->next = head1;
			head1 = head1->next;
		}

		else
		{
			current->next = head2;
			head2 = head2->next;
		}

		current = current->next;
	}

	if (head1)
	{
		current->next = head1;
	}

	else if (head2)
	{
		current->next = head2;
	}

	return head;
}

// 11. Display LinkedList

void display(node* head)
{
	if (!head)
	{
		return;
	}

	node* temp = head;

	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

// 12. Get Value at Specific Position

int getValueAtSpecificPos(node* head, int index)
{
	if (!head || index < 0)
	{
		return -1;
	}

	node* current = head;

	for (int i = 0; i < index; i++)
	{
		if (!current)
		{
			return -1;
		}

		current = current->next;
	}

	return current->data;

}

//13. Search

bool search(node* head, int data)
{
	if (!head)
	{
		return false;
	}
	
	node* current = head;

	while (current)
	{
		if (current->data == data)
		{
			return true;
		}

		current = current->next;
	}

	return false;
}

//14. insert at Specific Position

node* insertAtSpecificPos(node* head, int Data, int index)
{
	node* n = new node(Data);

	if (index == 0)
	{
		n->next = head;
		head = n;
		return n;
	}

	node* prev = head;

	for (int i = 0; i < index - 1; i++)
	{
		if (!prev || !prev->next)
		{
			delete n;
			return nullptr;    // Invalid index
		}

		prev = prev->next;
	}

	// Insert the new node
	n->next = prev->next;
	prev->next = n;

	return head;
}

// 15. Reverse Singly Linked list

node* reverseList(node* head)
{
	node* previous = nullptr;
	node* current = head;
	node* next = nullptr;

	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	head = previous;
	return head;
}

//16. Bubble Sort

void bubbleSort(node* head)
{
	if (!head)
	{
		cout << "List does not exist" << endl;
		return;
	}

	bool swapped;

	do
	{
		swapped = false;
		node* current = head;

		while (current->next)
		{
			if (current->data > current->next->data)
			{
				int temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;

				swapped = true;
			}

			current = current->next;
		}

	} while (swapped);
}

int main()
{
	node* head = nullptr;

	// Insert at End
	head = insertAtEnd(head, 10);
	head = insertAtEnd(head, 20);
	head = insertAtEnd(head, 30);
	head = insertAtEnd(head, 40);

	cout << "Original List: ";
	display(head);
	cout << endl;

	// Insert at Head
	head = insertAtHead(head, 5);
	cout << "After Insert at Head: ";
	display(head);
	cout << endl;

	// Insert at Specific Position
	head = insertAtSpecificPos(head, 25, 3);
	cout << "After Insert 25 at Index 3: ";
	display(head);
	cout << endl;

	// Delete at Head
	head = deleteAtHead(head);
	cout << "After Delete at Head: ";
	display(head);
	cout << endl;

	// Delete at End
	head = deleteAtEnd(head);
	cout << "After Delete at End: ";
	display(head);
	cout << endl;

	// Delete Nth Node
	head = deleteNthNode(head, 2);
	cout << "After Delete Index 2: ";
	display(head);
	cout << endl;

	// Get Value at Specific Position
	cout << "Value at Index 1: " << getValueAtSpecificPos(head, 1) << endl;

	// Search
	cout << "Search 20: ";
	if (search(head, 20))
		cout << "Found\n";
	else
		cout << "Not Found\n";

	cout << "Search 100: ";
	if (search(head, 100))
		cout << "Found\n";
	else
		cout << "Not Found\n";

	// Middle Node
	node* mid = middleNode(head);
	if (mid)
		cout << "Middle Node: " << mid->data << endl;

	// Reverse List
	head = reverseList(head);
	cout << "Reversed List: ";
	display(head);
	cout << endl;

	//Sorted List

	bubbleSort(head);
	cout << "Sorted List: ";
	display(head);
	cout << endl;

	// Cycle Detection
	cout << "Has Cycle? ";
	if (hasCycle(head))
		cout << "Yes\n";
	else
		cout << "No\n";

	// -----------------------------
	// Merge Two Sorted Lists
	// -----------------------------

	node* list1 = nullptr;
	list1 = insertAtEnd(list1, 1);
	list1 = insertAtEnd(list1, 3);
	list1 = insertAtEnd(list1, 5);

	node* list2 = nullptr;
	list2 = insertAtEnd(list2, 2);
	list2 = insertAtEnd(list2, 4);
	list2 = insertAtEnd(list2, 6);

	cout << "\nList 1: ";
	display(list1);

	cout << "\nList 2: ";
	display(list2);

	node* merged = merge2SortedList(list1, list2);

	cout << "\nMerged List (Iterative): ";
	display(merged);
	cout << endl;

	// -----------------------------
	// Merge Recursively
	// -----------------------------

	node* a = nullptr;
	a = insertAtEnd(a, 10);
	a = insertAtEnd(a, 30);
	a = insertAtEnd(a, 50);

	node* b = nullptr;
	b = insertAtEnd(b, 20);
	b = insertAtEnd(b, 40);
	b = insertAtEnd(b, 60);

	node* mergedRec = merge2SortedListRecursion(a, b);

	cout << "Merged List (Recursive): ";
	display(mergedRec);
	cout << endl;


	return 0;
}
