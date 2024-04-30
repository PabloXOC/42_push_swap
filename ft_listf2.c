/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listf2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:15:39 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 13:54:09 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "push_swap.h"

void	ft_lstdelone_int(t_list_int *lst)
{
	free(lst);
}

void	ft_lstiter_int(t_list_int *lst, void (*f)(int))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list_int	*ft_lstlast_int(t_list_int *lst)
{
	int		size;
	int		i;

	size = ft_lstsize_int(lst);
	i = 0;
	while (i < size - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	ft_lstlastindex_int(t_list_int *lst)
{
	int		size;
	int		i;

	size = ft_lstsize_int(lst);
	i = 0;
	while (i < size - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst->index);
}

int	ft_lstindex_int(t_list_int *lst, int index)
{
	while (lst)
	{
		if (index == lst->index)
			return (lst->content);
		lst = lst->next;
	}
	return (lst->index);
}

t_list_int	*map_int(t_list_int *lst, int (*f)(int))
{
	t_list_int	*new_node;
	t_list_int	*new_list;
	int			cont;

	new_list = NULL;
	while (lst != NULL)
	{
		cont = f(lst->content);
		new_node = ft_lstnew_int(cont);
		if (new_node == NULL)
		{
			ft_lstclear_int(&new_list);
			return (NULL);
		}
		ft_lstadd_back_int(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
