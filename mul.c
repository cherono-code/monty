#include "monty.h"

/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: the stack head
 * @counter: the line_number
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	r = *head;
	aux = r->next->n * r->n;
	r->next->n = aux;
	*head = r->next;
	free(r);
}
