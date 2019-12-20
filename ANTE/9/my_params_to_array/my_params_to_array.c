/*
** ETNA PROJECT, 09/10/2019 by zhou_p
** my_params_to_array.c
** File description:
**      Code is poetry..
*/

#include <stdlib.h>
#include "my_struct.h"

int alphanumeric(char c)
{
    if ((c > 47 &&  c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
        return (1);
    return (0);
}

int nbrm(char *str)
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

char **my_str_to_word_array(char *str)
{
    int nbrmm = nbrm(str);
    char **tab = (char**)malloc(sizeof(char*) * (nbrmm + 1));

    my_savmot(tab, str, nbrmm);
    tab[nbrmm] = NULL;
    return (tab);
}

static int my_strlen(const char *str)
{
    int cpt = 0;

    while (*str != '\0') {
        ++cpt;
        ++str;
    }
    return (cpt);
}

static char *my_strdup(const char *src)
{
    char *nsrc;
    int i = 0;

    while (src[i])
        ++i;
    nsrc = (char *)malloc(sizeof(*src) * (i + 1));
    i = -1;
    while (src[++i])
        nsrc[i] = src[i];
    nsrc[i] = '\0';
    return (nsrc);
}

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *test;
    int i = 0;

    if (!(test = malloc(sizeof(struct info_param) * (ac + 1))))
        return (0);
    while (i < ac) {
        test[i].length = my_strlen(av[i]);
        test[i].str = av[i];
        test[i].copy = my_strdup(av[i]);
        test[i].word_array = my_str_to_word_array(av[i]);
        ++i;
    }
    test[i].str = 0;
    return (test);
}
