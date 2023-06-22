#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: the number of arguments
* @argv: the monty file location
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char *cont;
	FILE *file;
	size_t s = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counters = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		cont = NULL;
		read_line = getline(&cont, &s, file);
		bus.cont = cont;
		counters++;
		if (read_line > 0)
		{
			execute(cont, &stack, counters, file);
		}
		free(cont);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
