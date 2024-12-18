#include "lists.h"

/**
 * reverse_listint - Reverses a singly linked list.
 * @head: Pointer to a pointer to the head of the list.
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Pointer to a pointer to the head of the list.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	listint_t *middlePointer = *head;
	listint_t *runnerPointer = *head;
	listint_t *temp = *head;
	listint_t *second_half;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	while (runnerPointer != NULL && runnerPointer->next != NULL)
	{
		runnerPointer = runnerPointer->next->next;
		middlePointer = middlePointer->next;
	}

	second_half = reverse_listint(&middlePointer);

	while (temp != NULL && second_half != NULL)
	{
		if (temp->n != second_half->n)
			return (0);
		temp = temp->next;
		second_half = second_half->next;
	}

	return (1);
}
