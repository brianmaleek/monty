#include "monty.h"
/**
* main - main function
* @argc: number of arguments
* @argv: arguments
* Return: 0
*/

data_s global_var = {NULL, NULL, NULL, NULL, 0};
int main(int argc, char **argv)
{
	FILE *fr;
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fr = fopen(argv[1], "r");
	global_var.fr = fr;


	if (fr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read > 0)
	{
		line = NULL;
		read = getline(&line, &len, fr);
		global_var.line = line;
		line_number++;

		if (read > 0)
			get_command(&stack, line, line_number, fr);
		free(line);
	}
	fclose(fr);
	free_stack(stack);
	return (0);
}
