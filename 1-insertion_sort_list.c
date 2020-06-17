#include "sort.h"
/**
 * insertion_sort_list - sort doub linked list of ints in ascending
 * @list: list being sorted
 * Return: Sorted List
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *here, *there, *help;

	if (!list || *list == NULL)
		return;

	here = *list;
	if (here->next == NULL)
		return;

	while (here->next != NULL)
	{
		there = here->next;
		if (here->n > there->n)
		{
			help = here;
			while (help != NULL && help->n > there->n)
			{
				help->next = there->next;
				if (help->next != NULL)
					help->next->prev = help;
				there->prev = help->prev;
				if (there->prev != NULL)
					there->prev->next = there;
				else
					*list = there;
				help->prev = there;
				there->next = help;
				print_list(*list);
				help = there->prev;
			}
			continue;
		}
		here = here->next;
	}
}
