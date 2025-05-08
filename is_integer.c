#include "monty.h"

/**
 * is_integer - checks if a string is a valid number
 * @str: argument to check
 *
 * Return: 1 if integer, 0 otherwise
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
