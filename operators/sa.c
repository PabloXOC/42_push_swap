/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 11:53:21 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "push_swap.h"

void	sa(t_list_int *list_a, int ss)
{
	int	size;
	int	temp;
	int	temp_index;

	size = ft_lstsize_int(list_a);
	if (size < 2)
		return ;
	temp = list_a->content;
	temp_index = list_a->index;
	list_a->content = list_a->next->content;
	list_a->index = list_a->next->index;
	list_a->next->content = temp;
	list_a->next->index = temp_index;
	if (ss == 0)
		ft_printf("sa\n");
}
