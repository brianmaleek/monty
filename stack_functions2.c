#include "monty.h"

/**
 * add_node_top - adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */

void add_node_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(global_var.fr);
		free(global_var.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = tmp->n + tmp->next->n;
	tmp->next->n = n;
	remove_node(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number
	__attribute__((unused)))
{
	(void)stack;
	(void)line_number;
}
