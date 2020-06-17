#include "sort.h"
/**
 * cocktail_sort_list- sort back and forth
 * @list: list being sorted
 * Return: Sorted Output
 */
void cocktail_sort_list(listint_t **list)
{
	if (!list || !(*list) || !((*list)->next))
		return;

	shaker_help(&(*list), *list, NULL, 1);
}

/**
 * shaker_help - recursive sort for cocktail
 * @list: list being sorted
 * @curr: current position
 * @end: end of list
 * @help: sort help
 * Return: Sorted Output
 */
void shaker_help(listint_t **list, listint_t *curr, listint_t *end, int help)
{
	listint_t *next_help = NULL;
	listint_t *temp = NULL;
	int holder = 0;

	if (help == 1)
	{
		do {
			if (curr->n > curr->next->n)
			{
				temp = curr->next;
				node_help(&(*list), &curr, &temp, &holder);
			}
			else
				curr = curr->next;
		} while (curr->next != end);
		if (holder)
			shaker_help(&(*list), curr->prev, next_help, -1);
	}
	else
	{
		while (curr->prev != end)
		{
			if (curr->n < curr->prev->n)
			{
				temp = curr->prev;
				node_help(&(*list), &temp, &curr, &holder);
			}
			else
				curr = curr->prev;
		}
		if (holder)
			shaker_help(&(*list), curr->next, next_help, 1);
	}
}

/**
 * node_help - swaps nodes
 * @list: list being sorted
 * @right: node moves right
 * @left: node moves left
 * @a: helper
 * Return: Sorted Output
 */
void node_help(listint_t **list, listint_t **right, listint_t **left, int *a)
{
	(*right)->next = (*left)->next;
	(*left)->prev = (*right)->prev;

	if ((*left)->next)
		(*left)->next->prev = (*right);
	if ((*right)->prev)
		(*right)->prev->next = (*left);
	(*left)->next = (*right);
	(*right)->prev = (*left);
	if (*right == *list)
		*list = *left;

	print_list(*list);
	*a = 1;
}
