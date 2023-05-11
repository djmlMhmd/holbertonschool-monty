#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_node_t *stack = NULL;
    char *line = NULL;
    size_t line_len = 0;
    unsigned int line_number = 0;
    ssize_t read;

    while ((read = getline(&line, &line_len, file)) != -1)
    {
        line_number++;
        if (read == 1 || line[0] == '#')
            continue;

        char *opcode = strtok(line, " \n");
        if (!opcode)
            continue;

        if (strcmp(opcode, "push") == 0)
            push(&stack, line_number);
        else if (strcmp(opcode, "pall") == 0)
            pall(&stack, line_number);
        else if (strcmp(opcode, "pint") == 0)
            pint(&stack, line_number);
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    return (EXIT_SUCCESS);
}
