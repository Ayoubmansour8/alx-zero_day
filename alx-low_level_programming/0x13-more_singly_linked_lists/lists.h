#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for alx project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/* Function to print all the elements of a linked list */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;
	const listint_t *current;

	for (current = h; current != NULL; current = current->next)
	{
		printf("%d\n", current->n);
		num++;
	}

	return num;
}

/* Function to return the number of nodes in a linked list */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;
	const listint_t *current;

	for (current = h; current != NULL; current = current->next)
		num++;

	return num;
}

/* Function to add a new node at the beginning of a linked list */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return NULL;

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return new_node;
}

/* Function to add a new node at the end of a linked list */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *last = *head;

	if (new_node == NULL)
		return NULL;

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return new_node;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;

	return new_node;
}

/* Function to free the memory allocated for a linked list */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/* Function to free the memory allocated for a linked list and set the head to NULL */
void free_listint2(listint_t **head)
{
	if (head == NULL)
		return;

	free_listint(*head);
	*head = NULL;
}

/* Function to delete the head node of a linked list and return its data */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return 0;

	temp = *head;
	data = temp->n;
	*head = (*head)->next;
	free(temp);

	return data;
}

/* Function to get the nth node of a linked list */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head != NULL)
	{
		if (count == index)
			return head;

		count++;
		head = head->next;
	}

	return NULL;
}

/* Function to return the sum of all the elements in a linked list */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return sum;
}

/* Function to insert a new node at a given position in the linked list */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp;
	unsigned int count = 0;

	if (head == NULL)
		return NULL;

	if (idx == 0)
		return add_nodeint(head, n);

	temp = *head;
	while (temp != NULL)
	{
		if (count == idx - 1)
		{
			new_node = malloc(sizeof(listint_t));
			if (new_node == NULL)
				return NULL;

			new_node->n = n;
			new_node->next = temp->next;
			temp->next = new_node;

			return new_node;
		}

		count++;
		temp = temp->next;
	}

	return NULL;
}

/* Function to delete a node at a given position in the linked list */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int count = 0;
	int data;

	if (head == NULL || *head == NULL)
		return -1;

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		data = current->n;
		free(current);
		return data;
	}

	while (current != NULL)
	{
		if (count == index - 1)
		{
			temp = current->next;
			if (temp == NULL)
				return -1;

			current->next = temp->next;
			data = temp->n;
			free(temp);
			return data;
		}

		count++;
		current = current->next;
	}

	return -1;
}

/* Function to reverse a linked list */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return *head;
}

/* Function to print a linked list safely (handles loops) */
size_t print_listint_safe(const listint_t *

