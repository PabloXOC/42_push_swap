/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:15:39 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/10 14:24:07 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "push_swap.h"

int	lowest_cluster_while(int current, int size, int lower, int index)
{
	int	found;

	found = 0;
	while (current <= size)
	{
		if (index == lower + current)
			found++;
		current++;
	}
	return (found);
}

int	lowest_cluster_while(t_list_int *head, int lower, int size, int found)
{
	int			current;
	int			i;
	t_list_int	*cycle;

	while (42)
	{
		size++;
		i = 1;
		found = 0;
		cycle = head;
		while (i <= size)
		{
			current = 1;
			found += inside(current, size, lower, cycle->index);
			i++;
			cycle = cycle->next;
		}
		if (found == size)
			return (size);
	}
	return (size);
}

// Function to create a new node
t_list_int	*newNode(int val)
{
	t_list_int	*node = (t_list_int *)malloc(sizeof(t_list_int));
	node->index = val;
	node->next = NULL;
	return (node);
}

int main()
{
	t_list_int* head = newNode(7);
	head->next = newNode(2);
	head->next->next = newNode(4);
	head->next->next->next = newNode(3);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	head->next->next->next->next->next->next = newNode(10);
	head->next->next->next->next->next->next->next = newNode(9);
	head->next->next->next->next->next->next->next->next = newNode(8);

	int result = lowest_cluster(head, 1, 0, 0);
	printf("Lowest range starting from the beginning: %d\n", result);

	// Free memory
	while (head != NULL)
	{
		t_list_int *temp = head;
		head = head->next;
		free(temp);
	}
	return 0;
}
