/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:15:39 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 13:53:48 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "push_swap.h"

t_list_int	*ft_lstnew_int(int content)
{
	t_list_int	*new_node;

	new_node = (t_list_int *)malloc(sizeof(t_list_int));
	if (!(new_node))
		return (NULL);
	new_node[0].content = content;
	new_node[0].index = 0;
	new_node[0].next = NULL;
	return (new_node);
}

int	ft_lstsize_int(t_list_int *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	ft_lstadd_back_int(t_list_int **lst, t_list_int *new)
{
	t_list_int	*last_item;

	if (lst != NULL && new != NULL)
	{
		last_item = ft_lstlast_int(*lst);
		if (last_item == NULL)
			*lst = new;
		else
			last_item->next = new;
	}
}

void	ft_lstadd_front_int(t_list_int **lst, t_list_int *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
	return ;
}

void	ft_lstclear_int(t_list_int **lst)
{
	t_list_int	*int_list;

	while (*lst != NULL)
	{
		int_list = (*lst)->next;
		ft_lstdelone_int(*lst);
		*lst = int_list;
	}
}
