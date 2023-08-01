#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0; /* Initialize a variable to count the number of nodes */

	while (h)
	{
		printf("%d\n", h->n); /* Print the integer value 'n' of the current node */
		num++; /* Increment the node count */
		h = h->next; /* Move to the next node */
	}

	return (num); /* Return the total number of nodes printed */
}

