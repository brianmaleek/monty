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
	/*add*/
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
	/*add the second top node to the top node*/
	n = tmp->n + tmp->next->n;
	/*set the top node to the sum*/
	tmp->next->n = n;
	/*remove the top node*/
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
	/*nop*/
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
	/*subtract the second top node from the top node*/
	res = tmp->next->n - tmp->n;
	/*set the top node to the difference*/
	tmp->next->n = res;
	/*remove the top node*/
	remove_node(stack, line_number);
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
	/*divide the second top node by the top node*/
	res = tmp->next->n / tmp->n;
	/*set the top node to the quotient*/
	tmp->next->n = res;
	/*remove the top node*/
	remove_node(stack, line_number);
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
	/*multiply the second top node by the top node*/
	res = tmp->n * tmp->next->n;
	/*set the top node to the product*/
	tmp->next->n = res;
	/*remove the top node*/
	remove_node(stack, line_number);
}
