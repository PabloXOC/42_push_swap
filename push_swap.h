/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:01:07 by pablo             #+#    #+#             */
/*   Updated: 2024/02/10 14:40:22 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//libft
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

# define TRUE 1
# define FALSE 0

typedef struct s_list_int
{
	int					content;
	int					index;
	struct s_list_int	*next;
}						t_list_int;

//list functions
t_list_int	*ft_lstnew_int(int content);
int			ft_lstsize_int(t_list_int *lst);
void		ft_lstadd_back_int(t_list_int **lst, t_list_int *new);
void		ft_lstadd_front_int(t_list_int **lst, t_list_int *new);
void		ft_lstclear_int(t_list_int **lst);
void		ft_lstdelone_int(t_list_int *lst);
void		ft_lstiter_int(t_list_int *lst, void (*f)(int));
t_list_int	*ft_lstlast_int(t_list_int *lst);
t_list_int	*map_int(t_list_int *lst, int (*f)(int));
int			ft_lstindex_int(t_list_int *lst, int content);
int			ft_lstlastindex_int(t_list_int *lst);
void		ft_printlist(t_list_int *list);

//setting up problem
t_list_int	*ft_put_in_a(int argc, char **argv, int i);
int			ft_check_spaces(char **argv);
int			ft_check_input(int argc, char **argv);
int			count_argv(char **argv);
t_list_int	*ft_make_list_a(int argc, char **argv);
int			ft_check_same_input(char **argv, int i, int j);
int			ft_additional_rules(char **argv);

//operators
void		sa(t_list_int *list_a, int ss);
void		sb(t_list_int *list_b, int ss);
void		ss(t_list_int *list_a, t_list_int *list_b);
void		ra(t_list_int *list_a, int rr);
void		rb(t_list_int *list_b, int rr);
void		rra(t_list_int *list_a, int rr);
void		rrb(t_list_int *list_a, int rr);
void		rrr(t_list_int *list_a, t_list_int *list_b);
void		pa(t_list_int **list_a, t_list_int **list_b);
void		pb(t_list_int **list_a, t_list_int **list_b);

//algorithms
void		ft_algorithm_2(t_list_int *list_a);
void		ft_algorithm_3(t_list_int *list_a, int only3);
void		ft_algorithm_4(t_list_int *list_a, t_list_int *list_b);
void		ft_algorithm_5(t_list_int *list_a, t_list_int *list_b);
void		ft_algorithm_6_plus(t_list_int *list_a, t_list_int *list_b);
void		ft_algorithm_6_plus_copy(t_list_int *list_a, t_list_int *list_b);

//algorithm 6

#endif
