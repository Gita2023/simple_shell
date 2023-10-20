#include "shell.h"

/**
 * userexper_useless - solve the user experiance problem
 *
 * Return: const value
 */

void userexper_useless(void)
{
	char **live_query = NULL;
	int i, query_type = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&way, &n, stdin) != -1)
		{
			delete_newline(way);
			delete_comment(way);
			condition = runer(way, ";");
			for (i = 0; condition[i] != NULL; i++)
			{
				live_query = runer(condition[i], " ");
				if (live_query[0] == NULL)
				{
					free(live_query);
					break;
				}
				query_type = pass_query(live_query[0]);
				starter_fun(live_query, query_type);
				free(live_query);
			}
			free(condition);
		}
		free(way);
		exit(status);
	}
}

