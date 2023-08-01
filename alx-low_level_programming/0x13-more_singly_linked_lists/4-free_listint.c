#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: listint_t list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *temp; /* Create a temporary pointer to traverse the list */

	while (head)
	{
		temp = head->next; /* Store the next node in the temporary pointer */
		free(head); /* Free the current node */
		head = temp; /* Move the head to the next node (temp) */
	}
}

