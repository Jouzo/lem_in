#include <stdio.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (i < 200000000)
		{
			write(1, "yoyoyo\n", 7);
			i++;
		}
	}
	else
	{
		while (i < 200000000)
		{
			printf("yoyoyo\n");
			i++;
		}
	}
	return (0);
}
