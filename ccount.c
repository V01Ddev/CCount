#include <stdio.h>
#include <ncurses.h>
#include "BigMoney-nw.c"

/*
Rewrite ascii_stycpy to manually write to output array.
An ascii_strcpy function shouldn't be used, instead an ascii_insert function can insert characters where needed.
*/


void ascii_strcpy(char out[][display_length], char ascii_in[][art_length]){
    for (int i=0; i<=art_height; i++){
        for (int j=0; j<art_length; j++){ // < and not <= to exclude the return char
            out[i][j] = ascii_in[i][j];
        }
    }
}


void print_time(WINDOW* win, char ascii_time[][display_length]){

    int width = art_length;
    int rows = art_height;

    // Size of the screen
    // int max_y = getmaxy(win);
    // int max_x = getmaxx(win);
    int max_y = 100;
    int max_x = 100;
    
    // Adjusting for string to be centered.
    int mid_y = max_y / 2;
    int mid_x = max_x / 2;
    int y = mid_y - width / 2;
    int x = mid_x - rows / 2;

    for (int i=0; i < art_height; i++){
        mvprintw(y, x, "%s", ascii_time[i]);
        // printf("%s\n", ascii_time[i]);
        y++;
    }
}

int main() {

    WINDOW* win = initscr();
    refresh();

    char display[art_height][display_length];

    ascii_strcpy(display, one);
    print_time(win, display);

    ascii_strcpy(display, two);
    print_time(win, display);

    getch(); // Keeps window alive.
    endwin();
    return 0;
}
