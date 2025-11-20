/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:45:31 by yzhuang           #+#    #+#             */
/*   Updated: 2023/06/16 12:18:53 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_list
{
	int				i;
	int				nb;
	struct s_list	*tail;
	struct s_list	*next;
	struct s_list	*topush;
	char			*acts;
	struct s_cost	*cst;
}	t_lst;

typedef struct s_cost
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rcost;
	int	rrcost;
	int	cost;
}	t_cst;

//********************tools for char and string**********************//

void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
void	ft_strcpy(char *s1, char *s2, char *new, int i);
char	*ft_strjoin(char *s1, char *s2);
char	*cut_join(char *s1, char *s2, int cut, int tsize);

//**********************tools for linked lists***********************//

int		ft_lstsize(t_lst *lst);
t_lst	*ft_lstlast(t_lst *lst);
void	ft_lstadd_front(t_lst **lst, t_lst *new);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
t_lst	*new_last(t_lst *lst, t_lst *t);

//************************tools for tables***************************//

void	update_index(t_lst **a, int *tab, int ttl);
void	create_tab(int ac, char **ags, int *tab);
int		tab_is_sorted(int *lst, int ac);
void	cst_to_tab(t_cst *cst, int *ct);
void	ft_sort_int_tab(int *tab, int size);

//************************init and clear*****************************//

void	cst_init(t_cst **cst);
void	cst_reinit(t_cst **cst);
void	lst_init(t_lst **lst, int nb, t_cst *cst);
t_lst	*create_stk(int *tab, int ac);
void	ft_clear(t_lst **lst);

//************************checking***********************************//

int		is_dup(int *tab, int ac);
int		stoi(const char *str, int *tab);
int		ft_isdigit(int c);
void	check_ags(int ac, char **ags, int *tab);
int		lst_is_sorted(t_lst *lst);

//************************deviding***********************************//

int		keep_a(t_lst *a, int count, int mid_a);
void	ft_devide_stk(t_lst **a, t_lst **b, int la, int *msk);
void	devide_further(t_lst **a, t_lst **b, int la, int *msk);
void	devide_stk(t_lst **a, t_lst **b, int la, int *msk);

//*********************cost counting*********************************//

int		a_min(t_lst *a);
void	count_ra(t_lst *a, t_lst **b, int nb, int min);
int		count_bsorted(t_lst *b, int bsorted);
int		count_last_roll(t_lst *a);
void	add_acost(t_lst *a, t_lst **b, int nb, int min);
void	add_cost(t_lst *a, t_lst **b, int nb);
void	update_costs(t_lst **a, t_lst **b, int ttl, int lb);
int		get_algo(t_lst *b);
void	final_cost(t_lst **b, int dir);
void	get_best(t_lst **b);

//************************sorting************************************//

void	ft_sort_int_tab(int *tab, int size);
void	sort_2(t_lst **a, t_lst **b);
void	sort_3(t_lst **a, t_lst **b, int ttl, int *tab);
void	sort_more(t_lst **a, t_lst **b, int ttl, int lb);
void	go_sorting(t_lst **a, int *tab, int ttl);

//************************operations*********************************//

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
void	do_rolling(t_lst **a, t_lst **b, t_cst *cst);
int		do_push(t_lst **a, t_lst **b);
void	finalising(t_lst **a, int ttl, int ts);
void	ft_exit(int *tab);

//************************the main***********************************//

void	ok_to_go(int ac, int *tab);

#endif
