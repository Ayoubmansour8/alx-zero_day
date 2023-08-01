#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *current; /* Create a pointer to traverse the list */
	listint_t *next_node; /* Create a pointer to store the next node */

	if (head == NULL)
		return; /* Return if the head is already NULL or invalid */

	current = *head; /* Start from the head of the list */

	while (current)
	{
		next_node = current->next; /* Store the next node in the temporary pointer */
		free(current); /* Free the current node */
		current = next_node; /* Move to the next node */
	}

	*head = NULL; /* Set the head pointer to NULL after freeing the entire list */
}

