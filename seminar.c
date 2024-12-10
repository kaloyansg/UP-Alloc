#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, size_t size)
{
	printf("\n");
	for (size_t i = 0; i < size; ++i)
	{
		printf("%zu: %d\n", i, arr[i]);
	}
	printf("\n_________________________________\n\n");
}

void insertAt(int** arr, size_t* size, size_t index, int element)
{
	if (index > size)
	{
		printf("Invalid index!\n");
		return;
	}

	int* temp = (int*)realloc((*arr), (*size + 1) * sizeof(int));
	if (!temp)
	{
		printf("Insertion failed!\n");
		return;
	}

	++(*size);
	*arr = temp;

	for (size_t i = *size-1; i > index; --i)
	{
		(*arr)[i] = (*arr)[i - 1];
	}

	(*arr)[index] = element;
}

int main()
{
	size_t size = 0;
	printf("Enter array size: ");
	scanf_s("%zu", &size);
	if (size == 0)
	{
		printf("Invalid array size!\n");
		return 1;
	}

	int* arr = NULL;
	arr = (int*)malloc(size * sizeof(int)); //arr = (int*)calloc(size, sizeof(int));
	if (!arr) //if (arr == NULL)
	{
		printf("Allocation failed!\n");
		return 1;
	}
	for (size_t i = 0; i < size; ++i)
	{
		printf("Enter %zu: ", i);
		scanf_s("%d", &arr[i]);
	}
	printArray(arr, size);

	size_t newSize = 0;
	printf("Enter new array size: ");
	scanf_s("%zu", &newSize);
	if (newSize == 0)
	{
		printf("Invalid size!\n");
		free(arr);
		return 1;
	}
	
	int* temp = NULL;
	temp = (int*) realloc(arr, (newSize) * sizeof(int));
	if (!temp)
	{
		printf("Reallocation failed!\n");
		/*free(arr);
		return 1;*/
	}
	else
	{
		arr = temp;
		if (newSize > size)
		{
			for (size_t i = size; i < newSize; ++i)
			{
				printf("Enter %zu: ", i);
				scanf_s("%d", &arr[i]);
			}
		}
		size = newSize;
	}
	printArray(arr, size);

	int newEl = 0, index = 0;
	printf("Enter the new element: ");
	scanf_s("%d", &newEl);
	printf("and the index you want to be inserted: ");
	scanf_s("%d", &index);
	insertAt(&arr, &size, index, newEl);
	printArray(arr, size);

	free(arr);
	return 0;
}

//<Sample input data>:
//5 1 2 4 5 6 3 3 2

//<Sample input data>:
//5 1 2 3 5 6 9 7 8 9 10 4 3