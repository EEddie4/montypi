#include "monty.h"

/**
 * m_pstr - prints the string starting at the top of the stack + '\n'
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	char str[1028];
	size_t i = 0;
	(void)line_number;

	if (!tmp)
		printf("\n");
	for (; tmp->next; tmp = tmp->next)
		;
	for (; tmp && tmp->n; tmp = tmp->prev, i++)
	{
		if (tmp->n < 0 || tmp->n > 128)
			break;
		str[i] = tmp->n;
	}
	str[i] = '\0';
	printf("%s\n", str);
}
