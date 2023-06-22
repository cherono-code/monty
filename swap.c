#include "monty.h"

/**
 * f_swap - adding the top two elements of the stack.
 * @head: the stack head
 * @counter: the line_number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *r;
	int lenn = 0, aux;

	r = *head;
	while (r)
	{
		r = r->next;
		lenn++;
	}
	if (lenn < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	r = *head;
	aux = r->n;
	r->n = r->next->n;
	r->next->n = aux;
}
