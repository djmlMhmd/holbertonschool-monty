#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * process_file - Processes a Monty bytecode file line by line.
 * @file: A pointer to the Monty bytecode file.
 * @stack: A pointer to the top of the stack.
 */
void process_file(FILE *file, stack_node_t **stack)
{
	char *line = NULL;
	size_t line_len = 0;
	unsigned int line_number = 0;
	ssize_t read;
	unsigned int args_len = 0;

		while ((read = getline(&line, &line_len, file)) != -1)
	{
		line_number++;
		parse_line(line, line_len, line_number, stack);
	}

		free(line);
}
