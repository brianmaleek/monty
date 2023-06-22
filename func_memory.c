#include "monty.h"


/**
 * _realloc - reallocates a memory block using malloc and free
 * @pointer: pointer to the memory previously allocated
 * @old_size: size of the allocated space for pointer
 * @new_size: new size in bytes of the new memory block
 * Return: pointer to the new memory block
*/


void *_realloc(void *pointer, unsigned int old_size, unsigned int new_size)
{
	char *new_pointer;
	unsigned int i;

	if (new_size == old_size)
		return (pointer);
	if (pointer == NULL)
	{
		new_pointer = malloc(new_size);
		if (new_pointer == NULL)
			return (NULL);
		return (new_pointer);
	}
	if (new_size == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}
	new_pointer = malloc(new_size);
	if (new_pointer == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
		new_pointer[i] = ((char *)pointer)[i];
	free(pointer);
	return (new_pointer);
}


/**
 * free_stack - frees a stack_t list
 * @stack: pointer to the head of the stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * _free - frees memory
 * Return: void
 */


void _free(void)
{
	free(global_var.args);
	global_var.args = NULL;
	free(global_var.line);
	global_var.line = NULL;
}
