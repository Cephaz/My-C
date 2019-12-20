/*
** ETNA PROJECT, 01/10/2019 by zhou_p
** getnbr.c
** File description:
**      Code is poetry..
*/

int    my_getnbr(const char *str)
{
    int			symb;
    long int	num;
    int			i;

    i = 0;
    symb = 1;
    num = 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            symb = symb * -1;
		++i;
    }
	while (str[i] >= '0' && str[i] <= '9') {
		num = num * 10 + (str[i] - 48);
		++i;
	}
	num = num * symb;
	if (num < -2147483648 || num > 2147483647)
		num = 0;
    return (num);
}
