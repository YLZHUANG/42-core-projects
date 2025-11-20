/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:07:08 by yzhuang           #+#    #+#             */
/*   Updated: 2023/06/01 18:10:05 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include "push_swap.h"

void	do_ps(char *line, t_lst **a, t_lst **b, int *tab);
void	do_ops(char *line, t_lst **a, t_lst **b, int *tab);
void	no_operation(void);
void	check_operations(int ac, int *tab);
void	checker_exit(int *tab, char *line, t_lst **a, t_lst **b);

//****************************checking*************************************//

int		is_dup(int *tab, int ac);
int		stoi(const char *str, int *tab);
int		ft_isdigit(int c);
void	check_ags(int ac, char **ags, int *tab);
int		lst_is_sorted(t_lst *lst);

//************************tools for tables*********************************//

int		tab_is_sorted(int *lst, int ac);
void	update_index(t_lst **a, int *tab, int ttl);
void	create_tab(int ac, char **ags, int *tab);

//********************tools for char and string****************************//

size_t	ft_strlen(const char *s);
void	ft_strcpy(char *s1, char *s2, char *new, int i);
char	*ft_strjoin(char *s1, char *s2);
char	*cut_join(char *s1, char *s2, int cut, int tsize);

//**********************tools for linked lists****************************//

int		ft_lstsize(t_lst *lst);
t_lst	*ft_lstlast(t_lst *lst);
void	ft_lstadd_front(t_lst **lst, t_lst *new);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
t_lst	*new_last(t_lst *lst, t_lst *t);

//************************init and clear*********************************//

void	cst_init(t_cst **cst);
void	lst_init(t_lst **lst, int nb, t_cst *cst);
t_lst	*create_stk(int *tab, int ac);
void	ft_clear(t_lst **lst);

//************************operations*************************************//

void	op_sa(t_lst **a);
void	op_sb(t_lst **a, t_lst **b);
void	op_ss(t_lst **a, t_lst **b);
void	op_pa(t_lst **a, t_lst **b);
void	op_pb(t_lst **a, t_lst **b);
void	op_ra(t_lst **a);
void	op_rb(t_lst **a, t_lst **b);
void	op_rr(t_lst **a, t_lst **b);
void	op_rra(t_lst **a);
void	op_rrb(t_lst **a, t_lst **b);
void	op_rrr(t_lst **a, t_lst **b);
void	ft_exit(int *tab);

#endif