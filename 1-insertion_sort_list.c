#include "sort.h"

/**
 * swap_sort - function to swap nodes in a doubly linked list
 * @hd: pointer to head node of the list
 * @fn: pointer to first node
 * @sn: pointer to second node
 * Return: Null
 */
void swap_sort(listint_t **h, listint_t **fn, listint_t *sn)
{
	(*fn)->next = sn->next;
	if (sn->next != NULL)
		sn->next->prev = *fn;
	sn->prev = (*fn)->prev;
	sn->next = *fn;
	if ((*fn)->prev != NULL)
		(*fn)->prev->next = sn;
	else
		*h = sn;
	(*fn)->prev = sn;
	*fn = sn->prev;
}


/**
 * insertion_sort_list - Function to sort a doubly linked list of
 * ints in ascending order using Insertion sort algorithm
 * @list: pointer to the list to be printed
 * Return: Null
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *idx;
	listint_t *tmp;

	if (*list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = tmp)
	{
		tmp = curr->next;
		idx = curr->prev;
		while (idx != NULL && curr->n < idx->n)
		{
			swap_sort(list, &idx, curr);
			print_list((const listint_t *)*list);
		}
	}
}
