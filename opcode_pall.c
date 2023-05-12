#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode being executed
 */

void pall(stack_node_t **stack, unsigned int line_number)
{
		stack_node_t *current = *stack;

		(void)line_number;

	while (current)

	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

