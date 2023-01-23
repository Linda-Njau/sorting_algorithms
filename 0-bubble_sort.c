#include "sort.h"
/**
 * bubble_sort - function that sorts array of integers
 *
 *@array: array to be sorted
 * @size: size of array
 *Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t len = size;
	int tmp;
	int swapped = 0;

	if (size < 2 || array == NULL)
		return;
	while (swapped == 0)
	{
		swapped = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				swapped = 0;
			}

		}
		len--;
	}
}

