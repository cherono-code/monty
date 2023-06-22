#include "monty.h"

/**
 * f_push - adding node to the stack
 * @head: the stack head
 * @counter: the line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int k, i = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	k = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, k);
	else
		addqueue(head, k);
}
