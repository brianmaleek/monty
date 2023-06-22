#include "monty.h"


/**
* get_command - get the command
* @stack: pointer to the head of the stack
* @line: line to be read
* @counter: line number
* @fr: file to be read
* Return: 0 if success, 1 if failure
*/


int get_command(stack_t **stack, char *line, unsigned int counter, FILE *fr)
{
	instruction_t opcodes[] = {
		{"push", add_node},
		{"pall", print_reverse},
		{NULL, NULL}
	};

	unsigned int index = 0;
	char *operation;

	operation = strtok(line, " \n\t");

	if (operation && operation[0] == '#')
		return (0);

	global_var.args = strtok(NULL, " \n\t");

	do {
		if (strcmp(operation, opcodes[index].opcode) == 0)
		{
			opcodes[index].f(stack, counter);
			return (0);
		}
		index++;
	} while (opcodes[index].opcode != NULL);

	if (operation && opcodes[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
		_free();
		fclose(fr);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}