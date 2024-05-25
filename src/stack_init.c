/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:38:26 by qbarron           #+#    #+#             */
/*   Updated: 2024/05/14 12:38:26 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_synthax(char *str_n)
{
	if(!(*str_n == '+' 
					   || *str_n == '-' 
					   || (*str_n >= '0' && *str_n <= '9')))
				return(1);
	if((*str_n == '+' 
					  || *str_n == '-')
					  || !(*str_n >= '0' && *str_n <= '9'))
				return(1);
	while(*++str_n)
	{
		if(!(*str_n >= '0' && *str_n <= '9'))
			return(1);
	}
	return(0);
}

t_stack_node *get_cheapest(t_stack_node *stack)
{
	if(!stack)
		return (NULL);
	while(stack)
	{
		if(stack->cheapest)
			return(stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if(!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if(!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if(!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->next = last_node;
	}	
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while(argv[i])
	{
		if(error_synthax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if(error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

void	prep_for_push(t_stack_node **stack, 
					  t_stack_node *top_node,
					  char stack_name)
{
	while(*stack != top_node)
	{
		if(stack_name == 'a')
		{
			if(top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if(stack_name == 'b')
		{
			if(top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}