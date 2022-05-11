#include "monty.h"

/**
 * m_sub - Function that subtracts the top two elements of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	size_t i = 1;

	for (; tmp && tmp->next; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		freell(stack);
		exit(EXIT_FAILURE);
	}
	tmp->prev->n -= tmp->n;
	m_pop(stack, line_number);
}
