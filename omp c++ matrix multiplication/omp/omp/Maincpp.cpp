#include<iostream>
#include<stdlib.h>
#include<time.h>

#define MATRIX_SIZE 10

using namespace std;

int main()
{
	int matrix1[MATRIX_SIZE][MATRIX_SIZE], matrix2[MATRIX_SIZE][MATRIX_SIZE], result[MATRIX_SIZE][MATRIX_SIZE];
	int rowIndex, columnIndex;

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

	#pragma omp parallel for 
	for (int i = 0; i < MATRIX_SIZE; i++) {
		#pragma omp critical
		cout << "Row index: " << i << "		Thread id: " << _threadid << endl;
	#pragma omp parallel
		{
			for (int j = 0; j < MATRIX_SIZE; j++) {
				for (int k = 0; k < MATRIX_SIZE; k++) {
					result[i][j] += matrix1[i][k] * matrix2[k][j];
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
