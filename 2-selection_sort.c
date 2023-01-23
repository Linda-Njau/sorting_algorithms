#include "sort.h"
/**
 * selection_sort - sorts array of integers
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int min;
	size_t i, j, position;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		position = i;

		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				position = j;
				min = array[j];
			}
		}
		if (position != i)
		{
			array[position] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
