/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:27:08 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 21:06:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_3(t_stack *stack)
{
	stack->stack_a_lowest = find_lowest(stack->stack_a, stack->stack_a_len);
	stack->stack_a_highest = find_highest(stack->stack_a, stack->stack_a_len);
	if (check_sorting(stack->stack_a, stack->stack_a_len) == 2
		|| stack->stack_a[2] == stack->stack_a_lowest)
	{
		do_instruction2(stack ,"ra");
		do_instruction2(stack ,"ra");
	}
	if (stack->stack_a[0] == stack->stack_a_lowest
		&& stack->stack_a[1] == stack->stack_a_highest)
	{
		do_instruction2(stack ,"sa");
		do_instruction2(stack ,"ra");
	}
	if (stack->stack_a[0] == stack->stack_a_highest
		&& stack->stack_a[1] == stack->stack_a_lowest)
		do_instruction2(stack ,"ra");;
	if (stack->stack_a[0] == stack->stack_a_highest
		&& stack->stack_a[2] == stack->stack_a_lowest)
	{
		do_instruction1(stack ,"rra");
		do_instruction1(stack ,"rra");
	}
	if (stack->stack_a[1] == stack->stack_a_lowest
		&& stack->stack_a[2] == stack->stack_a_highest)
		do_instruction1(stack ,"sa");
	if (stack->stack_a[1] == stack->stack_a_highest
		&& stack->stack_a[2] == stack->stack_a_lowest)
		do_instruction2(stack ,"rra");
}

void	sort_stack_5(t_stack *stack)
{	
	int		i;

	stack->stack_a_lowest = find_lowest(stack->stack_a, stack->stack_a_len);
	stack->stack_a_highest = find_highest(stack->stack_a, stack->stack_a_len);
	while (stack->stack_b_len != 2)
	{
		i = 0;
		stack->stack_a_lowest = find_lowest(stack->stack_a, stack->stack_a_len);
		while (stack->stack_a[i] != stack->stack_a_lowest)
			i++;
		if (i <= stack->stack_a_len / 2)
			while (stack->stack_a[0] != stack->stack_a_lowest)
				do_instruction2(stack ,"ra");
		if (i > stack->stack_a_len / 2)
			while (stack->stack_a[0] != stack->stack_a_lowest)
				do_instruction1(stack ,"rra");
		do_instruction2(stack, "pb");
	}
	if (check_sorting(stack->stack_a, stack->stack_a_len) != 1)
		sort_stack_3(stack);
	if (stack->stack_b[0] < stack->stack_b[1])
		do_instruction2(stack ,"sb");
}
