#include <stdlib.h>
#include <unistd.h>

void	fuck(char *src)
{
	char	*ptr = malloc(2049);
	int		depth;
	int		i;

	i = 0;
	while (i < 2049)
		ptr[i++] = '\0';
	i = 0;
	while (src[i])
	{
		if (src[i] == '>')
			++ptr;
		else if (src[i] == '<')
			--ptr;
		else if (src[i] == '+')
			*ptr += 1;
		else if (src[i] == '-')
			*ptr -= 1;
		else if (src[i] == '.')
			write(1, ptr, 1);
		else if (src[i] == '[' && !*ptr)
		{
			depth = 1;
			while (depth)
			{
				++i;
				src[i] == '[' ? ++depth : depth;
				src[i] == ']' ? --depth : depth;
			}
		}
		else if (*src == ']' && *ptr)
		{
			depth = 1;
			while (depth)
			{
				--i;
				src[i] == '[' ? --depth : depth;
				src[i] == ']' ? ++depth : depth;
			}
		}
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fuck(argv[1]);
	write(1, "\n", 1);
	return (0);
}
