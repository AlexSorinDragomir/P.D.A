#include <iostream>
#include<time.h>
using namespace std;

void oddEvenSort(int arr[], int n)
{
	bool isSorted = false;

	while (!isSorted)
	{
		isSorted = true;

		for (int i = 1; i <= n - 2; i = i + 2)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}

		for (int i = 0; i <= n - 2; i = i + 2)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
	}

	return;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	srand(time(NULL));
	clock_t begin = clock();

	int arr[201];
	for (int i = 0; i < 200; i++) {
		arr[i] = rand() % 500;
	}


	int n = 200;

	oddEvenSort(arr, n);
	printf("Time taken: %.4fs\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
	printArray(arr, n);

	system("pause");
	return (0);
}
