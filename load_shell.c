#include "shell.h"

/** pass_query - consideratin of query
 * @query: query ready to passing
 *
 * Return: const value
 * Description -
 * 		 OUT_QUERY (1) display root query
 *		 INSIDE_QUERY (2) display query quit, ENVIROMENT
 *		 WAY_QUERY (3) display exsit files
 *		 NOTCORRECT_QUERY (-1) display uncorrect query
 */

int pass_query(char *query)
{
	int i;
	char *internal_query[] = {"ENVIROMENT", "exit", NULL};
	char *link = NULL;

	for (i = 0; query[i] != '\0'; i++)
	{
		if (query[i] == '/')
			return (OUT_QUERY);
	}
	for (i = 0; internal_query[i] != NULL; i++)
	{
		if (_stringcmp(query, internal_query[i]) == 0)
			return (INSIDE_QUERY);
	}
	/* @fix_way - fix the run of query */
	link = fix_way(query);
	if (link != NULL)
	{
		free(link);
		return (WAY_QUERY);
	}

	return (NOTCORRECT_QUERY);
}

/**
 * run_query - run the query
 * @super_query: run all query
 * @query_type: type of the query
 *
 * Return: void
 */
void run_query(char **super_query, int query_type)
{
	void (*func)(char **query);

	if (query_type == OUT_QUERY)
	{
		if (execve(super_query[0], super_query, NULL) == -1)
		{
			perror(_rollbackfun("PWD"));
			exit(2);
		}
	}
	if (query_type == WAY_QUERY)
	{
		if (execve(fix_way(super_query[0]), super_query, NULL) == -1)
		{
			perror(_rollbackfun("PWD"));
			exit(2);
		}
	}
	if (query_type == INSIDE_QUERY)
	{
		func = retrive_fun(super_query[0]);
		func(super_query);
	}
	if (query_type == NOTCORRECT_QUERY)
	{
		output(value_shell, STDERR_FILENO);
		output(": 1: ", STDERR_FILENO);
		output(super_query[0], STDERR_FILENO);
		output(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * fix_way - fixing the run of the query
 * @query: querye used
 *
 * Return: link for the location of query
 */
char *fix_way(char *query)
{
	char **arr_value = NULL;
	char *teal, *teal2, *copy_link;
	char *link = _rollbackfun("PATH");
	int i;

	if (link == NULL || _lengthstr(link) == 0)
		return (NULL);
	copy_link = malloc(sizeof(*copy_link) * (_lengthstr(link) + 1));
	_copystring(link, copy_link);
	arr_value = runer(copy_link, ":");
	for (i = 0; arr_value[i] != NULL; i++)
	{
		teal2 = _stringcon(arr_value[i], "/");
		teal = _stringcon(teal2, query);
		if (access(teal, F_OK) == 0)
		{
			free(teal2);
			free(arr_value);
			free(copy_link);
			return (teal);
		}
		free(teal);
		free(teal2);
	}
	free(copy_link);
	free(arr_value);
	return (NULL);
}

/**
 * retrive_fun - rollback the func to describe
 * @query: desplay check
 *
 * Return: link to func or error, null
 */
void (*retrive_fun(char *query))(char **)
{
	int i;
	describe_func design[] = {
		{"ENVIROMENT", ENVIROMENT}, {"exit", OUTSIDE}
	};

	for (i = 0; i < 2; i++)
	{
		if (_stringcmp(query, design[i].query_name) == 0)
			return (design[i].func);
	}
	return (NULL);
}

/**
 * _rollbackfun - back the value of the var
 * @variable: address of the variable location
 *
 * Return: string value
 */
char *_rollbackfun(char *variable)
{
	char **my_uniqe;
	char *loc_link;
	char *address_link;

	for (my_uniqe = environ; *my_uniqe != NULL; my_uniqe++)
	{
		for (loc_link = *my_uniqe, address_link = variable;
		     *loc_link == *address_link; loc_link++, address_link++)
		{
			if (*loc_link == '=')
				break;
		}
		if ((*loc_link == '=') && (*address_link == '\0'))
			return (loc_link + 1);
	}
	return (NULL);
}
