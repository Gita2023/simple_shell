#include "shell.h"

/**
 *_stringcmp - compare two strings
 *@firststr: string number one
 *@secondstr: string number two
 *
 * Return: feedback of both string
 */

int _stringcmp(char *firststr, char *secondstr)
{
	int j = 0;

	while (firststr[j] != '\0')
	{
		if (firststr[j] != secondstr[j])
			break;
		j++;
	}
	return (firststr[j] - secondstr[j]);
}

/**
 *_stringcon - join of both string
 *@reciver: recevied srting
 *@sender:  sended string
 *
 * Return: new one of string
 */

char *_stringcon(char *reciver, char *sender)
{
	char *new_string =  NULL;
	int len_reciver = _lengthstr(reciver);
	int len_sender = _lengthstr(sender);

	new_string = malloc(sizeof(*new_string) * (len_reciver + len_sender + 1));
	_copystring(reciver, new_string);
	_copystring(sender, new_string + len_reciver);
	new_string[len_reciver + len_sender] = '\0';
	return (new_string);
}

/**
 *_stringpre - primary string 
 *@string1: string number one
 *@string2: string number two
 *
 *Return: size of the string been generated
 */

int _stringpre(char *string1, char *string2)
{
	int j = 0;
	int like = 0;

	while (string1[j] != '\0')
	{
		if (_stringloc(string2, string1[j]) == NULL)
			break;
		like++;
		j++;
	}
	return (like);
}

/**
 *_stringcom - calculate the size of strings
 *@string1: string number one
 *@string2: string number two
 *
 *Return: location of both value
 */

int _stringcom(char *string1, char *string2)
{
	int var = 0, j;

	for (j = 0; string1[j] != '\0'; j++)
	{
		if (_stringloc(string2, string1[j]) != NULL)
			break;
		var++;
	}
	return (var);
}

/**
 *_stringloc - locates a char in a string
 *@s: string to be searched
 *@c: char to be checked
 *
 *Return: pointer to the firststr occurence of c in s
 */

char *_stringloc(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

/**
 *_string_tokr - outhrized task
 *@string: task to be done
 *@diffr: differnet task to authenticated
 *@poniter: track the authentication
 *
 *Return: allowded access to do task
 */
char *_string_tokr(char *string, char *diffr, char **poniter)
{
	char *last;

	if (string == NULL)
		string = *poniter;

	if (*string == '\0')
	{
		*poniter = string;
		return (NULL);
	}

	string += _stringpre(string, diffr);
	if (*string == '\0')
	{
		*poniter = string;
		return (NULL);
	}

	last = string + _stringcom(string, diffr);
	if (*last == '\0')
	{
		*poniter = last;
		return (string);
	}

	*last = '\0';
	*poniter = last + 1;
	return (string);
}

/**
 * _stringint - change integer of task
 * @done: change be done
 *
 * Return: changed integer
 */
int _stringint(char *done)
{
	unsigned int n = 0;

	do {
		if (*done == '-')
			return (-1);
		else if ((*done < '0' || *done > '9') && *done != '\0')
			return (-1);
		else if (*done >= '0'  && *done <= '9')
			n = (n * 10) + (*done - '0');
		else if (n > 0)
			break;
	} while (*done++);
	return (n);
}

/**
 * _factloc - generate space for location
 * @loc: link to free space
 * @old_one: valuome of space linked
 * @new_one: valuome of space linked to it
 *
 * Return: location of free space
 */
void *_factloc(void *loc, unsigned int old_one, unsigned int new_one)
{
	void *loc_space;
	unsigned int i;

	if (loc == NULL)
	{
		loc_space = malloc(new_one);
		return (loc_space);
	}
	else if (new_one == old_one)
		return (loc);
	else if (new_one == 0 && loc != NULL)
	{
		free(loc);
		return (NULL);
	}
	else
	{
		loc_space = malloc(new_one);
		if (loc_space != NULL)
		{
			for (i = 0; i < min(old_one, new_one); i++)
				*((char *)loc_space + i) = *((char *)loc + i);
			free(loc);
			return (loc_space);
		}
		else
			return (NULL);

	}
}

/**
 * control_c - input task
 * @entnum: enter number 
 *
 * Return: void
 */
void control_c(int entnum)
{
	if (entnum == SIGINT)
		output("\n($) ", STDIN_FILENO);
}

/**
 * delete_comment - delete anythings
 * @inputvalue: inputvalue to be used
 *
 * Return: void
 */
void delete_comment(char *inputvalue)
{
	int j = 0;

	if (inputvalue[j] == '#')
		inputvalue[j] = '\0';
	while (inputvalue[j] != '\0')
	{
		if (inputvalue[j] == '#' && inputvalue[j - 1] == ' ')
			break;
		j++;
	}
	inputvalue[j] = '\0';
}
