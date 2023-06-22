#include "monty.h"
/**
 * add_node - adds a new node at the beginning of a stack_t list
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */


void add_node(stack_t **stack, unsigned int line_number
	__attribute__((unused)))
{/*push*/
	stack_t *new_node = malloc(sizeof(stack_t));
	int i = 0;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (global_var.args == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", global_var.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	while (global_var.args[i] != '\0')
	{
		if (global_var.args[i] == '-' && i == 0)
			continue;
		if (isdigit(global_var.args[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", global_var.line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new_node->n = atoi(global_var.args);
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
}


/**
 * print_reverse - prints all the elements of a stack_t list
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */

void print_reverse(stack_t **stack, unsigned int line_number
	__attribute__((unused)))
{
	/*pall*/
	stack_t *tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}
