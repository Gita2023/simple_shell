#include "shell.h"

/**
 * OUTSIDE - out side the shell
 * @given_commands: input value
 *
 * Return: void
 */

void OUTSIDE(char **given_commands)
{
	int GIVEN_NUMBER = 0, arg;

	for (; given_commands[GIVEN_NUMBER] != NULL; GIVEN_NUMBER++)
		;
	if (GIVEN_NUMBER == 1)
	{
		free(given_commands);
		free(way);
		free(condition);
		exit(status);
	}
	else if (GIVEN_NUMBER == 2)
	{
		arg = _stringint(given_commands[1]);
		if (arg == -1)
		{
			output(value_shell, STDERR_FILENO);
			output(": 1: exit: Illegal number: ", STDERR_FILENO);
			output(given_commands[1], STDERR_FILENO);
			output("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(way);
			free(given_commands);
			free(condition);
			exit(arg);
		}
	}
	else
		output("$: only one arg to be quite\n", STDERR_FILENO);
}

/**
 *ENVIROMENT - output the status
 *@given_commands: task be generated
 *
 *Return: void
 */

void ENVIROMENT(char **given_commands __attribute__((unused)))
{
	int j;

	for (j = 0; environ[j] != NULL; j++)
	{
		output(environ[j], STDOUT_FILENO);
		output("\n", STDOUT_FILENO);
	}
}
