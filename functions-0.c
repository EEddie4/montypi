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
	new->cmd[0] = strdup(strtok(s, " \t"));
	if (!(new->cmd[0]))
	{
		free(new);
		return (NULL);
	}
	str = strtok(NULL, " \t");
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

/**
 * m_com - Function that find # in the line.
 * @s: line to read
 *
 * Return: 1 if find # and 0 if not find.
 */
int m_com(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '#')
			return (1);
	}
	return (0);
}

