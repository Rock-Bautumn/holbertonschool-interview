#include "lists.h"

listint_t *get_list_item(listint_t *head, size_t index)
{
	size_t search = 0;
	listint_t *t_n = head;

	for (; t_n; t_n = t_n->next, search++)
		if (search == index)
			return (t_n);

	return (NULL);
}

int is_palindrome(listint_t **head)
{
	listint_t *t_n = *head;
	size_t end = 0, index = 0;

	if (t_n == NULL)
		return (true);

	for (; t_n; t_n = t_n->next)
		end++;
	end--;

	for (t_n = *head; index < end; t_n = t_n->next, index++, end--)
		if (t_n->n != get_list_item(*head, end)->n)
			return (false);

	return (true);
}
