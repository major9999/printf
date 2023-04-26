#include "main.h"

/**
 * printchsw - qwdwefer dgerdgrefg.
 * @types: werrger gregwdqwdwqd.
 * @buffer: rfgredfgw edfwqadwqad.
 * @flags:  ergre gref asddfsa.
 * @width: Widwwq dqwdqdeqwdth.
 * @precision: Prtghrtf dgdsfsawaqsdwqad.
 * @size: dfgdfg wqdwq adfzsxdfsf.
 * Return: wqadqo ia qshdu iwqadhuwiqd.
 */

int printchsw(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (writmychar(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prlqkwdkljwqndqwdng
 * @types: Llkqwndjkionwqdwqds
 * @buffer: kiowqudhuijnqwgegnt
 * @flags:  Clqkwdjmoiqlwdoiwqdgs
 * @width: polqwdjioqwdjwqd
 * @precision: Precipo0qowdjoidwqon
 * @size: Slikoqwdiujwqder
 * Return: Nuqolpiwdjiuowqdjwq
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNWATEDX(buffer);
	UNWATEDX(flags);
	UNWATEDX(width);
	UNWATEDX(precision);
	UNWATEDX(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & 1)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * priperc - oqiwdjiouqwdjwqd
 * @types: Lrtjhrtghtgergents
 * @buffer: Bufqwdqgrtfhettetrg
 * @flags:  tyjtrgdsfsfrdfds
 * @width: grthfsadfsfewrdgh.
 * @precision: Pwqdwegrehtrhjon
 * @size: Siqwdqwfreherthr
 * Return: Nuqwdwgrehertjhrh
 */

int priperc(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	UNWATEDX(types);
	UNWATEDX(buffer);
	UNWATEDX(flags);
	UNWATEDX(width);
	UNWATEDX(precision);
	UNWATEDX(size);

	return (write(1, "%%", 1));

}

/**
 * print_int - Pwqtgewhgreh
 * @types: Liwrhtrehfdsgv
 * @buffer: Bujrwqdwqfrefherint
 * @flags:  Cqwdqwferhrthjwqedf
 * @width: get width.
 * @precision: Precqwdwegrehertjhion
 * @size: Swdwqferhrtehjer
 * Return: Nutrjhewfddqwqwed
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_fmnw(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prireholqiwduijnwer
 * @types: Liqwdqfgrehrtjhnts
 * @buffer: Buftrhjdfwqdfwqnt
 * @flags:  Caltrehwqdwqds
 * @width: gqwdqwdfrhrehh.
 * @precision: Prqwdwegertherhwqdon
 * @size: Sqwedqwferhrthjther
 * Return: Nqwdwq wqdwqwqgreher.
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int a[32];
	unsigned int n, m, i, sum;
	int count;

	UNWATEDX(buffer);
	UNWATEDX(flags);
	UNWATEDX(width);
	UNWATEDX(precision);
	UNWATEDX(size);

	m = 2147483648;
	n = va_arg(types, unsigned int);

	a[0] = n / m;

	for (i = 1; i < 32; i++)

	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (i = 0, sum = 0, count = 0; i < 32; i++)

	{
		sum += a[i];
		if (sum || i == 31)

		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
