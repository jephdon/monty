#include "monty.h"

/**
 * op_add - Adds te top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	sum = first->n + second->n;
	second->n = sum;
	/* Remove the top element */
	*stack = second;
	if (second->next != NULL)
		second->next->prev = second;
	free(first);
}
