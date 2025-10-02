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


#define TOTAL_NUMBER	119
int main_random(int argc, char **argv)
{
	int a, b, i;
	
	srand(time(NULL));

	for (i=0; i<1; i++)		/* for verifying srand function */
	{
		b = rand();
		a = (b % TOTAL_NUMBER) +1;	/* start from 1 */
		printf ("%d ", a);
		//printf ("(%d) ", b);
	}

	printf("\n");

	return 0;
}
