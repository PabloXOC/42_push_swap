/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 13:58:32 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

void	ft_algorithm_3(t_list_int *list_a, int only3)
{
	int	cont_1;
	int	cont_2;
	int	cont_3;

	cont_1 = list_a->content;
	cont_2 = list_a->next->content;
	cont_3 = list_a->next->next->content;
	if (cont_1 < cont_2 && cont_1 > cont_3)
		rra(list_a, 0);
	else if (cont_1 > cont_3 && cont_3 > cont_2)
		ra(list_a, 0);
	else if (cont_1 > cont_2 && cont_2 > cont_3)
	{
		ra(list_a, 0);
		sa(list_a, 0);
	}
	else if (cont_3 > cont_1 && cont_1 > cont_2)
		sa(list_a, 0);
	else if (cont_2 > cont_3 && cont_3 > cont_1)
	{
		rra(list_a, 0);
		sa(list_a, 0);
	}
	while (list_a != NULL)
	{
		ft_printf("(%d)\n", list_a->content);
		list_a = list_a->next;
	}
	if (only3 == TRUE)
		ft_lstclear_int(&list_a);
	return ;
}
