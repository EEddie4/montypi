#include "monty.h"

cmds *head = NULL;
/**
 * main - entry point, evaluates path name.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: EXIT_SUCCESS, EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	FILE *f;
	char *s = NULL;
	size_t n, i;
	int r;
	stack_t *stk = NULL;
	cmds *tmp2;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (!f)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (i = 1; (r = getline(&s, &n, f)) != EOF; i++)
	{
		s[r - 1] = '\0';
		if (m_com(s))
			continue;
		if (!command_builder(&head, s, i))
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			freell(&stk);
			exit(EXIT_FAILURE);
		}
	}
	free(s);
	fclose(f);
	for (; head; free(tmp2->cmd[1]), free(tmp2->cmd[0]), free(tmp2))
	{
		tmp2 = head;
		execute_ops(&stk);
		head = head->next;
	}
	freell(&stk);
	return (EXIT_SUCCESS);
}
