#include "monty.h"

/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		read_line = getline(&content, &size, file);
		counter++;

		if (read_line > 0)
		{
			content[strcspn(content, "\n")] = '\0';
			execute(content, &stack, counter, file);
		}
	}

	free(content);
	free_stack(stack);
	fclose(file);

	return (0);
}

