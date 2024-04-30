/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 11:51:25 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "push_swap.h"

void	rrb(t_list_int *list_b, int rr)
{
	int			temp_prev;
	int			temp_act;
	int			index_prev;
	int			index_act;

	if (list_b != NULL)
	{
		temp_prev = ft_lstlast_int(list_b)->content;
		index_prev = ft_lstlast_int(list_b)->index;
		while (list_b->next != NULL)
		{
			temp_act = list_b->content;
			index_act = list_b->index;
			list_b->content = temp_prev;
			list_b->index = index_prev;
			temp_prev = temp_act;
			index_prev = index_act;
			list_b = list_b->next;
		}
		list_b->content = temp_prev;
		list_b->index = index_prev;
	}
	if (rr == 0)
		ft_printf("rrb\n");
}
