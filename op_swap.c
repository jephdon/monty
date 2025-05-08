#include "monty.h"

/**
 * op_swap - Swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	/* Swap the nodes */
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}
