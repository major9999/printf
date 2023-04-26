#include "main.h"

/**
 * print_unsigned - joiqndwiuwqdiuqwd
 * @types: Lergergdqwqwds
 * @buffer: Btrherfwqedwq
 * @flags:  Crgregreffwqedf
 * @width: qwdqwdqwdrhgrth
 * @precision: ewgrtehgrtgadasd
 * @size: ergwefwqedwqd
 * Return: Nuwqdqwdqwdqw
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (wkwdkq(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - wqdwegrthrhnrtsadfadf
 * @types: hsadfadwqfwetgfw
 * @buffer: ertqdqwdqwerhrth
 * @flags:  rthrtghaswdwaqd
 * @width: wqdewefgerhgrth
 * @precision: qwdwqefredghrthn
 * @size: Sdewfergrtehgrethg
 * Return: Nqwdfregtrehgerr
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & 8 && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (wkwdkq(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - rhgergsadwqdwqdfdgfgn
 * @types: Lqwdfrfgrthtrwerdwsf
 * @buffer: Bqwdwqfdeghergergt
 * @flags:  Crgrthgsadfasdwqdfqwrf
 * @width: erhgtrhgsaxdfsfdqwer
 * @precision: egerthgghxvdsfewf
 * @size: qwdwqegtrhrthjwqdr
 * Return: erhgrthasdfsadadd
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Phtrghewfwqdwqdsadasdn
 * @types: Lisqwdqwwqdqwqw gqwd
 * @buffer: qwwewwqdqwdwq d qwdwqdqdrfqwe
 * @flags:  ergregasdwqdqwhgerth
 * @width: qwdwgrrtehtrgwedf
 * @precision: Pewfgerghregwerwqn
 * @size: rthtrfswfewfewrf
 * Return: wqderwgrtefhrthdqwd
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prherfsafdasdferwhgrfhdsdfrr
 * @types: Lqwfrfherhasddqwf
 * @map_to: trhfsdafqwefewwrh
 * @buffer: Bwehrtehsdfdfewgfegtwe
 * @flags:  Cqwdgrthtawqsdsaffs
 * @flag_ch: Cqwdthrthsadwdqtgs
 * @width: gtrhefdasdfwqdwqgergh
 * @precision: Ptrhjnrtgdsafwdqwn
 * @size: Sqwdwegrthytrhsadfadfwqdr
 * @size: trhrthdsfsfwqedfwegf
 * Return: Nqwdwqfrehrthjh
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	unsigned long int num = va_arg(types, unsigned long int);
	int i = BUFF_SIZE - 2;
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)

	{
		buffer[i--] = '0';
	}


	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)

	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & 8 && init_num != 0)

	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (wkwdkq(0, i, buffer, flags, width, precision, size));
}
