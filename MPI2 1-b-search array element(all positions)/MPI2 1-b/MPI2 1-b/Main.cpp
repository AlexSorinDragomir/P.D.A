#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 103
#define KEY 60

int main(int argc, char *argv[])
{
	int rank, size, segmentSize, index;
	int array[SIZE], segment[SIZE], found[SIZE], finalFound[SIZE + 10];
	bool ok = false;

	srand((unsigned int)time(NULL));

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	segmentSize = SIZE / size;
	if (SIZE % size != 0 /*&& rank >= 3*/)
		/*segmentSize += SIZE % size;*/
		++segmentSize;

	MPI_Barrier(MPI_COMM_WORLD);

	if (rank == 0) 
	{
		printf("Array elements are:\n");
		for (int i = 0; i < SIZE; i++) 
		{
			array[i] = rand() % 100;
			printf("%d, ", array[i]);
			finalFound[i] = -1;
		}
		array[25] = 60;
		array[67] = 60;
		array[99] = 60;
	}

	MPI_Scatter(array, segmentSize, MPI_INT, segment, segmentSize, MPI_INT, 0, MPI_COMM_WORLD);
	printf("\n\nrank: %d, segement size: %d", rank, segmentSize);

	for (int i = 0; i < segmentSize; i++)
		found[i] = 0;

	index = 0;
	for (int i = 0; i < segmentSize; i++) 
	{
		if (segment[i] == KEY) 
		{
			found[index++] = i + rank * segmentSize;
		}
	}

	MPI_Gather(found, segmentSize, MPI_INT, finalFound, segmentSize, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0) 
	{
		for (int i = 0; i < SIZE + 10; i++)
		{
			if (finalFound[i] > 0)
			{
				if (!ok)
					printf("\n\nNumber found on the follwing position(s): ");
				ok = true;
				printf("%d ", finalFound[i]);
			}
		}
		if (!ok) 
			printf("\n\nNumber not found.");
	}

	MPI_Finalize();
	return 0;
}
