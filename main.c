#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void array_check(int arr[], int start, int end)
{
	int i;

	printf("start:%d, end:%d\t", start, end);
	printf("[ ");

	for (i = start; i <= end; i ++)
		printf("%d ", arr[i]);

	printf(" ]\n");
}

void SWAP(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int QSORT(int arr[], int start, int end)
{
	int i, j, pivot;

	array_check(arr + start, start, end);

	if (start >= end)
		return start;

	i = start + 1;
	j = end;
	pivot = arr[start];

	while (i < j)
	{
		while ((arr[i] <= pivot) && (i < j))
			i ++;

		while ((arr[j] >= pivot) && (i < j))
			j --;

		if (i < j)
		{
			SWAP(arr + i, arr + j);

			printf("i:%d, j:%d\t", i, j);
			array_check(arr, start, end);
		}
		else
			break;
	}

	SWAP(arr + start, arr + i);

	printf("i:%d, j:%d\t", i, j);
	array_check(arr, start, end);


	QSORT(arr, start, i - 1);
	QSORT(arr, i + 1, end);

	return i;
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
