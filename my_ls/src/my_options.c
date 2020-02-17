/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** my_options.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

int cptopt(opt_t *opt)
{
    int cpt = 0;

    cpt += (opt->neg == 1) ? 1 : 0;
    cpt += (opt->l == 1) ? 1 : 0;
    cpt += (opt->R == 1) ? 1 : 0;
    cpt += (opt->r == 1) ? 1 : 0;
    cpt += (opt->d == 1) ? 1 : 0;
    cpt += (opt->t == 1) ? 1 : 0;
    cpt += (opt->a == 1) ? 1 : 0;
    cpt += (opt->A == 1) ? 1 : 0;
    cpt += (opt->L == 1) ? 1 : 0;
    return (cpt);
}

opt_t *newopt()
{
    opt_t *opt = NULL;

    opt = malloc(sizeof(*opt));
    if (opt == NULL)
        return NULL;
    opt->neg = 0;
    opt->l = 0;
    opt->R = 0;
    opt->r = 0;
    opt->d = 0;
    opt->t = 0;
    opt->a = 0;
    opt->A = 0;
    opt->L = 0;
    return (opt);
}

int nopt(opt_t *opt)
{
    int nopt = 0;

    if ((opt->neg == 1) || (opt->l == 1) || (opt->R == 1)
        || (opt->r == 1) || (opt->d == 1) || (opt->t == 1)
        || (opt->a == 1) || (opt->A == 1) || (opt->L == 1))
            nopt = 1;
    return (nopt);
}

void addopt(opt_t *opt, char c)
{
    opt->neg = (c == '1') ? 1 : opt->neg;
    opt->l = (c == 'l') ? 1 : opt->l;
    opt->R = (c == 'R') ? 1 : opt->R;
    opt->r = (c == 'r') ? 1 : opt->r;
    opt->d = (c == 'd') ? 1 : opt->d;
    opt->t = (c == 't') ? 1 : opt->t;
    opt->a = (c == 'a') ? 1 : opt->a;
    opt->A = (c == 'A') ? 1 : opt->A;
    opt->L = (c == 'L') ? 1 : opt->L;
}

opt_t *verif_options(int ac, char **av){
    opt_t *opt = newopt();
    int i = 0;

    while (i < ac) {
        if (av[i][0] == '-')
            if (my_strlen(av[i]) >= 2) {
                print_option_errors(av[i][1]);
                addopt(opt, av[i][1]);
                if (opt->l == 1)
                    opt->neg = 0;
            }
        ++i;
    }
    return (opt);
}