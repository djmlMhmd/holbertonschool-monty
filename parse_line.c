#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * parse_line - Parses a line of input from a Monty bytecode file and processes
 * it according to the corresponding opcode.
 * @line: The line of input to parse.
 * @line_len: The length of the line of input.
 * @line_number: The line number of the input.
 * @stack: A pointer to the top of the stack.
 */
void parse_line(char *line,
		size_t line_len __attribute__((unused)),
		unsigned int line_number,
		stack_node_t **stack)
{
		char *opcode = strtok(line, " \n");

		if (line == NULL || line[0] == '\0' || line[0] == '#')
		return;

		if (strcmp(opcode, "push") == 0)
			push(stack, line_number);

		else if (strcmp(opcode, "pall") == 0)
			pall(stack, line_number);

		else if (strcmp(opcode, "pint") == 0)
			pint(stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			pop(stack, line_number);
		else if (strcmp(opcode, "swap") == 0)
			swap(stack, line_number);
		else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
