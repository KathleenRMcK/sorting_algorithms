#include "sort.h"

/**
 * quick_sort - sorts ints in ascending order
 * @array: int holder
 * @size: holder size
 * Return: Sorted Output
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	q_s_help(array, size, 0, size - 1);
}

/**
 * q_s_help - helper for quick_sort
 * @array: int holder
 * @size: holder size
 * @start: idx start
 * @end: idx end
 * Return: Sorted Output
 */
void q_s_help(int *array, size_t size, size_t start, size_t end)
{
	if (start < end)
	{
		size_t lomuto = quick_lomuto(array, size, start, end);

		if (lomuto > start + 1)
			q_s_help(array, size, start, lomuto - 1);
		if (lomuto < end - 1)
			q_s_help(array, size, lomuto + 1, end);
	}
}

/**
 * swap_help - help that swap plz
 * @first: first int
 * @second: second int
 * @array: int holder
 * @size: holder size
 * Return: Sorted Output
 */
void swap_help(int *first, int *second, int *array, size_t size)
{
	int help = *first;

	if (first != second)
	{
		*first = *second;
		*second = help;
		print_array(array, size);
	}
}

/**
 * quick_lomuto - partition using Lomuto method
 * @array: int holder
 * @size: holder size
 * @start: idx start
 * @end: idx end
 * Return: Sorted Output
 */
size_t quick_lomuto(int *array, size_t size, size_t start, size_t end)
{
	int lom_help = array[end];
	size_t help_1 = start, help_2;

	for (help_2 = start; help_2 < end; help_2++)
		if (array[help_2] <= lom_help)
		{
			swap_help(&array[help_1], &array[help_2], array, size);
			help_1++;
		}
	swap_help(&array[help_1], &array[end], array, size);
	return (help_1);
}
