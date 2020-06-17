#include "sort.h"
/**
 * selection_sort - sort an array of ints in ascending order
 * @array: int holder
 * @size: holder size
 * Return: Sorted Output
 */
void selection_sort(int *array, size_t size)
{
	unsigned int first, second, min, help;

	for (first = 0; first < size - 1; first++)
	{
		min = first;
		for (second = first + 1; second < size; second++)
		{
			if (array[second] < array[min])
			{
				min = second;
			}
		}
		if (min != first)
		{
			help = array[min];
			array[min] = array[first];
			array[first] = help;
			print_array(array, size);
		}
	}
}
