#include "main.h"

/**
 * handle_write_char - qwdwqdqwdqwdqwd
 * @c: qwdwqdqwdqwdwq
 * @buffer: qwdwqdwqdwqdqwq
 * @flags:  qwdqwdqwdqwdwqd
 * @width: qwdqwdwqdqw
 * @precision: wegregredfgreg
 * @size: qwdqwdwqdqwwdqw
 * Return: qwefdwqefdewfewrsgregre.
 */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)

{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & 4)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & 1)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_fmnw - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int write_fmnw(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)

{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & 4) && !(flags & 1))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & 2)
		extra_ch = '+';
	else if (flags & 16)
		extra_ch = ' ';

	return (owowmmq(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * owowmmq - qwdwqdqwdwqadqwad
 * @ind: qwdwqdqwdqwdwq
 * @buffer: qwegerwgfredfger
 * @flags: rgrtedfgherfedf
 * @width: widerdgwqdqwdth
 * @prec: Precisqwdwqdqwdion swqdwqdwqdwqdpecifier
 * @length: Numberqwdqwdqwd leqwdwqdwqdqwngth
 * @padd: Padqwdqwdwqing qwdqwdwqdchar
 * @extra_c: Ewqdqwdwqxtraqwd chqwdqwdwqdar
 * Return: Numbedqwdr odwwqdqwdqwdf dqwprinwqdted chqwdqwdqwars.
 */

int owowmmq(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & 1 && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & 1) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & 1) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * wkwdkq - Writqwdwqdwqdes aqdumber
 * @is_negative: Numbwqdqqdwve
 * @ind: Indexdqwdwqd wdqqwdat wdwqhe buffer
 * @buffer: wqdwqdwqdwq
 * @flags: Fqwqdwqdqwwdqw
 * @width: Wqwdidtqwdh specifqwdwqdier
 * @precision: Preciswqdqwdion sqwdwqdwqdpecifier
 * @size: Size speciwqdqwdqwdwqdfier
 * Return: Numbqwdwqder of wqwdwqdritten chadrs.
 */
int wkwdkq(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & 4) && !(flags & 1))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & 1) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * writefmpotrr - Writwqdqwde a meqwdwqdwqmory aqwdwqdwqddress
 * @buffer: Arrays of chars
 * @ind: Index at efwqeqwd starts in theqwd bufqwfer
 * @length: qwdqwdeqwed
 * @width: Widtqwdwqdqwdwqd
 * @flags: Flqwdqwdwqdr
 * @padd: Chaqwdwqfdgrfghfdfding
 * @extra_c: Cerghsdaasdasdf
 * @padd_start: Iwqdwqdqwdqwdqwd
 * Return: qwdwqdwqdqwdwqds.
 */
int writefmpotrr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & 1 && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & 1) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & 1) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
