/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 13:58:24 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

void	ft_algorithm_2(t_list_int *list_a)
{
	if (list_a->content > list_a->next->content)
		sa(list_a, 0);
	while (list_a != NULL)
	{
		ft_printf("(%d)\n", list_a->content);
		list_a = list_a->next;
	}
	ft_lstclear_int(&list_a);
	return ;
}
