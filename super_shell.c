#include "shell.h"


	char **condition = NULL;
	char *way = NULL;
	char *value_shell = NULL;
	int status = 0;

/**
 * main - super code of simple shell
 * @value: count of task to done
 * @values: passed code

 * Return: 0 on success
 */

int main(int value __attribute__((unused)), char **values)
{
	char **live_query = NULL;
	int i, query_type = 0;
	size_t n = 0;

	signal(SIGINT, control_c);
	value_shell = values[0];
	while (1)
	{
		userexper_useless();
		output(" ($) ", STDOUT_FILENO);
		if (getline(&way, &n, stdin) == -1)
		{
			free(way);
			exit(status);
		}
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

			/* starter_fun -   */
			starter_fun(live_query, query_type);
			free(live_query);
		}
		free(condition);
	}
	free(way);

	return (status);
}

	
