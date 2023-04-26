#include "main.h"

/**
 * priusig - joiqndwiuwqdiuqwd
 * @types: Lergergdqwqwds
 * @buffer: Btrherfwqedwq
 * @flags:  Crgregreffwqedf
 * @width: qwdqwdqwdrhgrth
 * @precision: ewgrtehgrtgadasd
 * @size: ergwefwqedwqd
 * Return: Nuwqdqwdqwdqw
 */

int priusig(va_list types, char buffer[],
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
 * primooctr - wqdwegrthrhnrtsadfadf
 * @types: hsadfadwqfwetgfw
 * @buffer: ertqdqwdqwerhrth
 * @flags:  rthrtghaswdwaqd
 * @width: wqdewefgerhgrth
 * @precision: qwdwqefredghrthn
 * @size: Sdewfergrtehgrethg
 * Return: Nqwdfregtrehgerr
 */

int primooctr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNWATEDX(width);

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
 * prhexmodec - rhgergsadwqdwqdfdgfgn
 * @types: Lqwdfrfgrthtrwerdwsf
 * @buffer: Bqwdwqfdeghergergt
 * @flags:  Crgrthgsadfasdwqdfqwrf
 * @width: erhgtrhgsaxdfsfdqwer
 * @precision: egerthgghxvdsfewf
 * @size: qwdwqegtrhrthjwqdr
 * Return: erhgrthasdfsadadd
 */

int prhexmodec(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (prehexo(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * myhhqwdupper - Phtrghewfwqdwqdsadasdn
 * @types: Lisqwdqwwqdqwqw gqwd
 * @buffer: qwwewwqdqwdwq d qwdwqdqdrfqwe
 * @flags:  ergregasdwqdqwhgerth
 * @width: qwdwgrrtehtrgwedf
 * @precision: Pewfgerghregwerwqn
 * @size: rthtrfswfewfewrf
 * Return: wqderwgrtefhrthdqwd
 */

int myhhqwdupper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (prehexo(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * prehexo - Prherfsafdasdferwhgrfhdsdfrr
 * @types: Lqwfrfherhasddqwf
 * @map_to: trhfsdafqwefewwrh
 * @buffer: Bwehrtehsdfdfewgfegtwe
 * @flags:  Cqwdgrthtawqsdsaffs
 * @flag_ch: Cqwdthrthsadwdqtgs
 * @width: gtrhefdasdfwqdwqgergh
 * @precision: Ptrhjnrtgdsafwdqwn
 * @size: Sqwdwegrthytrhsadfadfwqdr
 * @size: trhrthdsfsfwqedfwegf
 * Return: Nqwdwqfrehrtjh
 */

int prehexo(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	unsigned long int num = va_arg(types, unsigned long int);
	int i = BUFF_SIZE - 2;
	unsigned long int init_num = num;

	UNWATEDX(width);
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
