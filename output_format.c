#include "shell.h"

/**
 * runer - run input task
 *@task_pass: passed the task to be done
 *@diffr: diffrent bettween tasks
 *
 *Return: group of tasks
 */

char **runer(char *task_pass, char *diffr)
{
	int num_diffr = 0;
	char **var = NULL;
	char *task = NULL;
	char *task_pointer = NULL;

	task = _string_tokr(task_pass, diffr, &task_pointer);

	while (task != NULL)
	{
		var = _factloc(var, sizeof(*var) * num_diffr, sizeof(*var) * (num_diffr + 1));
		var[num_diffr] = task;
		task = _string_tokr(NULL, diffr, &task_pointer);
		num_diffr++;
	}

	var = _factloc(var, sizeof(*var) * num_diffr, sizeof(*var) * (num_diffr + 1));
	var[num_diffr] = NULL;

	return (var);
}

/**
 *output - display of tasks
 *@string: output of task
 *@flow: flow of output
 *
 *Return: value
 */
void output(char *string, int flow)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(flow, &string[i], 1);
}

/**
 *delete_newline - delete any task
 *@task: task to be done
 *
 *
 *Return: value
 */

void delete_newline(char *task)
{
	int i = 0;

	while (task[i] != '\0')
	{
		if (task[i] == '\n')
			break;
		i++;
	}
	task[i] = '\0';
}

/**
 *_copystring - copy the task
 *@sender: send the task
 *@reciver: recive the task
 *
 * Return: void
 */

void _copystring(char *sender, char *reciver)
{
	int i = 0;

	for (; sender[i] != '\0'; i++)
		reciver[i] = sender[i];
	reciver[i] = '\0';
}

/**
 *_lengthstr - length of task
 *@task: calculat the task
 *
 * Return: length value
 */

int _lengthstr(char *task)
{
	int len = 0;

	if (task == NULL)
		return (len);
	for (; task[len] != '\0'; len++)
		;
	return (len);
}
