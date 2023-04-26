#include "main.h"

/**
 * printptr - Pwefgerggrthgtrfgsadsadle
 * @types: Lrthawedwqadwqefewts
 * @buffer: Burthrtgwasdwqadwqad
 * @flags:  hrthwdwqdqwdqwds
 * @width: trhrthwdqqwdth
 * @precision: Pqwdqwdqwdon
 * @size: yhjrfdsfdsgfier
 * Return: qwdqwdqoidhjiouwq.
 */

int printptr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNWATEDX(width);
	UNWATEDX(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNWATEDX(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & 4) && !(flags & 1))
		padd = '0';
	if (flags & 2)
		extra_c = '+', length++;
	else if (flags & 16)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (writefmpotrr(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * thenonprin - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int thenonprin(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNWATEDX(flags);
	UNWATEDX(width);
	UNWATEDX(precision);
	UNWATEDX(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += apxcode(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * wdwoqwd_rev - Ptrhgrthtsewdfewsfwef
 * @types: Lrthrtghawdawdwaqd
 * @buffer: Burthgrtefadasdsad
 * @flags: rawqdwqdqwdwqd
 * @width: gtrhsadsadwqadwqf
 * @precision: Prerthtrhgadfadf
 * @size: qwdqwdrfghtrhgr
 * Return: Nutreherfasdfsadfsdf
 */

int wdwoqwd_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNWATEDX(buffer);
	UNWATEDX(flags);
	UNWATEDX(width);
	UNWATEDX(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNWATEDX(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * prmyrot13 - Prrehregwdwqdqwdqwdqw.
 * @types: Lierhtrtehsadasdwqds
 * @buffer: Buerhergsadfsadfwerfewft
 * @flags:  Cqwdqwdregrthrtgwed
 * @width: rtgfdewfergrtegwdewq
 * @precision: Prewegtergredgasd
 * @size: Sthrthgsdfsfdsr
 * Return: Numqwfergrthtrjhwded
 */

int prmyrot13(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNWATEDX(buffer);
	UNWATEDX(flags);
	UNWATEDX(width);
	UNWATEDX(precision);
	UNWATEDX(size);

	if (str == NULL)
	{
		str = "(AHYY)";
	}

	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
