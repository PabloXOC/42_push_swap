/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_6_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/06 12:34:42 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

int	ft_highest(t_list_int *list)
{
	int	highest;

	highest = list->content;
	list = list->next;
	while (list != NULL)
	{
		if (list->content > highest)
			highest = list->content;
		list = list->next;
	}
	return (highest);
}

int	ft_lowest(t_list_int *list)
{
	int	lowest;

	lowest = list->content;
	list = list->next;
	while (list != NULL)
	{
		if (list->content < lowest)
			lowest = list->content;
		list = list->next;
	}
	return (lowest);
}

int	ft_ordered6(t_list_int *list_a)
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
/* 
void	ft_6_plus_cont2(t_list_int **list_a, t_list_int **list_b)
{
	int	i;

	i = 0;
	while ((*list_b)->content > (*list_a)->content)
	{
		ra((*list_a), 0);
		i++;
	}
	pa(list_a, list_b);
	if (i > ft_lstsize_int((*list_a)) / 2)
	{
		while (ft_lstsize_int((*list_a)) > i)
		{
			ra((*list_a), 0);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rra((*list_a), 0);
			i--;
		}
	}
}

void	ft_6_plus_cont(t_list_int *list_a, t_list_int *list_b, int size_b)
{
	while (size_b > 0)
	{
		if (list_b->content < list_a->content)
		{
			pa(&list_a, &list_b);
		}
		else if (list_b->content > ft_highest(list_a))
		{
			pa(&list_a, &list_b);
			ra(list_a, 0);
		}
		else
			ft_6_plus_cont2(&list_a, &list_b);
		size_b--;
	}
}

void	ft_algorithm_6_plus(t_list_int *list_a, t_list_int *list_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize_int(list_a);
	if (ft_ordered6(list_a) == TRUE)
		return ;
	while (i + 3 < size)
	{
		pb(&list_a, &list_b);
		i++;
	}
	ft_algorithm_3(list_a);
	ft_printf("%d\n", 11);
	ft_6_plus_cont(list_a, list_b, i);
	return ;
}
 */

void	ft_6_plus_cont2_2(t_list_int **list_a, t_list_int **list_b)
{
	int	i;

	i = 0;
	while ((*list_a)->content < (*list_b)->content)
	{
		rb((*list_b), 0);
		i++;
	}
	pb(list_a, list_b);
	if (i > ft_lstsize_int((*list_b)) / 2)
	{
		while (ft_lstsize_int((*list_b)) > i)
		{
			rb((*list_b), 0);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rrb((*list_b), 0);
			i--;
		}
	}
}

void	ft_6_plus_cont_2(t_list_int **list_a, t_list_int **list_b, int size_a)
{
	while (size_a > 0)
	{
		if ((*list_a)->content > (*list_b)->content)
		{
			pb(list_a, list_b);
		}
		else if ((*list_a)->content < ft_lowest((*list_b)))
		{
			pb(list_a, list_b);
			rb((*list_b), 0);
		}
		else
			ft_6_plus_cont2_2(list_a, list_b);
		size_a--;
	}
}

void	ft_algorithm_6_plus(t_list_int *list_a, t_list_int *list_b)
{
	if (ft_ordered6(list_a) == TRUE)
		return ;
	pb(&list_a, &list_b);
	pb(&list_a, &list_b);
	if (list_b->content < list_b->next->content)
		sb(list_b, 0);
	ft_6_plus_cont_2(&list_a, &list_b, ft_lstsize_int(list_a));
	while (ft_lstsize_int(list_b) > 0)
		pa(&list_a, &list_b);
	/* while (list_a != NULL)
	{
		ft_printf("(%d)\n", list_a->content);
		list_a = list_a->next;
	} */
	ft_lstclear_int(&list_a);
	ft_lstclear_int(&list_b);
	return ;
}
