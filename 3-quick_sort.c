#include "sort.h"

/**
 * swap_ints - swaps two integers
 * @a: first integer to swap
 * @b: second int to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 *lomuto_partition - orders array subset according to lomuto partition scheme
 *@array: array of integers
 *@size: size of array
 *@left: starting index of order
 *@right: ending index of order
 *Return: final partition index
  */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

 /**
  * lomuto_sort - implement the quicksort algorithm
  * @array: array to be sorted
  * @size: size of array
  * @left: starting index
  * @right: ending index
  * Return: nothing
  * Description: use lomuto partiton scheme
  */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sorts array of integers
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}




































