#include "monty.h"

/**
 * command_builder - addnode_end singly linked list of parsed commands.
 * @head: head of the linked list
 * @s: command to be parsed
 * @i: line number of the script
 * Return: new node, NULL if it fails.
 */
cmds *command_builder(cmds **head, char *s, int i)
{
	cmds *tmp = *head, *new = NULL;
	char *str;

	new = malloc(sizeof(cmds));
	if (!new)
		return (NULL);
	new->cmd[0] = strdup(strtok(s, " "));
	if (!(new->cmd[0]))
	{
		free(new);
		return (NULL);
	}
	str = strtok(NULL, " ");
	if (str)
	{
		new->cmd[1] = strdup(str);
		if (!(new->cmd[1]))
		{
			free(new->cmd[1]);
			free(new);
			return (NULL);
		}
	}
	else
		new->cmd[1] = NULL;
	new->line_number = i;
	new->next = NULL;
	if (!(*head))
	{
		*head = new;
		return (new);
	}
	for (; tmp->next; tmp = tmp->next)
		continue;
	tmp->next = new;
	return (new);
}
