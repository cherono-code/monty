#include "monty.h"

/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
<<<<<<< HEAD
	char *content = NULL;
=======
	char *content;
>>>>>>> 49b39a180245cdb0a4fdf5378fea82a0a996bc5f
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
<<<<<<< HEAD
		read_line = getline(&content, &size, file);
		counter++;

		if (read_line > 0)
		{
			content[strcspn(content, "\n")] = '\0';
			execute(content, &stack, counter, file);
		}
=======
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counters++;
		if (read_line > 0)
		{
			execute(content, &stack, counters, file);
		}
		free(content);
>>>>>>> 49b39a180245cdb0a4fdf5378fea82a0a996bc5f
	}

	free(content);
	free_stack(stack);
	fclose(file);

	return (0);
}

