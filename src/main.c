/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:36:44 by qbarron           #+#    #+#             */
/*   Updated: 2024/03/29 16:36:44 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv) //3 1 4 5 2
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;

	if (argc == 1 || argc == 2 && !argv[1][0])
	{
		error_message("Invalide type of argument");
		return(1);
	}
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1);
	if(!stack_sorted(a))
	{
		if(stack_len(a) == 2) //s'il n'y a que deux elements dans la liste
			sa(&a, false);
		else if(stack_len(a) == 3) // s'il n'y en que trois
			sort_three(&a);
		else
			sort_stack(&a, &b); // s'il y a en a +
	}
	free_stack(&a);
	return(0);
}

