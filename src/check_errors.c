/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:21:07 by qbarron           #+#    #+#             */
/*   Updated: 2024/05/16 12:21:07 by qbarron          ###   ########.fr       */
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

int	error_duplicate(t_stack_node *a, int n)
{
	if(!a)
		return ;
	while(a)
	{
		if(a->nbr == n)
			return(1);
		a = a->next;
	}
	return(0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if(!stack)
		return ;
	current = *stack;
	while(current)
	{
		temp = current->next;
		current->nbr = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}