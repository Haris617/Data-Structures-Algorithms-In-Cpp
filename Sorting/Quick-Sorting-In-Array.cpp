#include <iostream>
using namespace std;


void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int start, int end)
{
	int i = start - 1;
	int pivot = arr[end];

	for (int j = start; j < end; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	i++;
	swap(arr[i], arr[end]);
	return i;
}

void QuickSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int partitionIndex = partition(arr, start, end);

		QuickSort(arr, start, partitionIndex - 1);
		QuickSort(arr, partitionIndex+1, end);
	}
}


int main()
{
	int arr[] = { 6,8,4,3,2,10,5,1,5 };

	QuickSort(arr, 0, 8);

	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
