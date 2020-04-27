/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my.h
** File description:
**      project_description
*/

#ifndef MY_H
# define MY_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

typedef struct s_base
{
	char key;
  	void (*pf)(void *, int);
} a_base;

void my_putchar(char c);
void my_putnbr(int nb);
void my_putstr(char *str);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *str);
void my_putnbrbase(int nb, char *base);
int my_putnbrunsigned(long unsigned int nb, char *base);
int my_printf(const char *, ...);
void base_ten(void* aff, int nbr);
void base_hexm(void* aff, int nbr);
void base_hexM(void* aff, int nbr);
void base_i(void* aff, int nbr);
void base_char(void* aff, int nbr);
void base_charetoile(void* aff, int nbr);
void base_octal(void* aff, int nbr);
void base_f(float aff, int boucle, char carac);
void my_putfloat(float nbr, unsigned int p);
void my_putde(float nbr, unsigned int p, char carac);
float foa(float f);
void rondibien(long nbr, long lon);
int intsize(int nbr);
void affichagespace(int nbr);
int checki(const char *entrer, int i);
int checknbr(const char *entrer, int i);
int cpti(int i, const char *entrer);

#endif
