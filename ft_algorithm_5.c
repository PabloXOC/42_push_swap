/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 13:58:41 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

int	ft_biggest5(t_list_int *list_a, int cont)
{
	int	cont_1;
	int	cont_2;
	int	cont_3;

	cont_1 = list_a->content;
	cont_2 = list_a->next->content;
	cont_3 = list_a->next->next->content;
	if (cont > cont_1 && cont > cont_2 && cont > cont_3)
		return (1);
	return (0);
}

int	ft_ordered(t_list_int *list_a)
{
	int	cont_1;
	int	cont_2;
	int	cont_3;
	int	cont_4;
	int	cont_5;

	cont_1 = list_a->content;
	cont_2 = list_a->next->content;
	cont_3 = list_a->next->next->content;
	cont_4 = list_a->next->next->next->content;
	cont_5 = list_a->next->next->next->next->content;
	if (cont_1 < cont_2 && cont_2 < cont_3 && cont_3
		< cont_4 && cont_4 < cont_5)
		return (1);
	if (cont_2 < cont_1 && cont_1 < cont_3 && cont_3
		< cont_4 && cont_4 < cont_5)
		return (2);
	return (0);
}

void	ft_algorithm_5(t_list_int *list_a, t_list_int *list_b)
{
	int	i;

	i = 0;
	if (ft_ordered(list_a) == 1)
		return ;
	if (ft_ordered(list_a) == 2)
		sa(list_a, 0);
	else
	{
		pb(&list_a, &list_b);
		pb(&list_a, &list_b);
		ft_algorithm_3(list_a, FALSE);
		if (list_b->content < list_b->next->content)
			sb(list_b, 0);
		if (ft_biggest5(list_a, list_b->content) == 1)
		{
			pa(&list_a, &list_b);
			ra(list_a, 0);
		}
		else
			sb(list_b, 0);
		while (ft_lstsize_int(list_b) > 0)
		{
			if (list_b->content < list_a->content)
				pa(&list_a, &list_b);
			ra(list_a, 0);
			i++;
		}
		while (i < 5)
		{
			ra(list_a, 0);
			i++;
		}
	}
	while (list_a != NULL)
	{
		ft_printf("(%d)\n", list_a->content);
		list_a = list_a->next;
	}
	ft_lstclear_int(&list_a);
	ft_lstclear_int(&list_b);
	return ;
}
