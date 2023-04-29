#include "main.h"

/**
 * print_unprintable - oiqwdjioqwdjoiwqdjwq.
 * @s: ioujjdhuijndiuwqnd.
 * Return: oiqjdwiowqiodjqwiod.
 */
unsigned int print_unprintable(char *s)
{
	unsigned int i, printed_char = 0;

	if (s == NULL)
	{
		return (print_string("(null)"));
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] > 0  && s[i] < 32) || s[i] >= 127)
		{
			print_string("\\x");
			if (s[i] < 15)
				print_string("0");

			printed_char += print_hexadecimal(s[i], 'A');
		}
		else
		{
			_putchar(s[i]);
			printed_char++;
		}
	}
	return (printed_char);
}

/**
 * premyintwqi - qpiowdjioqwodiqwidjwqdoi.
 * @ooqiw: trhrgewfwqedqwdqw.
 * Return: nopqwodiqwdqwdwqdqwrthgrtehg.
 */

unsigned int premyintwqi(int ooqiw)
{
	unsigned int i = 0, printed_char = 0, n;
	char *digits = (char *)malloc(sizeof(char));

	if (digits == NULL)
		return (-1);

	if (ooqiw < 0)
	{
		_putchar('-');
		printed_char++;
		n = ooqiw * (-1);
	}
	else
		n = ooqiw;
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		digits[i++] = n % 10 + '0';
		digits = (char *)_realloc(digits, i, i + 1);
		n = n / 10;
	}
	while (i > 0)
	{
		_putchar(digits[--i]);
		printed_char++;
	}
	free(digits);
	return (printed_char);
}

/**
 * print_string - oiqwdjiowqidojwaq.
 * @s: qwdqwpiodjqwiodjoiqwd
 * Return: nbr of char printed
 */

unsigned int print_string(char *s)
{
	unsigned int i, printed_char = 0;

	if (s == NULL)
	{
		return (print_string("(null)"));
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		printed_char++;
	}

	return (printed_char);
}

/**
 * print_base - pqowdjoiqwdoijwqd.
 * @n: oqjdwiwqdiojwq.
 * @base: kijuqwduiwqd.
 * Return: oiqdwjiowqd.
 */

unsigned int print_base(unsigned int n, int base)
{
	unsigned int i = 0, printed_char = 0;
	char *digits = (char *)malloc(sizeof(char));

	if (digits == NULL)
		return (-1);
	if (n == 0)
	{
		_putchar('0');
		printed_char++;
	}
	while (n > 0)
	{
		digits[i++] = n % base + '0';
		digits = (char *)_realloc(digits, i, i + 1);
		n = n / base;
	}
	while (i > 0)
	{
		_putchar(digits[--i]);
		printed_char++;
	}
	free(digits);
	return (printed_char);
}

/**
 * print_hexadecimal - oiqhdiuqwdiuhdiwqud.
 * @n: iojqdiuojdwioqdwjiwqd.
 * @a: oiqjdwiodwqiojdoqwd.
 * Return: oiqdjioqdwoijdw.
 */

unsigned int print_hexadecimal(unsigned int n, int a)
{
	unsigned int i = 0, printed_char = 0;
	char *digits = (char *)malloc(sizeof(char));

	if (digits == NULL)
		return (-1);
	if (n == 0)
	{
		_putchar('0');
		printed_char++;
	}
	while (n > 0)
	{
		if (n % 16 < 10)
			digits[i++] = n % 16 + '0';
		else
		{
			digits[i++] = (n % 16) - 10   + a;
		}
		digits = (char *)_realloc(digits, i, i + 1);
		n = n / 16;
	}
	while (i > 0)
	{
		_putchar(digits[--i]);
		printed_char++;
	}
	free(digits);
	return (printed_char);
}

