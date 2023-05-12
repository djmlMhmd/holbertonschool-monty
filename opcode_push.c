#include "monty.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode being executed
 */

void push(stack_node_t **stack, unsigned int line_number)
{
		char *value_str = strtok(NULL, " \n");

		if (value_str == NULL)
	{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
	}

		int value = atoi(value_str);

		if (value_str[0] == '\0' || (value == 0 && value_str[0] != '0'))
	{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
	}

		stack_node_t *new_node = malloc(sizeof(stack_node_t));

		if (new_node == NULL)
	{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
	}

		new_node->n = value;
		new_node->prev = NULL;
		new_node->next = *stack;

		if (*stack != NULL)
	{
			new_node->next = *stack;
			(*stack)->prev = new_node;
	}
		*stack = new_node;
}
