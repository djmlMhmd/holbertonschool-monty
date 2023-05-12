#include "monty.h"
#include <stdlib.h>

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode being executed
 */
void swap(stack_node_t **stack, unsigned int line_number)
{
		if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

		int tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
}
