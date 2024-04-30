/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 11:37:16 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "push_swap.h"

void	rb(t_list_int *list_b, int rr)
{
	int			first;
	int			first_index;
	t_list_int	*temp;

	if (list_b != NULL)
	{
		first = list_b->content;
		first_index = list_b->index;
		temp = list_b;
		while (temp->next != NULL)
		{
			temp->index = temp->next->index;
			temp->content = temp->next->content;
			temp = temp->next;
		}
		temp->index = first_index;
		temp->content = first;
	}
	if (rr == 0)
		ft_printf("rb\n");
}
