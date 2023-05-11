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
    int n;
    char *arg;

    if (!stack)
    {
        fprintf(stderr, "L%d: stack not found\n", line_number);
        exit(EXIT_FAILURE);
    }

    arg = strtok(NULL, " \n");
    if (!arg || (!isdigit(*arg) && *arg != '-'))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    if (!n)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_node_t *new_node = malloc(sizeof(stack_node_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}
