/*
** ETNA PROJECT, 09/10/2019 by zhou_p
** my_show_params_array.c
** File description:
**      Code is poetry..
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_struct.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static void my_putstr(const char *str)
{
    while (*str) {
        my_putchar(*str);
        ++str;
    }
}

void my_putnbr(int n)
{
    if (-2147483648 == n) {
        my_putchar('-');
        my_putchar('2');
        n = 147483648;
        my_putnbr(n);
    } else {
        if (n < 0) {
            my_putchar('-');
            n = n * -1;
        }
        if (n >= 10) {
            my_putnbr(n / 10);
        }
        my_putchar(n % 10 + '0');
    }
}

static int alphanumeric(char c)
{
    if ((c > 47 &&  c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
        return (1);
    return (0);
}

static int nbrm(char *str)
{
    int mot = 0;
    int i = 0;
    int nbrm = 0;

    while (str[i]) {
        if (mot == 0 && alphanumeric(str[i]) == 1) {
            mot = 1;
            ++nbrm;
        }
        if (mot == 1 && alphanumeric(str[i]) == 0)
            mot = 0;
        ++i;
    }
    return (nbrm);
}

static void my_copyopti(char *dest, char *str, int deb, int fin)
{
    int i = 0;

    while (deb < fin + 1) {
        dest[i] = str[deb];
        ++deb;
        ++i;
    }
    dest[i] = '\0';
}

static void my_savmot(char **tab, char *str, int nbrm)
{
    int i = 0;
    int deb = 0;
    int motcpt = 0;

    while (motcpt < nbrm) {
        while (str[i] && alphanumeric(str[i]) == 0)
            i = i + 1;
        deb = i;
        while (str[i] && alphanumeric(str[i]) == 1)
            i = i + 1;
        tab[motcpt] = (char*)malloc(sizeof(char) * ((i - 1) - deb + 2));
        my_copyopti(tab[motcpt], str, deb, i - 1);
        ++i;
        ++motcpt;
    }
}

static char **my_str_to_word_array(char *str)
{
    int nbrmm = nbrm(str);
    char **tab = (char**)malloc(sizeof(char*) * (nbrmm + 1));

    my_savmot(tab, str, nbrmm);
    tab[nbrmm] = NULL;
    return (tab);
}

void my_show_params_array(const struct info_param *par)
{
    int i = 1;
    int j = 0;
    char **tab;

    while (par[i].str) {
        my_putstr("str=\"");
        my_putstr(par[i].str);
        my_putstr("\" | size=[");
        my_putnbr(par[i].length);
        my_putstr("] | words=[\'");
        j = -1;
        while (par[i].word_array[++j]) {
            tab = my_str_to_word_array(par[i].word_array[j]);
            my_putstr(tab[0]);
            if (par[i].word_array[j+1] != NULL)
                my_putstr("\', \'");
        }
        my_putstr("\']\n");
        ++i;
    }
}
