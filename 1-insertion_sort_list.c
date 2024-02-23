#include "sort.h"

/**
 * node_swap - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @fst_node: A pointer to the first node to swap.
 * @scd_node: The second node to swap.
 */
void node_swap(listint_t **head, listint_t **fst_node, listint_t *scd_node)
{
	(*fst_node)->next = scd_node->next;
	if (scd_node->next != NULL)
		scd_node->next->prev = *fst_node;
	scd_node->prev = (*fst_node)->prev;
	scd_node->next = *fst_node;
	if ((*fst_node)->prev != NULL)
		(*fst_node)->prev->next = scd_node;
	else
		*head = scd_node;
	(*fst_node)->prev = scd_node;
	*fst_node = scd_node->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *         using insertion sort algorithm.
 * @list: pointer to head of doubly-linked list of integers.
 * Description: Prints the list after swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *printer, *add, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (printer = (*list)->next; printer != NULL; printer = tmp)
	{
		tmp = printer->next;
		add = printer->prev;
		while (add != NULL && printer->n < add->n)
		{
			node_swap(list, &add, printer);
			print_list((const listint_t *)*list);
		}
	}
}
