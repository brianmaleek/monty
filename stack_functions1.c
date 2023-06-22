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

	if (tmp == NULL)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


/*
* top_node - prints the value at the top of the stack
* @stack: pointer to the head of the stack
* @line_number: line number of the opcode
*
* Return: void
*/

void top_node(stack_t **stack, unsigned int line_number)
{
	/*pint*/

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(global_var.fr);
		free(global_var.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * remove_node - deletes the head node of a stack_t list
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */
void remove_node(stack_t **stack, unsigned int line_number)
{
	/*pop*/
	stack_t *head = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else{
		/*set the head to the next node*/
		*stack = (*stack)->next;
		/*set the new head's prev to NULL*/
		if (*stack != NULL)
			(*stack)->prev = NULL;
		/*free the old head*/
		free(head);
	}
}

/**
 * swap_node - swaps the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */
void swap_node(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(global_var.fr);
		free(global_var.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = n;
}


