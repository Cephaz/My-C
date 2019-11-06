/*
** ETNA PROJECT, 11/10/2019 by zhou_p
** my_list.h
** File description:
**      Code is poetry..
*/

#ifndef MY_LIST_H
# define MY_LIST_H

typedef struct chaine_list
{
    int key;
    char *value;
    struct chaine_list *ap;
    struct chaine_list *av;
} chaine_list_t;

#endif
