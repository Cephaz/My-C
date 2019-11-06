/*
** ETNA PROJECT, 12/10/2019 by zhou_p
** mainn.c
** File description:
**      Code is poetry..
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/my_list.h"
//BOOLEAN VAALL 0/1/2 NULL/CHAR/INT/
int vall(char *lachaine)
{
	if (lachaine[0] == 'D')
		return (1);
	if (lachaine[0] != '\0')
		return (2);
	return (0);
}
//BOOLEAN CHAINE
int boochaine(chaine_list_t *chaine)
{
	if (chaine != NULL)
		return (1);
	return (0);
}
//RENVOIE VAL
char *my_getval(char *lachaine)
{
	int i = 0;
	int j = 0;
	char *dest;

	while (lachaine[i] != ' ' && lachaine[i] != '\n' && lachaine[i])
		++i;
	while (lachaine[i] == ' ' && lachaine[i] != '\n' && lachaine[i])
		++i;
	while (lachaine[i] != ' ' && lachaine[i] && lachaine[i] != '\n') {
		++j;
		++i;
	}
	if (j == 0)
		return (NULL);
	dest = malloc(sizeof(char) * (j + 1));
	i = i - j;
	dest = my_strcpy(dest, &lachaine[i]);
	return (dest);
}
//PARCOURS CHAINE
int parcourschaine(chaine_list_t * chaine, int keyy)
{
	if (chaine == NULL)
		return (0);
	while (chaine->ap != NULL)
		chaine = chaine->ap;
	while (chaine->av != NULL) {
		if (chaine->key == keyy)
			return (1);
		chaine = chaine->av;
	}
	return (0);
}
//SUPPRIME UNE STRUCT
chaine_list_t *deletechaine(chaine_list_t *chaine, int keyy)
{
    chaine_list_t *newchaine = chaine;
	int i = 0;

	if ((parcourschaine(chaine, keyy)) == 1) {
        while (newchaine->ap != NULL) {
            if (newchaine->key == keyy) {
                if (newchaine->av != NULL)
                    (newchaine->av)->ap = newchaine->ap;
                if (newchaine->ap != NULL)
                    (newchaine->ap)->av = newchaine->av;
                if (newchaine->av == NULL && newchaine->ap == NULL)
                    newchaine = NULL;
				newchaine = chaine;
                return (newchaine);
            }
			newchaine = newchaine->ap;
		}
    }
    return (chaine);
}
//AJOUTE UNE STRUCT
chaine_list_t *addchaine(chaine_list_t *chaine, int keyy, char *valuee)
{
    chaine_list_t *putchaine;

	putchaine = malloc(sizeof(*putchaine));
	if (putchaine == 0)
		return (chaine);
    putchaine->key = keyy;
    putchaine->value = valuee;
    putchaine->av = NULL;
    putchaine->ap = chaine;
	if (chaine != NULL)
		chaine->av = putchaine;
    return (putchaine);
}
//AFFICHE KEY
void affichage(int keyy, chaine_list_t *chaine, int choix)
{
    if (chaine == NULL) {
        my_putstr("-1\n");
        return ;
    }
    while (chaine != NULL) {
        if (keyy == chaine->key) {
            if (choix == 1)
                my_putstr(chaine->value);
            if (choix == 2)
                my_putnbr(chaine->key);
            my_putchar('\n');
			return ;
        }
		chaine = chaine->ap;
	}
}
//RENVOI LA CHAINE ET FAIT TOUT LES APPELS
chaine_list_t *my_centre(char *lachaine, chaine_list_t *chaine)
{
	int key = my_getnbr(lachaine);
	char *val = my_getval(lachaine);

	if (val == NULL)
		affichage(key, chaine, 1);
	else {
		if (val[0] == 'D') {
			affichage(key, chaine, 1);
			chaine = deletechaine(chaine, key);
		}
		if (val[0] != 'D') {
			chaine = addchaine(chaine, key, val);
			affichage(key, chaine, 2);
		}
	}
	return (chaine);
}
//RECUPERATION LIGNE PAR LIGNE
int main(void)
{
	char *lachaine;
	chaine_list_t *chaine = NULL;

	while (0 != (lachaine = my_readline()))
		chaine = my_centre(lachaine, chaine);
	return (0);
}
