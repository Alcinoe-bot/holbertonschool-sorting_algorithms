#include "sort.h"
/**
 * repartition - distribute elements of the table to the left or to the right
 * @array: array
 * @start: start of array;
 * @end: end of array
 * @size: size of array
 * Return: position of pivot
 */
int repartition(int *array, int start, int end, int size)
{
int pivot = array[end];
int i = start, j, tmp;

for (j = start; j < end; j++)
{
	if (array[j] <= pivot)
	{
		if (i < j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
if (i < end)
{
	tmp = array[i];
	array[i] = array[end];
	array[end] = tmp;
	print_array(array, size);
}
return (i);
}
/**
 * recursive - quick sorts with recursion
 * @array: array
 * @start: start of array
 * @end: end of array
 * @size: size of array
 */
void recursive(int *array, int start, int end, int size)
{
	int pivot;

	if (start < end)
	{
		pivot = repartition(array, start, end, size);
		recursive(array, start, pivot - 1, size);
		recursive(array, pivot + 1, end, size);
	}
}
/**
 * quick_sort - quick sorts an array
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive(array, 0, size - 1, size);
}
