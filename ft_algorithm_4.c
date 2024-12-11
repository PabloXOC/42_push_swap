/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/12/11 15:02:21 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

int	ft_biggest(t_list_int *list_a, int cont)
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

void	ft_algorithm_4(t_list_int *list_a, t_list_int *list_b)
{
	int	i;

	pb(&list_a, &list_b);
	ft_algorithm_3(list_a, FALSE);
	i = 0;
	if (ft_biggest(list_a, list_b->content) == 0)
	{
		while (list_b->content > list_a->content)
		{
			i++;
			ra(list_a, 0);
		}
	}
	pa(&list_a, &list_b);
	while (i > 0)
	{
		rra(list_a, 0);
		i--;
	}
	if (list_a->content > list_a->next->content)
		ra(list_a, 0);
	while (list_a != NULL)
	{
		//ft_printf("(%d)\n", list_a->content);
		list_a = list_a->next;
	}
	ft_lstclear_int(&list_a);
	//ft_lstclear_int(&list_b);
}
