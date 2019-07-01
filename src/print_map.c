#include "lem_in.h"

void			print_map(char *s)
{
	int		i;
	int		size;

	size = ft_sqrt(ft_strlen(s));
	i = 0;
	ft_putchar('\n');
	write(1, "---------- LEM IN MAP ----------\n", 33);
	ft_putchar('\n');
	while (i < size * size)
	{
		if (s[i] == '1')
			write(1, "\x1B[31m1 \033[0m", 11);
		else if (s[i] == '2')
			write(1, "\x1B[32m2 \033[0m", 11);
		else
			write(1, "0 ", 2);
		if ((i + 1) % size == 0)
			write(1, "\n", 1);
		i++;
	}
	ft_putchar('\n');
}
