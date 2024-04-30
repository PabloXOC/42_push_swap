/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 11:51:56 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "push_swap.h"

void	rra(t_list_int *list_a, int rr)
{
	int			temp_prev;
	int			temp_act;
	int			index_prev;
	int			index_act;

	if (list_a != NULL)
	{
		temp_prev = ft_lstlast_int(list_a)->content;
		index_prev = ft_lstlast_int(list_a)->index;
		while (list_a->next != NULL)
		{
			temp_act = list_a->content;
			index_act = list_a->index;
			list_a->content = temp_prev;
			list_a->index = index_prev;
			temp_prev = temp_act;
			index_prev = index_act;
			list_a = list_a->next;
		}
		list_a->content = temp_prev;
		list_a->index = index_prev;
	}
	if (rr == 0)
		ft_printf("rra\n");
}
