#!/bin/bash
## ETNA PROJECT, 05/10/2019 by zhou_p
## build.sh
## File description:
##		project_description
##

cd lib/my
gcc -c *.c
ar rc libmy.a *.o
