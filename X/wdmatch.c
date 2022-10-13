#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	flag;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		flag = 1;
		while (argv[1][i] != '\0')
		{
			while (argv[1][i] != argv[2][j] && argv[2][j] != '\0')
				j++;
			if (argv[2][j] == '\0')
			{
				flag = 0;
				break ;
			}
			i++;
		}
		if (flag == 1)
		{
			i = 0;
			while (argv[1][i])
				write(1, &argv[1][i++], 1);
		}
	}
	write(1, "\n", 1);
}
