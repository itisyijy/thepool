#include <unistd.h>

int duplicate(char c, char *str, int index)
{
	int	i;

	i = 0;
	if (index == -1)
	{
		while (str[i] != '\0')
		{
			if (str[i] == c)
				return (1);
			i++;
		}
		return (0);
	}
	while (i < index)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int	i;
	int	j;
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (duplicate(argv[1][i], argv[1], i) == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
		j = 0;
		while (argv[2][j] != '\0')
		{
			if (duplicate(argv[2][j], argv[1], -1) == 0)
				if (duplicate(argv[2][j], argv[2], j) == 0)
					write(1, &argv[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}
