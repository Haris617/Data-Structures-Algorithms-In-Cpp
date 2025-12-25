#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
	int temp[100];   // temporary array
	int index = 0;

	int i = start;
	int j = mid + 1;

	// merge both halves into temp[]
	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
		{
			temp[index] = arr[i];
			i++;
			index++;
		}
		else
		{
			temp[index] = arr[j];
			j++;
			index++;
		}
	}

	// copy remaining elements from left half
	while (i <= mid)
	{
		temp[index] = arr[i];
		i++;
		index++;
	}

	// copy remaining elements from right half
	while (j <= end)
	{
		temp[index] = arr[j];
		j++;
		index++;
	}

	// copy merged elements back into original array
	for (int k = 0; k < index; k++)
	{
		arr[start + k] = temp[k];
	}
}



void mergeSort(int arr[], int start, int end)
{
	if (start < end)
	{
		// Find mid
		int mid = (start + end)/2;

		// left side
		mergeSort(arr, start, mid);

		// right side
		mergeSort(arr, mid + 1, end);

		merge(arr, start, mid, end);
	}
}


int main()
{
	int arr[8] = { 5,4,3,6,7,2,1,8 };

	mergeSort(arr, 0, 7);

	// print sorted array
	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";

	return 0;
}
