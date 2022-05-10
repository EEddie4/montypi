#include "monty.h"


/**
 * add_dnodeint_end - Add a new node at the end of a list
 *
 * @head: pointer to Head of the list
 * @n: number to add in node
 *
 * Return: the address of the new element, or NULL if it failed
 */

void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	stack_t *tmp = *stack;
	cmds *cm = head;

	new_node = malloc(sizeof(stack_t));
	/*if (new_node == NULL)
		return (NULL);*/

	new_node->n = atoi(cm->cmd[1]);
	new_node->next = NULL;

	if (*stack == NULL)
	{
		new_node->prev = *stack;	
		*stack = new_node;
		return;
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
	new_node->prev = tmp;

	return;
}

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack; 

	if (tmp == NULL)
		return;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	while (tmp->prev != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
	printf("%d\n", tmp->n);
}


void m_pint(stack_t **stack, unsigned int line_number)
{

}


void m_pop(stack_t **stack, unsigned int line_number)
{

}


void m_swap(stack_t **stack, unsigned int line_number)
{

}

void m_add(stack_t **stack, unsigned int line_number)
{

}

void m_nop(stack_t **stack, unsigned int line_number)
{

}

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
