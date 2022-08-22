#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has
 * a cycle in it
 * @list: pointer to the list
 * Return: 0 if there is no cycle,
 * 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *ptr;
	listint_t *prev;

	ptr = list;
	prev = list;
	while (list && ptr && ptr->next)
	{
		list = list->next;
		ptr = ptr->next->next;

		if (list == ptr)
		{
			list = prev;
			prev =  ptr;
			while (1)
			{
				ptr = prev;
				while (ptr->next != list && ptr->next != prev)
				{
					ptr = ptr->next;
				}
				if (ptr->next == list)
					break;

				list = list->next;
			}
			return (1);
		}
	}

	return (0);
}
