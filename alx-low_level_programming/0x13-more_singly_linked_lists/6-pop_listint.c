#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to the first element in the linked list
 *
 * Return: the data inside the element that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	if (!head || !*head)
		return (0);

	listint_t *temp = *head; /* Store the head node in a temporary pointer */
	int num = temp->n; /* Get the data from the head node */

	*head = temp->next; /* Move the head to the next node */
	free(temp); /* Free the original head node */

	return (num);
}

