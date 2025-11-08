#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
	int i = start;
	int pivot = arr[start];

	for (int j = start+1; j <= end; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i], arr[start]);

	return i;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort(int arr[], int start, int end)
{
	int pivotIndex = partition(arr, start, end);

	if (start < end)
	{
		QuickSort(arr, start, pivotIndex - 1);
		QuickSort(arr, pivotIndex+1, end);
	}

	return;
}

int main()
{
	int arr[10] = { 5,10,9,1,5,4,3,2,8,7 };

	QuickSort(arr, 0, 9);

	for (int i = 0; i <= 9; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
