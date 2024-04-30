/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 11:54:28 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "push_swap.h"

void	sb(t_list_int *list_b, int ss)
{
	int	size;
	int	temp;
	int	temp_index;

	size = ft_lstsize_int(list_b);
	if (size < 2)
		return ;
	temp = list_b->content;
	temp_index = list_b->index;
	list_b->content = list_b->next->content;
	list_b->index = list_b->next->index;
	list_b->next->content = temp;
	list_b->next->index = temp_index;
	if (ss == 0)
		ft_printf("sb\n");
}
