#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include "BigMoney-nw.c"


void asciicpy(char out[][display_length], char ascii_in[][art_length]){
    for (int i=0; i <= art_height; i++){
        strcpy(out[i], ascii_in[i]);
    }
}


void asciicat(char out[art_height][art_length], char ascii_in[][art_length]){
    for (int i=0; i < art_height; i++){
        strcat(out[i], ascii_in[i]);
    }

}


void print_time(WINDOW* win, char ascii_time[][display_length]){
    int width = strlen(ascii_time[0]);
    int rows = art_height;

    // Size of the screen
    int max_y = getmaxy(win);
    int max_x = getmaxx(win);
    
    // Adjusting for string to be centered.
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

    char display[art_height][display_length];

    asciicpy(display, one);
    asciicat(display, two);

    strcpy(display[0], one[0]);
    strcpy(display[1], one[1]);
    strcpy(display[2], one[2]);
    strcpy(display[3], one[3]);
    strcpy(display[4], one[4]);
    strcpy(display[5], one[5]);
    strcpy(display[6], one[6]);
    strcpy(display[7], one[7]);

    strcat(display[0], two[0]);
    strcat(display[1], two[1]);
    strcat(display[2], two[2]);
    strcat(display[3], two[3]);
    strcat(display[4], two[4]);
    strcat(display[5], two[5]);
    strcat(display[6], two[6]);
    strcat(display[7], two[7]);

    /*
    printf("%s\n", display[0]);
    printf("%s\n", display[1]);
    printf("%s\n", display[2]);
    printf("%s\n", display[3]);
    printf("%s\n", display[4]);
    printf("%s\n", display[5]);
    printf("%s\n", display[6]);
    printf("%s\n", display[7]);
    */

    // Printing display array to analyse
    for (int i=0; i <= art_height; i++) {
        for (int j=0; j<=sizeof(display[i]); j++){
            putchar(display[i][j]);
        }
        printf("\n");
    }

    /*
    getch(); // Keeps window alive.
    endwin();
    */
    return 0;
}
