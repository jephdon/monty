#include "monty.h"

/**
 * free_stack - Frees each node in the stack
 * @stack: stack memory to free
 *
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
