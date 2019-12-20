/*
** ETNA PROJECT, 03/10/2019 by zhou_p
** my_sort_params.c
** File description:
**      project_description
*/

#include <unistd.h>

my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i])) {
		++i;
	}
	if (s1[i] != s2[i]) {
		return (s1[i] - s2[i]);
	}
	return (0);
}

void doubletab(char **tab, int x)
{
    int i = -1;
    int j = -1;
    
    while (++i < x) {
        j = -1;
        while (tab[i][++j])
            my_putchar(tab[i][j]);
    }
}

char **my_sort_params(int ac, char **av)
{
	int i = -1;
	int j = -1;
	char *tmp;

	while (++i < ac) {
		j = i + 1;
		while (++j < ac)
		.   if (0 < (my_strcmp(av[i], av[j]))) {
			    tmp = av[i];
		    	av[i] = av[j];
		    	av[j] = tmp;
	.   	}
		}
	}
	return (dest);
}

int main(int argc, char **argv)
{
	char **str = my_sort_params(argc, argv);

	doubletab(str, argc);
	free(str);
	return (0);
}
