/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:48:41 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/18 14:48:20 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int		*arr;
	char	id;
	int		len;
	int		min;
	int		max;
}	t_stack;

typedef struct s_op
{
	char		*val;
	char		id;
	int			count;
	struct s_op	*next;
}	t_op;

//operation
void	push_op(t_op **op, char *val, char id);
void	free_op(t_op *start);
void	print_op(t_op *start);

//instruction
void	r(t_stack st, t_op **op);
void	rr(t_stack st, t_op **op);
void	s(t_stack st, t_op **op);
void	p(t_stack *from, t_stack *to, t_op **op);

//stack
t_stack	init_stack(char id, int len, char **argv);
void	print_stack(t_stack st);

//sort
void	average_sort(t_stack *a, t_stack *b, t_op **op);
void	sort_25_to_75_percent(t_stack *a, t_stack *b, t_op **op);
void	sort_0_to_100_percent(t_stack *a, t_stack *b, t_op **op);

//fastest_to_op
int		fastest_to_top(t_stack st, int target);

//fastest_to_sort
int		fastest_to_sort(t_stack st, int target);


//utils
int		error(void);
int		ft_abs(int n);


#endif