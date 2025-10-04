#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void array_check(char *title, int arr[], int start, int end)
{
	int i;

	if (title)
		printf ("%s\n", title);

	printf("start:%d, end:%d\t\t\t", start, end);

	if(end >= start)
	{
		printf("[ ");

		for (i = 0; i < start; i ++)
			printf("  ");

		for (i = start; i <= end; i ++)
			printf("%d ", arr[i]);

		printf("]\n");
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

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (1)
	{
        do {i++;}	while (arr[i] < pivot);
        do {j--;}	while (arr[j] > pivot);

        if (i >= j)
			return j;

        SWAP(arr + i, arr + j);
		array_check("SWAP", arr, i, j);
    }
}

void quicksort(int arr[], int low, int high)
{
    if (low >= high)
		return;

    int p = partition(arr, low, high);
	printf("p:%d\n", p);

    quicksort(arr, low, p);
    quicksort(arr, p + 1, high);
}

int main(int argc, char **argv)
{
	int array[] = {5,7,1,3,4,2,6};
	int n = sizeof(array) / sizeof(array[0]);

	array_check("BEFORE", array, 0, n-1);
	quicksort(array, 0, n-1);
	array_check("AFTER", array, 0, n-1);

	return 0;
}

/*
annie@ubuntu:/home/share/code/250930_QSORT$ ./a.out
BEFORE
start:0, end:6                  [ 5 7 1 3 4 2 6 ]
SWAP
start:0, end:5                  [ 2 7 1 3 4 5 ]
SWAP
start:1, end:4                  [   4 1 3 7 ]
p:3
SWAP
start:0, end:2                  [ 1 4 2 ]
p:0
SWAP
start:1, end:3                  [   3 2 4 ]
p:2
SWAP
start:1, end:2                  [   2 3 ]
p:1
SWAP
start:4, end:6                  [         6 5 7 ]
p:5
SWAP
start:4, end:5                  [         5 6 ]
p:4
AFTER
start:0, end:6                  [ 1 2 3 4 5 6 7 ]
annie@ubuntu:/home/share/code/250930_QSORT$
*/

