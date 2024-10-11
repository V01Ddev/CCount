#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include "BigMoney-nw.c"


void clear_display(char out[art_height][art_width]){
    for (int i=0; i < art_height; i++) {
        for (int j=0; j < art_width; j++){
            out[i][j] = ' ';
        }
    }
}

void ascii_cpy(char out[art_height][art_width], char ascii_1[8][12], char ascii_2[8][12]){
    for (int i=0; i < art_height; i++){
        strcpy(out[i], ascii_1[i]);
        strcat(out[i], ascii_2[i]);
    }
}

void ascii_cat(char out[art_height][art_width], char ascii_in[8][12]){
    for (int i=0; i < art_height; i++){
        strcat(out[i], ascii_in[i]);
    }

}

void print_time(WINDOW* win, char* ascii_time[]){
    int width = sizeof(ascii_time[0]);
    int rows = sizeof(&ascii_time) / 8;
    int max_y = getmaxy(win);
    int max_x = getmaxx(win);
    
    int mid_y = max_y / 2;
    int mid_x = max_x / 2;

    int y = mid_y - width/2;
    int x = mid_x - rows/2;

    for (int i=0; i < rows; i++){
        mvprintw(y, x, "%s\n", ascii_time[i]);
        y++;
    }
}

int main() {

    /*
    WINDOW* win = initscr();
    refresh();
    */

    // print_time(win, one);

    char display[art_height][art_width];

    ascii_cat(display, one);
    ascii_cat(display, two);

    for (int i=0; i<art_height; i++){
        printf("%s\n", display[i]);
    }

    /*
    getch();
    endwin();
    */
    return 0;
}
