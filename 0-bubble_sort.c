#include "sort.h"

/**
 * bubble_sort - sort array of ints in ascending order
 * @array: holder for ints
 * @size: total size being sorted
 * Return: Sorted Output
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int first, second, help;

	if (size < 2)
	{
		return;
	}

	for (first = 0; first < size - 1; first++)
	{
		for (second = 0; second < size - first - 1; second++)
		{
			if (array[second] > array[second + 1])
			{
				help = array[second];
				array[second] = array[second + 1];
				array[second + 1] = help;
				print_array(array, size);
			}
		}
	}
}
