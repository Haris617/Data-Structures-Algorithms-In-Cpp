#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
	int i = start - 1;
	int pivot = arr[end];

	for (int j = start; j < end; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	i++;
	swap(arr[i], arr[end]);

	return i; //index of Pivot
}

void swap(int &a, int &b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int arr[] = { 5,4,6,3,7,2,1 };

	return 0;
}
