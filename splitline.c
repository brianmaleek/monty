#include "monty.h"

#define DELIMITER " \n\t\a"
/**
 * splitline - splits a line into tokens
 * @line: line to be split
 * Return: pointer to an array of strings
 */

char **splitline(char *line)
{
	int buffer_size = 1024;
	int new_size = 0;
	int position = 0;
	char *token;
	char **tokens = malloc(buffer_size * sizeof(char *));

	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIMITER);
	do {
		if (token == NULL)
			break;
		tokens[position] = token;
		position++;
		if (position >= buffer_size)
		{
			new_size += buffer_size;
			tokens = _realloc(tokens, new_size * sizeof(char *),
							buffer_size * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMITER);
	} while (token != NULL);
	tokens[position] = NULL;
	return (tokens);
}
#undef DELIMITER
