
install:
	clang -std=c99 -Wall -Werror -fsanitize=address ccount.c -o ccount -lncurses

