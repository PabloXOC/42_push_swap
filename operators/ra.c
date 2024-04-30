/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 11:35:32 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "push_swap.h"

void	ra(t_list_int *list_a, int rr)
{
	int			first;
	int			first_index;
	t_list_int	*temp;

	if (list_a != NULL)
	{
		first = list_a->content;
		first_index = list_a->index;
		temp = list_a;
		while (temp->next != NULL)
		{
			temp->index = temp->next->index;
			temp->content = temp->next->content;
			temp = temp->next;
		}
		temp->content = first;
		temp->index = first_index;
	}
	if (rr == 0)
		ft_printf("ra\n");
}
