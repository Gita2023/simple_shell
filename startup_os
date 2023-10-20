#include "shell.h"

/**
 * starter_fun - lunch the run mode
 * @live_query: check the exsist query
 * @query_type: pass the connection
 *
 * Return: static function
 */

void starter_fun(char **live_query, int query_type)
{
	pid_t PID;

	if (query_type == OUT_QUERY || query_type == WAY_QUERY)
	{
		PID = fork();
		if (PID == 0)
			run_query(live_query, query_type);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		run_query(live_query, query_type);
}
