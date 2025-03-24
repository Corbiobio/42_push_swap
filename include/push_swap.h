/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:48:41 by edarnand          #+#    #+#             */
/*   Updated: 2025/03/24 14:46:07 by edarnand         ###   ########.fr       */
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

//push_swap
void	push_swap(int len, int *arr);

//operation
void	push_op(t_op **op, char *val, char id);
void	free_op(t_op *start);
void	print_op(t_op *start);
void	merge_all_op(t_op *start);

//instruction
void	r(t_stack st, t_op **op);
void	rr(t_stack st, t_op **op);
void	s(t_stack st, t_op **op);
void	p(t_stack *from, t_stack *to, t_op **op);

//stack
t_stack	init_stack(char id, int len, int *arr);
void	print_stack(t_stack st);

//get_fastest_to_top
int		get_fastest_to_top(t_stack st, int target);

//get_fastest_to_sort
int		get_fastest_to_sort(t_stack st, int target);

//sort_quarter
void	sort_quarter(t_stack *a, t_stack *b, t_op **op);

//sort
void	sort(t_stack *a, t_stack *b, t_op **op, t_op *op_start);

//sort_small_stack
void	sort_stack_6(t_stack *a, t_stack *b, t_op **op);
void	sort_stack_3(t_stack *a, t_op **op);

//verif_and_split_arg
char	**verif_and_split_arg(int argc, char **argv, int *to_free);

//arg_to_normalised_arr
int		*arg_to_normalised_arr(int *argc, char **argv);

//utils
void	error_exit(void);
void	free_argv(char **argv);
void	free_all(t_stack *a, t_stack *b, t_op *op);
int		is_sorted_descending(int *arr, int len);

//instruction_fake_bonus
void	r_fake(t_stack st);
void	rr_fake(t_stack st);
void	s_fake(t_stack st);
void	p_fake(t_stack *from, t_stack *to);

#endif