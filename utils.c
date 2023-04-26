#include "main.h"

/**
 * convert_size_number - Cqwdwqdwqd
 * @num: Nuqwdwqdwq
 * @size: Nqwdwqdwqd
 * Return: Cqwdqwdwqdqwd
 */

long int convert_size_number(long int num, int size)
{
	if (size == 2)
		return (num);
	else if (size == 1)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Caqwdqwdwqde
 * @num: qwdwqd
 * @size: Nuqwdqwdwqd
 * Return: Cdwqdwqd
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == 2)
		return (num);
	else if (size == 1)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * is_printable - Evaqwdwqdwqdle
 * @c: Chqwdwqdwqded.
 * Return: 1qwdqwdwqdwqe
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * apxcode - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */

int apxcode(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * isdigox - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int isdigox(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
