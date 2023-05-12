#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point for Monty bytecode interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

	int global_status = EXIT_SUCCESS;
	char *args = NULL;

int main(int argc, char **argv)
{
		if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

		FILE *file = fopen(argv[1], "r");

		if (!file)

	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

		stack_node_t *stack = NULL;

		process_file(file, &stack);

		while (stack)
	{
		stack_node_t *next = stack->next;

		free(stack);

		stack = next;
	}

		fclose(file);
		return (EXIT_SUCCESS);
}
