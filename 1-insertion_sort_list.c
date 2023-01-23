#include "sort.h"
/**
 * insertion_sort_list - sorts doubly linked list of integers
 * @list: doubly linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *new, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (node = (*list)->next; node != NULL; node = tmp)
	{
		tmp = node->next;
		new = node->prev;
		while (new != NULL && node->n < new->n)
		{
			swap_node(list, &new, node);
			print_list((const listint_t *)*list);
		}
	}
}
/**
 * swap_node - swaps nodes in a doubly linked list.
 * @h: head pointer
 * @n1: pointer to first node
 * @n2: pointer to second node
 * Return: nothing
 */

void swap_node(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
