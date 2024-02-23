#include "sort.h"


/**
 * swap_inver - Swap a node in a listint_t doubly-linked
 *                    head of integers with the node behind it.
 * @head: A pointer to the head of a doubly-linked head of integers.
 * @tail: A pointer to the tail of the doubly-linked head.
 * @shak: A pointer to the current swapping node of the cocktail shak algo.
 */
void swap_inver(listint_t **head, listint_t **tail, listint_t **shak)
{
	listint_t *tmp = (*shak)->prev;

	if ((*shak)->next != NULL)
		(*shak)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shak)->next;
	(*shak)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shak;
	else
		*head = *shak;
	(*shak)->next = tmp;
	tmp->prev = *shak;
	*shak = tmp;
}

/**
 * swap_forward - Swap node in a listint_t doubly-linked head
 * @head: A pointer to the head of a doubly-linked head of integers.
 * @tail: A pointer to the tail of the doubly-linked head.
 * @shak: A pointer to the current swapping node of the cocktail shak algo.
 */
void swap_forward(listint_t **head, listint_t **tail, listint_t **shak)
{
	listint_t *tmp = (*shak)->next;

	if ((*shak)->prev != NULL)
		(*shak)->prev->next = tmp;
	else
		*head = tmp;
	tmp->prev = (*shak)->prev;
	(*shak)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shak;
	else
		*tail = *shak;
	(*shak)->prev = tmp;
	tmp->next = *shak;
	*shak = tmp;
}


/**
 * cocktail_sort_list - Sort a listint_t doubly-linked head of integers in
 *                      ascending order using the cocktail shak algorithm.
 * @head: A pointer to the head of a listint_t doubly-linked head.
 */
void cocktail_sort_list(listint_t **head)
{
	listint_t *tail, *shak;
	bool shaken_not_stirred = false;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	for (tail = *head; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shak = *head; shak != tail; shak = shak->next)
		{
			if (shak->n > shak->next->n)
			{
				swap_forward(head, &tail, &shak);
				print_list((const listint_t *)*head);
				shaken_not_stirred = false;
			}
		}
		for (shak = shak->prev; shak != *head;
				shak = shak->prev)
		{
			if (shak->n < shak->prev->n)
			{
				swap_inver(head, &tail, &shak);
				print_list((const listint_t *)*head);
				shaken_not_stirred = false;
			}
		}
	}
}
