#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);

void print_list(const listint_t *list);


void swap_int(int *ia, int *ib);
void bubble_sort(int *array, size_t size);


void swap_sort(listint_t **h, listint_t **fn, listint_t *sn);
void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

int tkn_arr(int *array, int fir, int sec, size_t size);
void lomunto_recsort(int *array, int fir, int sec, size_t size);
void quick_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);


void forward_swap(listint_t **hd, listint_t **tl, listint_t **cur);
void backward_swap(listint_t **hd, listint_t **tl, listint_t **cur);
void cocktail_sort_list(listint_t **list);


void counting_sort(int *array, size_t size);


#endif
