/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_6_plus_copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/10 15:15:59 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

//print list
void	ft_printlist(t_list_int *list)
{
	while (list != NULL)
	{
		ft_printf(" (%d, %d) \n", list->index, list->content);
		list = list->next;
	}
}

int	lowest_stack_while(int current, int size, int lower, int index)
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

int	lowest_stack(t_list_int *head, int lower, int size, int found)
{
	int			current;
	int			i;
	t_list_int	*cycle;

	while (size < ft_lstsize_int(head))
	{
		size++;
		i = 1;
		found = 0;
		cycle = head;
		while (i <= size)
		{
			current = 1;
			found += lowest_stack_while(current, size, lower, cycle->index);
			i++;
			cycle = cycle->next;
		}
		if (found == size)
			return (size);
	}
	return (size);
}

//highest value in range
int	ft_highest_copy(t_list_int *list, int n)
{
	int	highest;
	int	i;

	highest = 0;
	i = 0;
	while (list != NULL && (i < n || n == 0))
	{
		if (list->index > highest)
			highest = list->index;
		list = list->next;
		i++;
	}
	return (highest);
}

//lowest value in range
int	ft_lowest_copy(t_list_int *list, int n)
{
	int	lowest;
	int	i;

	lowest = ft_lstsize_int(list);
	i = 0;
	while (list != NULL && (i < n || n == 0))
	{
		if (list->index < lowest)
			lowest = list->index;
		list = list->next;
		i++;
	}
	return (lowest);
}

//check if all values are already in order
int	ft_ordered6_copy(t_list_int *list_a)
{
	int	prev;

	prev = list_a->content;
	while (list_a != NULL)
	{
		if (prev > list_a->content)
			return (FALSE);
		prev = list_a->content;
		list_a = list_a->next;
	}
	return (TRUE);
}

//calculate the average of the indices in the range 
int	ft_index_av(t_list_int *list, int n, int pass2a)
{
	int	i;
	int	value;
	int	av;

	value = 0;
	i = 0;
	while (list != NULL && (i < n || pass2a == TRUE))
	{
		value += list->index;
		list = list->next;
		i++;
	}
	av = value / i;
	if (pass2a == TRUE && value % i != 0)
		av++;
	return (av);
}

int	ft_stack_size(t_list_int *list, int n, int pass2a)
{
	int	i;
	int	value;
	int	av;

	value = 0;
	i = 0;
	while (list != NULL && (i < n || pass2a == TRUE))
	{
		value += list->index;
		list = list->next;
		i++;
	}
	av = value / i;
	if (pass2a == TRUE && value % i != 0)
		av++;
	return (av);
}

//check index(inside check, index and swap, then rotate appropriate part);
int	ft_check_index(t_list_int **list_a, int n)
{
	int	correct_order;
	int	passed_values;

	correct_order = TRUE;
	passed_values = 0;
	while (correct_order == TRUE && (passed_values < n || n == 0))
	{
		if (((*list_a)->index - 1 == ft_lstlastindex_int((*list_a))) || (*list_a)->index == 1)
		{
			ra((*list_a), 0);
			passed_values++;
		}
		else if ((*list_a)->next->index - 1 == ft_lstlastindex_int((*list_a)))
		{
			sa((*list_a), 0);
			ra((*list_a), 0);
			passed_values++;
		}
		else
			correct_order = FALSE;
	}
	return (passed_values); //returns number of rotated values
}

void	ft_index(t_list_int *list_a)
{
	t_list_int	*begining;
	t_list_int	*iterator;
	int			mypos;
	int			i;

	begining = list_a;
	while (begining)
	{
		iterator = list_a;
		i = 1;
		mypos = begining->content;
		while (iterator != NULL)
		{
			if (mypos > iterator->content)
				i++;
			iterator = iterator->next;
		}
		begining->index = i;
		begining = begining->next;
	}
}

void	ft_back2start(t_list_int *list_a, int passed_values)
{
	int	size_a;
	int	i;

	i = 0;
	size_a = ft_lstsize_int(list_a);
	if (passed_values < size_a)
	{
		while (i < passed_values)
		{
			rra(list_a, 0);
			i++;
		}
	}
	else
	{
		while (i < size_a - passed_values)
		{
			ra(list_a, 0);
			i++;
		}
	}
}

int	ft_send2a(t_list_int **list_a, t_list_int **list_b, int passed_values, int i)
{
	int	middle;
	int	stack;
	int	size_b;
	int	rotated;

	middle = ft_index_av((*list_b), 0, TRUE);
	size_b = ft_lstsize_int((*list_b));
	stack = 0;
	while (i < size_b)
	{
		if ((*list_b)->index >= middle)
		{
			pa(list_a, list_b);
			stack++;
		}
		else
			rb((*list_b), 0);
		i++;
	}
	if (ft_lstsize_int((*list_b)) > 0)
		passed_values = ft_send2a(list_a, list_b, passed_values, 0);
	rotated = ft_check_index(list_a, stack);
	passed_values += rotated;
	stack -= rotated;
	return (passed_values);
}

int	ft_send2b_while(t_list_int **list_a, t_list_int **list_b, int middle, int send2b)
{
	if ((*list_a)->index <= middle)
	{
		pb(list_a, list_b);
		send2b++;
	}
	else
		ra((*list_a), 0);
	return (send2b);
}

void	ft_send2b(t_list_int **list_a, t_list_int **list_b, int passed_values, int send2b)
{
	int	middle;
	int	i;
	int	stack;

	if (ft_ordered6_copy((*list_a)) == TRUE)
		return ;
	stack = lowest_stack((*list_a), ft_lstlastindex_int((*list_a)), 0, 0);
	if (passed_values == 0)
		stack = lowest_stack((*list_a), 0, 0, 0);

	middle = ft_index_av((*list_a), stack, FALSE);
	i = 0;
	while (i < stack)
	{
		send2b = ft_send2b_while(list_a, list_b, middle, send2b);
		i++;
	}
	ft_back2start((*list_a), (i - send2b));
	if (ft_lstsize_int((*list_b)) > 0)
		passed_values = ft_send2a(list_a, list_b, passed_values, 0);
	ft_send2b(list_a, list_b, passed_values, 0);
}

void	ft_algorithm_6_plus_copy(t_list_int *list_a, t_list_int *list_b)
{
	int	passed_values;

	if (ft_ordered6_copy(list_a) == TRUE)
		return ;
	ft_index(list_a);
	passed_values = ft_check_index(&list_a, ft_lstsize_int(list_a));
	ft_send2b(&list_a, &list_b, passed_values, 0);
	//ft_printlist(list_a);
	ft_lstclear_int(&list_a);
	ft_lstclear_int(&list_b);
	return ;
}
