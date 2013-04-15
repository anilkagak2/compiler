#! /usr/bin/sh
bison -vd sub_c.y
flex sub_c.l
gcc lex.yy.c sub_c.tab.c -o p
