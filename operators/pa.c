/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 13:54:43 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "push_swap.h"

void	pa(t_list_int **list_a, t_list_int **list_b)
{
	t_list_int	*temp;
	t_list_int	*new;

	if ((*list_b) == NULL)
	{
		ft_printf("pa\n");
		return ;
	}
	new = ft_lstnew_int((*list_b)->content);
	new ->index = (*list_b)->index;
	if (!(new))
		return ;
	ft_lstadd_front_int(list_a, new);
	temp = (*list_b);
	(*list_b) = (*list_b)->next;
	free(temp);
	ft_printf("pa\n");
}
