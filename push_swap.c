/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/10 14:30:36 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

void	ft_push_swap(t_list_int *list_a, t_list_int *list_b, int size)
{
	if (size == 2)
		ft_algorithm_2(list_a);
	if (size == 3)
		ft_algorithm_3(list_a, TRUE);
	if (size == 4)
		ft_algorithm_4(list_a, list_b);
	if (size == 5)
		ft_algorithm_5(list_a, list_b);
	if (size > 5)
		ft_algorithm_6_plus_copy(list_a, list_b);
}

int	main(int argc, char **argv)
{
	t_list_int	*list_a;
	t_list_int	*list_b;

	argv++;
	argc--;
	list_a = ft_make_list_a(argc, argv);
	if (list_a == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	list_b = NULL;
	ft_push_swap(list_a, list_b, ft_lstsize_int(list_a));
}
