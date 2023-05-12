#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>

/* data structures */
/**typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;*/

/*test*/
typedef struct stack_node_s
{
    int n;
    struct stack_node_s *prev;
    struct stack_node_s *next;
} stack_node_t;

typedef struct monty_stack_s
{
    stack_node_t *top;
} monty_stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_node_t **stack, unsigned int line_number);
} instruction_t;

/* function prototypes */

void pall(stack_node_t **stack, unsigned int line_number __attribute__((unused)));
void push(stack_node_t **stack, unsigned int line_number);
void pint(stack_node_t **stack, unsigned int line_number);
void parse_line(char *line, size_t line_len __attribute__((unused)), unsigned int line_number, stack_node_t **stack);
void process_file(FILE *file, stack_node_t **stack);
void pop(stack_node_t **stack, unsigned int line_number);
void swap(stack_node_t **stack, unsigned int line_number);
void add(stack_node_t **stack, unsigned int line_number);
void nop(stack_node_t **stack, unsigned int line_number __attribute__((unused)));
#endif /* MONTY_H */
