#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: pointer to the first node in the list
 * @n: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	/* Allocate memory for the new node */
	listint_t *new = (listint_t *)malloc(sizeof(listint_t));

	if (new == NULL)
	{
		return (NULL); /* Return NULL if memory allocation fails */
	}

	/* Set the 'n' value of the new node to the provided data */
	new->n = n;

	/* Point the 'next' of the new node to the current head node */
	new->next = *head;

	/* Make the new node the new head of the linked list */
	*head = new;

	return (new); /* Return a pointer to the new node */
}

