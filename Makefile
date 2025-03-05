
install:
	clang -std=c99 -s ccount.c -o ccount -lncurses

dev:
	clang -std=c99 -g -Wall -Werror ccount.c -o ccount -lncurses

