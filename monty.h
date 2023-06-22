#ifndef MONTY_H
#define MONTY_H


/* Libs */
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


/* Structs */

/**
 * struct global_variables - global variables
 * @fr: the file
 * @line: readed line
 * @args: arguments
 * @fn: file name
 * @line_number: line number
 *
 * Description: global variables
 * for stack, queues, LIFO, FIFO
 */

typedef struct global_variables
{
		FILE *fr;
		char *line;
		char *args;
		char *fn;
		unsigned int line_number;
} data_s;



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern data_s global_var;

/*prototypes*/
void add_node(stack_t **stack, unsigned int line_number); /*push*/
void print_reverse (stack_t **stack, unsigned int line_number); /*pall*/
void top_node(stack_t **stack, unsigned int line_number); /*pint*/
void swap_node(stack_t **stack, unsigned int line_number); /*swap*/
void remove_node(stack_t **stack, unsigned int line_number); /*pop*/
void add_node_top(stack_t **stack, unsigned int line_number); /*push*/
void nop(stack_t **stack, unsigned int line_number); /*nop*/

/*memory*/
void free_stack(stack_t *stack);
void *_realloc(void *pointer, unsigned int old_size, unsigned int new_size);
void _free(void);

/*helper functions*/
char **splitline(char *line);
int get_command(stack_t **stack, char *line, unsigned int counter, FILE *fr);




#endif /* MONTY_H */