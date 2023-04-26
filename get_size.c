#include "main.h"

/**
 * getmasiz - Caqwdwqdqwdqwdqwdwqdnt.
 * @format: Foqwjdwqdqwdqwdqwdqwments.
 * @i: qwdwqdqwdqwdwqdwqd.
 * Return: nothinghfoisajdioasjd.
 */

int getmasiz(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')

	{
		size = 2;
	}

	else if (format[curr_i] == 'h')

	{
		size = 1;
	}


	if (size == 0)

	{
		*i = curr_i - 1;
	}

	else

	{
		*i = curr_i;
	}


	return (size);
}
