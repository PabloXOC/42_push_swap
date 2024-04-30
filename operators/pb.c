/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 13:54:34 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "push_swap.h"

void	pb(t_list_int **list_a, t_list_int **list_b)
{
	t_list_int	*temp;
	t_list_int	*new;

	if (list_a == NULL)
	{
		ft_printf("pb\n");
		return ;
	}
	if ((*list_b) == NULL)
	{
		(*list_b) = ft_lstnew_int((*list_a)->content);
		(*list_b)->index = (*list_a)->index;
	}
	else
	{
		new = ft_lstnew_int((*list_a)->content);
		new->index = (*list_a)->index;
		if (!(new))
			return ;
		ft_lstadd_front_int(list_b, new);
	}
	temp = (*list_a);
	(*list_a) = (*list_a)->next;
	free(temp);
	ft_printf("pb\n");
}
