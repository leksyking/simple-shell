#include "main.h"

/**
 * _puts - prints a string
 *
 * @str: the pointer to the string to be printed
 *
 * Return: nothing
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
