#include "monty.h"


/**
 * m_push - function that pusher an element to the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	stack_t *tmp = *stack;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(head->cmd[1]);
	if (!(new_node->n) && ((*(head->cmd[1]) != '0') ||
			       (strlen(head->cmd[1]) != 1)))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->next = NULL;

	if (!(*stack))
	{
		new_node->prev = *stack;
		*stack = new_node;
		return;
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->prev = tmp;
}

/**
 * m_pall - Function that print all values on the stack
 * starting from the top of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
		return;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
 * execute_ops - Function to execute options
 *
 * @stack: address of double linked list
 *
 */

void execute_ops(stack_t **stack)
{
	int i = 0;

	instruction_t options[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{NULL, NULL},
	};

	while (options[i].opcode)
	{
		if (!strcmp(options[i].opcode, head->cmd[0]))
		{
			(*options[i].f)(stack, head->line_number);
		}
		i++;
	}
}
