#include "monty.h"

/**
 * op_pall - prints all numbers of the stack from top to bottom
 * @stack: stack to be printed
 * @line_number: line index
 *
 * Return: nothing
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number; /* unnecessary but need by function signature */

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
