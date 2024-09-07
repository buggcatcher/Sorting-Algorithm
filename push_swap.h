/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:17:08 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 20:18:01 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	totmoves;
}	t_moves;

typedef struct s_nodes
{
	int				value;
	int				index;
	int				*content;
	struct s_nodes	*next;
	struct s_nodes	*prev;
	t_moves			moves;
}	t_nodes;

typedef struct s_data
{
	t_nodes	*stack_a;
	t_nodes	*stack_b;
	char	**args;
	int		free_flag;
	int		*temp_array;
	int		len;
	int		stack_size;
	int		*array;
}	t_data;

void			initialize(int argc, char **argv, t_data *data);
void			perform_rr(t_moves *moves, t_nodes **stack_a, \
				t_nodes **stack_b);
void			perform_ra(t_moves *moves, t_nodes **stack_a);
void			perform_rrr(t_moves *moves, t_nodes **stack_a, \
				t_nodes **stack_b);
void			perform_rra(t_moves *moves, t_nodes **stack_a);
void			perform_rb(t_moves *moves, t_nodes **stack_b);
void			perform_rrb(t_moves *moves, t_nodes **stack_b);
void			execute_rotations(t_moves *moves, t_nodes **stack_a, \
				t_nodes **stack_b);
void			rotate_to_min(t_nodes **stack_a);
int				find_min_index(t_nodes *stack);
int				check_order(t_nodes *stack);
int				calculate_distance_from_head(t_nodes *stack, int target);
int				find_target(t_nodes *stack_a, t_nodes *stack_b);
void			target_distance(t_moves *moves, t_nodes *stack_a, \
				t_nodes *stack_b);
t_moves			assign_cost(t_moves moves);
int				find_cheapest_move(t_moves *moves);
void			execute_cheapest_move(t_moves *moves, t_nodes **stack_a, \
				t_nodes **stack_b);
void			execute_moves(t_moves *moves, t_nodes **stack_a, \
				t_nodes **stack_b);
int				find_min_index(t_nodes *stack);
int				is_min_index_on_top(t_nodes *stack);
void			print_moves_cost(t_moves moves);
int				make_chunks(int count);
void			push_chunks(t_nodes **stack_a, t_nodes **stack_b, int count);
void			update_chunks(t_nodes **stack_b, int *min_chunk, int *step, \
				int *pushed);
void			divide_and_push(t_nodes **stack_a, t_nodes **stack_b);
void			fill_left(int arr[], int temp_left[], int left, int low);
void			fill_right(int arr[], int temp_right[], int right, int middle);
int				create_arrays(int left, int right, int **temp_left, \
				int **temp_right);
int				cold_start(int arr[], t_nodes **list_a, int length);
void			merge_sort(int arr[], int length);
void			merge_sort_recursion(int arr[], int low, int high);
void			merge_sorted_arrays(int arr[], int low, int middle, int high);
int				binary_search(int arr[], int target, int low, int high);
int				*sort_temp_array(int arr[], int length);
void			ft_print_array(int arr[], int length);
void			assign_indices(t_nodes *stack_a, int *sorted_array, \
				int length);
void			ft_print_indices_and_values(t_nodes *stack_a);
int				ft_sort2(t_nodes **stack_a);
void			ft_sort3(t_nodes **stack_a);
void			process_stack(t_nodes *stack_a, int **temp_array);
void			check_for_letters(char **argv);
void			sort_case_1(t_nodes **stack_a);
void			sort_case_2(t_nodes **stack_a);
void			sort_case_3(t_nodes **stack_a);
void			sort_case_4(t_nodes **stack_a);
void			sort_case_5(t_nodes **stack_a);
int				ft_push_cost(t_nodes *node_b);
void			exe_cheapest_move(t_nodes **stack_a, t_nodes **stack_b);
t_nodes			*ft_find_min_node(t_nodes *stack_a);
void			ft_rotate_to_min(t_nodes **stack_a);
void			apply_moves(t_nodes *cheapest_node, t_nodes **stack_a, \
				t_nodes **stack_b);
void			handle_error(const char *message);
int				parse_sign(const char *str, int *index);
unsigned long	parse_number(const char *str, int *index);
int				ft_atoi_minmax(const char *str);
int				ft_isdup(int num, char **argv, int i);
int				ft_order_check(t_nodes *stack);
char			**ft_usage_check(int argc, char **argv);
char			**ft_arg_checker(int argc, char **argv);
int				validate_stack(t_nodes *stack_a, int free_flag, char **args);
t_nodes			*ft_createstack_a(char **args);
t_nodes			*ft_lstnew_int(int value);
t_nodes			*ft_lstlast_int(t_nodes *lst);
void			ft_lstadd_back_int(t_nodes **lst, t_nodes *new);
int				ft_lstsize_int(t_nodes *lst);
t_nodes			*ft_lstnew_index(int index);
void			ft_lstprev(t_nodes *head);
int				ft_lstlast_index(t_nodes *head);
t_nodes			*ft_lstmin_index(t_nodes *stack);
void			ft_lstclear_int(t_nodes **lst);
void			free_split(char **split);
void			validate_range(int argc, char **args);
void			initialize_stacks_part1(int argc, char **argv, int *free_flag, \
char ***args);
void			initialize_stacks_part2(t_nodes **stack_a, t_nodes **stack_b, \
char **args);
int				handle_memory_allocation(void *array, int free_flag, \
				void *args);
void			sort_stacks(t_nodes **stack_a, t_nodes **stack_b);
void			populate_array(t_nodes *stack_a, int *array);
int				ft_create_temp_array(t_nodes *stack, int **array);
void			handle_error(const char *message);
void			error_handler(const char *error_type);
void			free_args(char **args);
void			check_range(int argc, char **argv);
void			cleanup(t_data *data);
int				sa(t_nodes **stack_a);
int				sb(t_nodes **stack_b);
int				ss(t_nodes **stack_a, t_nodes **stack_b);
int				push(t_nodes **stack_to, t_nodes **stack_from);
int				pa(t_nodes **stack_a, t_nodes **stack_b);
int				pb(t_nodes **stack_b, t_nodes **stack_a);
void			ra(t_nodes **stack_a);
void			rb(t_nodes **stack_b);
void			rr(t_nodes **stack_a, t_nodes **stack_b);
void			rra(t_nodes **stack_a);
void			rrb(t_nodes **stack_b);
void			rrr(t_nodes **stack_a, t_nodes **stack_b);

#endif