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

/**
 * sub_node_top - subtracts the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void sub_node_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(global_var.fr);
		free(global_var.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	res = tmp->next->n - tmp->n;
	tmp->next->n = res;
	free_stack(*stack);
}

/**
 * div_node_top - divides the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void div_node_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(global_var.fr);
		free(global_var.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(global_var.fr);
		free(global_var.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	res = tmp->next->n / tmp->n;
	tmp->next->n = res;
	free_stack(*stack);
}

/**
 * mul_node_top - multiplies the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void mul_node_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(global_var.fr);
		free(global_var.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	res = tmp->n * tmp->next->n;
	tmp->next->n = res;
	free_stack(*stack);
}
