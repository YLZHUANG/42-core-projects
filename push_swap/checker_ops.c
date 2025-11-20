/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:55:10 by yzhuang           #+#    #+#             */
/*   Updated: 2023/06/15 16:55:45 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_ps(char *line, t_lst **a, t_lst **b, int *tab)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		op_sa(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		op_sb(a, b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		op_ss(a, b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		op_pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		op_pb(a, b);
	else
		checker_exit(tab, line, a, b);
}

void	do_ops(char *line, t_lst **a, t_lst **b, int *tab)
{
	if (line[0] == 's' || line[0] == 'p')
		do_ps(line, a, b, tab);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		op_ra(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		op_rb(a, b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		op_rr(a, b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a'
		&& line[3] == '\n')
		op_rra(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'
		&& line[3] == '\n')
		op_rrb(a, b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'
		&& line[3] == '\n')
		op_rrr(a, b);
	else
		checker_exit(tab, line, a, b);
}

void	no_operation(void)
{
	char	*line;

	line = get_next_line(0);
	if (line)
	{
		write(1, "KO\n", 3);
		free(line);
	}
	else
		write(1, "OK\n", 3);
}

void	check_operations(int ac, int *tab)
{
	char	*line;
	t_lst	*a;
	t_lst	*b;

	a = NULL;
	b = NULL;
	line = NULL;
	a = create_stk(tab, ac);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		do_ops(line, &a, &b, tab);
		if (line)
			free(line);
	}
	if (b == NULL && lst_is_sorted(a) == 1 && ft_lstsize(a) == (ac - 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (a)
		ft_clear(&a);
	if (b)
		ft_clear(&b);
}

void	checker_exit(int *tab, char *line, t_lst **a, t_lst **b)
{
	if (tab)
		free(tab);
	if (line)
		free(line);
	if (*a)
		ft_clear(a);
	if (*b)
		ft_clear(b);
	write(1, "Error\n", 6);
	exit(1);
}
