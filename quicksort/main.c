#include <stdio.h>

void quicksort(int array[], int low, int high);
int split(int array[], int low, int high);
void printArray(int size, int array[]);

int main()
{
	int a[] = {2, 4, 1, 5, 3};
	int i;
	
	printf("a: ");
	printArray(5, a);
	printf("\n");
	quicksort(a, 0, sizeof(a)/sizeof(a[0]) - 1);
	printf("a: ");
	printArray(5, a);
	printf("\n");
	
	return 0;
}

void quicksort(int array[], int low, int high)
{
	int middle;
	
	if(low >= high)
	{
		return;
	}
	
	middle = split(array, low, high);
	quicksort(array, low, middle - 1);
	quicksort(array, middle + 1, high);
}

int split(int array[], int low, int high)
{
	int partitionElement = array[low];
	
	while(1)
	{
		while(low < high && partitionElement <= array[high])
		{
			high--;
		}
		
		if(low >= high)
		{
			break;
		}
		
		array[low] = array[high];
		low++;
		
		while(low < high && array[low] <= partitionElement)
		{
			low++;
		}
		
		if(low >= high)
		{
			break;
		}
			
		array[high] = array[low];
		high--;
	}
	
	array[high] = partitionElement;
	
	return high;
}

void printArray(int size, int array[])
{
	int i;

	for(i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}
