#!/bin/sh
gcc -c g.c
gcc -c tok.c
gcc -c tree.c
gcc -c stack.c
gcc -c parse.c
gcc -o hope parse.c g.c tok.c tree.c stack.c
./hope
