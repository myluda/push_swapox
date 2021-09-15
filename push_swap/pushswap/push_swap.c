/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:36:29 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/07/06 10:36:31 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct t_node
{
	int				value;
	struct t_node	*next;
}				t_node;

t_node	*swap_a(t_node *stack)
{
	t_node *tmp;
	int		value;

	value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = value;
	return(stack);
}

t_node	*rotate_reverse_a(t_node *stack, int indicate)
{
	t_node *tmp;
	t_node *befinal;

	int		i;

	i = 0;
	tmp = stack;
	while(stack->next)
	{
		stack = stack->next;
		i++;
		if (i == indicate - 2)
		{
			befinal = stack;
		}
		
	}
	befinal->next = NULL;
	stack->next = tmp;
	return stack;
}

t_node	*rotate_a(t_node *stack)
{
	t_node *tmp;
	t_node *head;

	head = stack->next;
	tmp = stack;
	while(stack->next)
		stack = stack->next;
	stack->next = tmp;
	tmp->next = NULL;
	return head;
}
t_node  *fillstack(char **array, int size)
{
    t_node *stack;
    t_node *tmp;
    int i;

    i = 1;
    if (size < 0)
        return (NULL);
    stack = (t_node *)malloc(sizeof(t_node) * 1);
    tmp = stack;
    if (!stack)
        return (NULL);
    stack->value = atoi(array[i++]);
    stack->next = NULL;
    while (i <= size)
    {
        stack->next = (t_node *)malloc(sizeof(t_node) * 1);
        stack->next->value = atoi(array[i++]);
        stack->next->next = NULL;
        stack = stack->next;
    }
    return (tmp);
}
int main(int argc , char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = malloc(sizeof(t_node));
	stack_a = fillstack(argv, argc - 1);
	//stack_a = rotate_a(stack_a);
	stack_a = rotate_reverse_a(stack_a,argc - 1);
	while(stack_a)
	{
		printf("%d\n",stack_a->value);
		stack_a = stack_a->next;
	}
}