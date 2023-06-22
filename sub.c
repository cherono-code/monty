#include "monty.h"

/**
  *f_sub- the sustration
  *@head: the stack head
  *@counter: the line_number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int suss, node;

	aux = *head;
	for (node = 0; aux != NULL; node++)
		aux = aux->next;
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	suss = aux->next->n - aux->n;
	aux->next->n = suss;
	*head = aux->next;
	free(aux);
}
