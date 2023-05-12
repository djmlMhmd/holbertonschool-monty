#include "monty.h"
#include <stdlib.h>

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void pop(stack_node_t **stack, unsigned int line_number)
{
		if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

		stack_node_t *temp = *stack;
		*stack = (*stack)->next;

		free(temp);
}
