#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void array_check(int arr[], int start, int end)
{
	int i;

	printf("start:%d, end:%d\t\t\t", start, end);

	if(end >= start)
	{
		printf("[ ");

		for (i = start; i <= end; i ++)
			printf("%d ", arr[i]);

		printf(" ]\n");
	}
	else
	{
		printf("INVALID INPUT !!\n");
	}
}

void SWAP(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int PivotIndex(int arr[], int start, int end)
{
	int i, j, pivot, pivot_idx = start;

	printf("\n[PivotIndex_init]\n");
	array_check(arr, start, end);

	if (end - start == 1)
	{
		if (arr[start] > arr[end])
			SWAP(arr + start, arr + end);

		return start;
	}
	else if (start >= end)
	{
		return end;
	}

	pivot = arr[start];
	i = start + 1;
	j = end;

	while (i < j)
	{
		while ((arr[i] <= pivot) && (i != j))	i++;
		while ((arr[j] >= pivot) && (j != i))	j--;

		//printf("[while_finished] i:%d, j:%d\n", i, j);

		if (i < j)
		{
			SWAP(arr + i, arr + j);

			printf("[CASE i<j, after SWAP] i:%d, j:%d\n", i, j);
			array_check(arr, start, end);

			i ++;
			j --;
		}
		else
		{
			pivot_idx = i;
			printf("[CASE i==j] i:%d, j:%d, pivot_idx=%d\n", i, j, pivot_idx);
			break;
		}
	}

	return pivot_idx;
}

void QSORT(int arr[], int start, int end)
{
	int pivot_idx = PivotIndex(arr, start, end);

	if(pivot_idx > start)
	{
		SWAP(arr + start, arr + pivot_idx);

		printf("[QSORT][AfterSWAP] pivot_idx:%d\n", pivot_idx);
		array_check(arr, start, end);

		QSORT(arr, start, pivot_idx - 1);
		QSORT(arr, pivot_idx + 1, end);
	}

	return;
}


int main(int argc, char **argv)
{
	int array[7] = {5, 7, 1, 3, 4, 2, 6};

	printf ("BEFORE \n");
	array_check(array, 0, 6);

	QSORT(array, 0, 6);

	printf ("\nAFTER \n");
	array_check(array, 0, 6);	

	return 0;
}

/*
annie@ubuntu:/home/share/code/250930_QSORT$ ./a.out
BEFORE
start:0, end:6                  [ 5 7 1 3 4 2 6  ]

[PivotIndex_init]
start:0, end:6                  [ 5 7 1 3 4 2 6  ]
[CASE i<j, after SWAP] i:1, j:5
start:0, end:6                  [ 5 2 1 3 4 7 6  ]
[CASE i==j] i:4, j:4, pivot_idx=4
[QSORT][AfterSWAP] pivot_idx:4
start:0, end:6                  [ 4 2 1 3 5 7 6  ]

[PivotIndex_init]
start:0, end:3                  [ 4 2 1 3  ]
[CASE i==j] i:3, j:3, pivot_idx=3
[QSORT][AfterSWAP] pivot_idx:3
start:0, end:3                  [ 3 2 1 4  ]

[PivotIndex_init]
start:0, end:2                  [ 3 2 1  ]
[CASE i==j] i:2, j:2, pivot_idx=2
[QSORT][AfterSWAP] pivot_idx:2
start:0, end:2                  [ 1 2 3  ]

[PivotIndex_init]
start:0, end:1                  [ 1 2  ]

[PivotIndex_init]
start:3, end:2                  INVALID INPUT !!

[PivotIndex_init]
start:4, end:3                  INVALID INPUT !!

[PivotIndex_init]
start:5, end:6                  [ 7 6  ]

AFTER
start:0, end:6                  [ 1 2 3 4 5 6 7  ]

*/

