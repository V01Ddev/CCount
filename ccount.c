#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include "BigMoney-nw.c"


void ascii_strcpy(char out[][display_length], char ascii_in[][art_length]){
    for (int i=0; i <= art_height; i++){
        // Clear the destination line

        memset(out[i], ' ', display_length - 1);
        out[i][display_length - 1] = '\0'; // Null-terminate the string
 
        strcpy(out[i], ascii_in[i]);
    }
    /*
    strcpy(out[0], ascii_in[0]);
    strcpy(out[1], ascii_in[1]);
    strcpy(out[2], ascii_in[2]);
    strcpy(out[3], ascii_in[3]);
    strcpy(out[4], ascii_in[4]);
    strcpy(out[5], ascii_in[5]);
    strcpy(out[6], ascii_in[6]);
    strcpy(out[7], ascii_in[7]);
    */
}


void ascii_srtcat(char out[][art_length], char ascii_in[art_height][art_length]){
    for (int i=0; i <= art_height; i++){
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
        mvprintw(y, x, "%s", ascii_time[i]);
        y++;
    }
}

int main() {

    // WINDOW* win = initscr();
    // refresh();

    char display[art_height][display_length];


    /*
    for (int k=0; k<art_height; k++){
        strcpy(display[k], one[k]);
    }
    */
    ascii_strcpy(display, one);

    for (int k=0; k<art_height; k++){
        printf("%s\n", display[k]);
    }

    // getch(); // Keeps window alive.
    // endwin();
    return 0;
}
