#include<iostream>
#include<stdlib.h>
#include<time.h>

#define MATRIX_SIZE 100

using namespace std;

int main()
{
	int matrix1[MATRIX_SIZE][MATRIX_SIZE], matrix2[MATRIX_SIZE][MATRIX_SIZE], result[MATRIX_SIZE][MATRIX_SIZE];
	int rowIndex, columnIndex;
	volatile int flag = 0;

	srand(time(NULL));

	for (rowIndex = 0; rowIndex < MATRIX_SIZE; rowIndex++) {
		for (columnIndex = 0; columnIndex < MATRIX_SIZE; columnIndex++) {
			matrix1[rowIndex][columnIndex] = rand() % 100;
		}
	}

	for (rowIndex = 0; rowIndex < MATRIX_SIZE; rowIndex++) {
		for (columnIndex = 0; columnIndex < MATRIX_SIZE; columnIndex++) {
			matrix2[rowIndex][columnIndex] = rand() % 100;
		}
	}

	for (rowIndex = 0; rowIndex < MATRIX_SIZE; rowIndex++) {
		for (columnIndex = 0; columnIndex < MATRIX_SIZE; columnIndex++) {
			cout << matrix1[rowIndex][columnIndex] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	for (rowIndex = 0; rowIndex < MATRIX_SIZE; rowIndex++) {
		for (columnIndex = 0; columnIndex < MATRIX_SIZE; columnIndex++) {
			cout << matrix2[rowIndex][columnIndex] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	for (rowIndex = 0; rowIndex < MATRIX_SIZE; rowIndex++) {
		for (columnIndex = 0; columnIndex < MATRIX_SIZE; columnIndex++) {
			result[rowIndex][columnIndex] = 0;
		}
	}

#pragma omp parallel
	{
		cout << "Thread id: " << _threadid << endl;
		for (rowIndex = 0; rowIndex < MATRIX_SIZE; rowIndex++) {
			for (columnIndex = 0; columnIndex < MATRIX_SIZE; columnIndex++) {
				for (int k = 0; k < MATRIX_SIZE; k++) {
					result[rowIndex][columnIndex] += matrix1[rowIndex][k] * matrix2[k][columnIndex];
				}
			}
		}
	}

	for (rowIndex = 0; rowIndex < MATRIX_SIZE; rowIndex++) {
		for (columnIndex = 0; columnIndex < MATRIX_SIZE; columnIndex++) {
			cout << result[rowIndex][columnIndex] << " ";
		}
		cout << endl;
	}

	cout << "Press enter if you want to close the console";
	getchar();
	return 0;
}
