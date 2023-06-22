#include "monty.h"

/**
 * mod_node_top - computes the rest of the
 * division of the second top two elements
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void mod_node_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
	res = tmp->next->n % tmp->n;
	tmp->next->n = res;
	free_stack(*stack);
}

/**
 * pchar_node_top - prints the char at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pchar_node_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(global_var.fr);
		free(global_var.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (tmp->n < 0 || tmp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(global_var.fr);
		free(global_var.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

/**
 * pstr_node_top - prints the string starting at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pstr_node_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while (tmp != NULL && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl_node_top - rotates the stack to the top
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void rotl_node_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int n;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	n = tmp->n;
	remove_node(stack, line_number);
	add_node(stack, n);
}

/**
 * rotr_node_top - rotates the stack to the bottom
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void rotr_node_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int n;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (tmp->next != NULL)
		tmp = tmp->next;
	n = tmp->n;
	remove_node(stack, line_number);
	add_node(stack, n);
}
