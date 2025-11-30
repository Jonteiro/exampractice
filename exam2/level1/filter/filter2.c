#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

void	normaliza(char *str, char *key)
{
	int	i = 0;

	while (*str)
	{
		while (str[i] == key[i] && key[i])
			i++;
		if (key[i] == '\0')
		{
			i = 0;
			while (str[i] == key[i] && key[i])
			{
				write(1, "*", 1);
				i++;
			}
			str += i;
		}
		else
		{
			write(1, str, 1);
			str++;
		}
	}
}

void	tes(char *key)
{
	int	i;
	char c;
	static char str[INT_MAX];

	c = 0;
	while (1)
	{
		i = 0;
		while (read(0, &c, 1) > 0)
		{
			str[i++] = c;
			if (c == '\n')
				break;
		}
		str[i] = '\0';
		normaliza(str, key);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1] || !argv[1][0])
		return (1);
	tes(argv[1]);
	return (0);
}
