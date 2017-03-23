// SecventialMatriXMultiplication.cpp : Defines the entry point for the console application.

#include <stdafx.h>

#include<iostream>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

using namespace std;


int main()
{
	int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], result[SIZE][SIZE];
	int i, j;

	srand(time(NULL));

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++) {
			matrix1[i][j] = rand() % 100;
		}

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++) {
			matrix2[i][j] = rand() % 100;
		}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			cout << matrix1[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "\n";

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			cout << matrix2[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "\n";

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++) {
			result[i][j] = 0;
		}

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			for (int k = 0; k < SIZE; k++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "Do you want to close the console?(y/n)";
	getchar();

	return 0;
}


