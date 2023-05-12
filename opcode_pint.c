#include "monty.h"
#include <stdlib.h>

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode being executed
 */
void pint(stack_node_t **stack, unsigned int line_number)
{
		if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

		printf("%d\n", (*stack)->n);
}

