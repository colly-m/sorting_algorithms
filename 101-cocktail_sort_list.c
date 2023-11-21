#include "sort.h"
#include <stdbool.h>

/**
 * forward_swap - function to swap a node in a doublylinked list of integers
 * with the node ahead of it
 * @hd: pointer to the head of the list
 * @tl: pointer to the tail of the list
 * @cur: pointer to the current node in the algorithm
 * Return: NUll
 */
void forward_swap(listint_t **hd, listint_t **tl, listint_t **cur)
{
	listint_t *tmp = (*cur)->next;

	if ((*cur)->prev != NULL)
		(*cur)->prev->next = tmp;
	else
		*hd = tmp;
	tmp->prev = (*cur)->prev;
	(*cur)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *cur;
	else
		*tl = *cur;
	(*cur)->prev = tmp;
	tmp->next = *cur;
	*cur = tmp;
}

/**
 * backward_swap - Function to swap a node in a doublylinked list of integers
 * with thw node behind it
 * @hd:: pointer to the head of the list
 * @tl: pointer to the tail of the list
 * @cur: pointer to the current node in the algorithm
 * Return: NUll
 */
void backward_swap(listint_t **hd, listint_t **tl, listint_t **cur)
{
	listint_t *tmp = (*cur)->prev;

	if ((*cur)->next != NULL)
		(*cur)->next->prev = tmp;
	else
		*tl = tmp;
	tmp->next = (*cur)->next;
	(*cur)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *cur;
	else
		*hd = *cur;
	(*cur)->next = tmp;
	tmp->prev = *cur;
	*cur = tmp;
}

/**
 * cocktail_sort_list - Function to sort a doubly linked list of integers in
 * ascending order using cocktail shaker algorithm
 * @list: pointer to the head of the list
 * Return: Null
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tl, *cur;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tl = *list; tl->next != NULL;)
		tl = tl->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (cur = *list; cur != tl; cur = cur->next)
		{
			if (cur->n > cur->next->n)
			{
				forward_swap(list, &tl, &cur);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (cur = cur->prev; cur != *list; cur = cur->prev)
		{
			if (cur->n < cur->prev->n)
			{
				backward_swap(list, &tl, &cur);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
