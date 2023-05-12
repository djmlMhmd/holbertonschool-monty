#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the pall opcode.
 */

void pall(stack_node_t **stack, unsigned int line_number)
{
		stack_node_t *node = *stack;

		while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
