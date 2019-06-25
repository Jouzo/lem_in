#include "includes/lem_in.h"

// static char	*formatted_ouput(char *vertex, int ant, int add)
// {
// 	char *s;
// 	int size;

// 	size = ft_sizeofint(ant);
// 	if (!(s = (char*)malloc(sizeof(char) * (size + ft_strlen(vertex)) + 3 + add)))
// 		return (NULL);
// 	if (add)
// 		s[0] = ' ';
// 	s[size + ft_strlen(vertex) + 3 + add] = 0;
// 	s[0 + add] = 'L';
// 	ft_strcat(s, ft_itoa(ant));
// 	s[size + 1 + add] = '-';
// 	ft_strcat(s, vertex);
// 	return (s);
// }

// // void	print_final(char **vertices, int ant, int i)
// // {
// // 		printf("%s\n", formatted_ouput(vertices[i], ant));
// // }

// void		print_flow2(t_flow *head)
// {
// 	t_flow *current;

// 	current = head;
// 	printf("inside printf flow\n");
// 	while (current != NULL)
// 	{
		
// 		printf("\n-------\n");
// 		print_path(current->path);
// 		current = current->next;
// 	}
// }

void		print_map(char *s)
{
	int		i;
	char	*one;
	char	*two;
	char	*three;
	int		size;

	size = ft_sqrt(ft_strlen(s));
	one = "\x1B[31m1 \033[0m";
	two = "\x1B[32m2 \033[0m";
	three = "\x1B[34m3 \033[0m";
	i = 0;
	while (i < size * size)
	{
		if (s[i] == '1')
			write(1, one, ft_strlen(one));
		else if (s[i] == '2')
			write(1, two, ft_strlen(one));
		else if (s[i] == '3')
			write(1, three, ft_strlen(one));
		else
			write(1, "0 ", 2);
		if ((i + 1) % size == 0)
			write(1, "\n", 1);
		i++;
	}
}

// void		print_output(char *map, char **vertices, t_flow *flow, int ants)
// {
// 	int i;
// 	int j;
// 	int end;
// 	int paths;
// 	char *print;
// 	t_flow *head;

// 	print = NULL;
// 	paths = number_of_path(flow);
// 	i = 0;
// 	end = 0;
// 	while (i < ants)
// 	{
// 		head = flow;
// 		j = end;
// 		while (j < i)
// 		{
// 			if (!print)
// 				print = ft_strdup(formatted_output(head->path->vertex, i, 0));
// 			else
// 				print = ft_strjoin(print, formatted_output(head->path->vertex, i, 1))
// 		}
// 		i++;
// 		printf("%s\n", print);
// 	}
// }