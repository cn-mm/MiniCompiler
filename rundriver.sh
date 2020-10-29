#!/bin/sh
gcc -c g.c
gcc -c tok.c
gcc -c tree.c
gcc -c stack.c
gcc -c parse.c
gcc -c driver.c
gcc -o fin driver.c parse.c g.c tok.c tree.c stack.c
./fin

