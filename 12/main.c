/*
** ETNA PROJECT, 11/10/2019 by zhou_p
** main.c
** File description:
**      Code is poetry..
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/my_list.h"

//RECUPERE LA VALUE
char *my_getvalue(char *lachaine)
{
	int i = 0;
	int j = 0;
	int pos;
	char *result;

	while (lachaine[i] != ' ')
		++i;
	while (lachaine[i] == ' ')
		++i;
	j = my_strlen(&lachaine[i]);
	result = malloc(sizeof(char) * j);
	result = my_strcpy(result, &lachaine[i]);
	my_putstr(result);
	return (result);
}
//VERIFICATION DE VALUE OU PAS
int intouchar(char *lachaine)
{
	int i = 0;

	while (lachaine[i]) {
		while (lachaine[i] == ' ') {
			++i;
			if (lachaine[i] != ' ')
				return (1);
		}
		++i;
	}
	return (0);
}
//VERIFIE SI KEY EXISTE DANS LA STRUCT
int existekey(chaine_list_t *chaine, int keyy)
{
	while (chaine != NULL) {
		if (chaine->key == keyy)
			return (1);
		chaine = chaine->ap;
	}
	return (0);
}
//AFFICHAGE DE KEY
void affichage(int keyy, chaine_list_t *chaine, int choix)
{
	if (chaine == NULL) {
		my_putstr("-1\n");
		return ;
	}
	while (chaine->ap != NULL)
		chaine = chaine->ap;
	if (chaine->av != NULL) {
		while (chaine != NULL) {
			if (keyy == chaine->key) {
				if (choix == 1)
					my_putstr(chaine->value);
				if (choix == 2)
					my_putnbr(chaine->key);
				my_putchar('\n');
			}
			chaine = chaine->av;
		}
	} else
		my_putstr("-1\n");
}
//VALUE Delete ou pas
int dorint(char *value)
{
	int i = 0;

	if(value[i] == 'D')
		return (1);
	return(0);
}
//DELETE STRUC KEY
chaine_list_t *deletestruc(chaine_list_t *chaine, int keyy)
{
	chaine_list_t *newchaine = chaine;
	while (newchaine->ap != NULL)
		newchaine = newchaine->ap;
	while (newchaine->av != NULL) {
		if (newchaine->key == keyy) {
			if (newchaine->av != NULL)
				(newchaine->av)->ap = newchaine->ap;
			if (newchaine->ap != NULL)
				(newchaine->ap)->av = newchaine->av;
			else
				newchaine = NULL;
			return (chaine);
		}
		newchaine = newchaine->av;
	}
	return (chaine);
}
//ADDSTRUC
chaine_list_t *addtruc(chaine_list_t *chaine, int keyy, char *value)
{
	chaine_list_t *putchaine = chaine;

	putchaine->key = keyy;
	putchaine->value = value;
	putchaine->av = NULL;
	putchaine->ap = chaine;
	return (putchaine);
}
//AJOUTE OU SUPPRIME SELON VALUE 
chaine_list_t *deloradd(chaine_list_t *chaine, char *value, int keyy)
{
	int boln = dorint(value);

	if (boln == 1) {
		affichage(keyy, chaine, 1);
		if (existekey(chaine, keyy) == 1)
			chaine = deletestruc(chaine, keyy);
	} else {
		chaine = addtruc(chaine, keyy, value);
		affichage(keyy, chaine, 2);
	}
	return (chaine);
}
//RECUPERE KEY ET VALUE/ AFFICHE KEY /ou ADD DELETE
chaine_list_t *my_verifie(char *lachaine, chaine_list_t *chaine)
{
	int keyy = my_getnbr(lachaine);
	int i = 0;
	char *value = 0;

	if (intouchar(lachaine) == 1)
		value = my_getvalue(lachaine);
	if (value == 0)
		affichage(keyy, chaine, 1);
	else {
		chaine = deloradd(chaine, value, keyy);
		affichage(keyy, chaine, 2);
	}
	return (chaine);
}
//J ENVOIS LIGNE PAR LIGNE
int main(void)
{
	char *lachaine;
	chaine_list_t *chaine = NULL;

	while (0 != (lachaine = my_readline())) {
		chaine = my_verifie(lachaine, chaine);
	}
	return (0);
}
