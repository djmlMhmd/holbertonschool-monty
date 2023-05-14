#include "monty.h"
#include <stdlib.h>

/**
 * nop - Does nothing.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the instruction.
 */
void nop(
	stack_node_t **stack,
	unsigned int line_number __attribute__((unused)))
{
	(void)**stack;
	(void)line_number;
}
