/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:44:04 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/11 18:31:53 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h> 
# include <limits.h>

// the stack structure
typedef struct s_list
{
	int				index;
	int				sorted_index;
	long			data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// error_handlers
int		check_non_digit(char *str);
void	check_doubles(t_list **lst, int *error);
int		check_if_sorted(t_list *head);
void	is_valid(t_list **stack, int *error, int len);
void	free_list(t_list **head);
void	free_arr(char **tab);

// utils
t_list	*ft_lstnew(long element);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	endoflist(t_list **node);
char	**ft_split(char const *s, char c);
long	ft_atoi(char *str, int *error);
int		list_len(t_list	*lst);
int		ft_isws(char *str, int *error);

//operations
int		swap(t_list **head);
int		push(t_list **head_d, t_list **head_s);
int		rotate(t_list **head);
int		rev_rotate(t_list **head);
void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_b, t_list **head_a);
void	sa(t_list **head_a);
void	sb(t_list **head_b);
void	ss(t_list **head_a, t_list **head_b);
void	ra(t_list **head_a);
void	rb(t_list **head_b);
void	rr(t_list **head_a, t_list **head_b);
void	rra(t_list **head_a);
void	rrb(t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);

//main proc
void	create_list(char **argv, int argc, t_list **stack_a, int *error);

//sorting functions
void	sort_of_three(t_list **stack_a);
void	case_0(t_list **stack_a);
void	case_1(t_list **stack_a);
void	sort_of_five(t_list **stack_a, t_list **stack_b);
void	sort_it(t_list **stack_a, t_list **stack_b, int isFive);
void	sort_of_four(t_list **stack_a, t_list **stack_b);
void	min_in_list(t_list *stack_a, int *i, long *smallest_value);
int		move_min_to_top(t_list **stack_a, long smallest_value, int isUpper);
void	add_fix_index(t_list **stack);
void	sort_of_n(t_list **stack_a, t_list **stack_b, int len);
void	add_sorted_index(t_list **stack);
int		move_max_top(t_list **stack_a, int isUpper, int max_index);
void	max_index_in_list(t_list *stack, int *max_i, int *pos);
void	move_to_b(t_list **stack_a, t_list **stack_b, int len, int chunk_len);
void	move_a(t_list **stack_a, t_list **stack_b, int *max_i, int *max_i_pos);
int		which_chunk(int len);

//Bonus
char	*get_next_line(int fd);
void	double_ops(t_list **stack_a, t_list **stack_b, char *line);
void	is_valid_b(t_list **stack, int *error, int len);
int		my_strcmp(char *str0, char *str1);
int		badargs(t_list **stack_a);
int		decesion(t_list **stack_a, t_list **stack_b);
int		which_op(char *line, t_list **stack_a, t_list **stack_b);

#endif