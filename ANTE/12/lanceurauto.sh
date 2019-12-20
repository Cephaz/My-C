#!/bin/bash
gcc -g3 mainn.c -L lib/ -lmy -o my_crd

./my_crd < commands.lst
