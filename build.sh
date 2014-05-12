gcc -c interpreter1.c interpreter2.c #y.tab.c lex.yy.c
gcc interpreter1.o interpreter2.o JaggScript.c -o JaggScript
