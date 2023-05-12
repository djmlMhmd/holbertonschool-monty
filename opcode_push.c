#include "monty.h"
#include <ctype.h>
#include <stdlib.h>

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode being executed
 */

void push(stack_node_t **stack, unsigned int line_number)
{
	if (args_len != 2 || !is_number(args[1]))
	{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	global_status = EXIT_FAILURE;
	return;
	}

	int number = atoi(args[1]);

	monty_stack_t *new_node = malloc(sizeof(monty_stack_t));

	if (!new_node)
	{
	fprintf(stderr, "Error: malloc failed\n");
		global_status = EXIT_FAILURE;
	return;
	}

	new_node->n = number;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack)
	(*stack)->prev = new_node;
	*stack = new_node;
}


