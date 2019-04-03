#include <stdlib.h>

char	*create_str(char *src, int negative, int base, int size)
{
	char	chrs[] = "0123456789ABCDEF";
	char	*res;
	int		i;

	size += (negative && base == 10);
	if (!(res = malloc(size + 1)))
		return (NULL);
	res[size] = '\0';
	i = (negative && base == 10);
	while (i < size)
	{
		res[i] = chrs[src[size - i - 1] - '0'];
		++i;
	}
	if (negative && base == 10)
		res[0] = '-';
	return (res);
}

char	*ft_itoa_base(int value, int base)
{
	char	buf[33];
	int		negative;
	int		size;

	negative = (value >= 0 ? 0 : 1);
	if (!value)
	{
		buf[0] = '0';
		size = 1;
	}
	else
	{
		size = 0;
		while (value)
		{
			buf[size] = (negative ? -1 : 1) * (value % base) + '0';
			value /= base;
			++size;
		}
	}
	buf[size] = '\0';
	return (create_str(buf, negative, base, size));
}
