#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>


void convertSeconds(int total_seconds, int *hours, int *minutes, int *seconds) {
    *hours = total_seconds / 3600;         // Get the number of hours
    *minutes = (total_seconds % 3600) / 60; // Get the remaining minutes
    *seconds = total_seconds % 60;          // Get the remaining seconds
}


void paused(){
    int p = 0;
    do {
        if (getch()==32){
            p = 1;
        }
    } while (p==0);
}

void helpMenu(){
    printf("[h] Pass your input as arguments\n");
    printf("[h] Example inputs:\n");
    printf("[h]     1 30 4  = 1 hour, 30 minutes, and 4 seconds\n");
    printf("[h]     0 69 0  = 69 minutes\n");
    printf("[h]     5 8     = 5 minutes and 8 seconds\n");
    printf("[h] Use Ctrl-C to exit\n");
    printf("[h] Use -h to get this page\n");
}


void countdown(int seconds) {
    initscr();
    noecho();
    curs_set(FALSE);
    timeout(0);

    int seconds_left = seconds;

    int h, m, s;

    for (int i = seconds; i >= 0; i--) {
        int k = getch();
        if (k==32){
            clear();
            mvprintw(LINES / 2, (COLS / 2) - 2, "Paused");
            paused();
        }

        clear();
        convertSeconds(i, &h, &m, &s);
        mvprintw(LINES / 2, (COLS / 2) - 2, "%02d:%02d:%02d", h, m, s);
        refresh();
        sleep(1);
    }

    endwin();
}


int main(int argc, char *argv[]) {
    // Processing CLI input
    int h_int = -1;
    int m_int = -1;
    int s_int = -1;

    if (argc == 1){
        printf("[E] No input given!\n");
        printf("[h] Use -h to get some help!\n");
        return 1;
    }

    if (argc == 2){
        if (argv[1][1]=='h'){
            helpMenu();
            return 0;
        }
        s_int = atoi(argv[1]);
    }

    if (argc == 3){
        s_int = atoi(argv[2]);
        m_int = atoi(argv[1]);
    }

    if (argc == 4){
        s_int = atoi(argv[3]);
        m_int = atoi(argv[2]);
        h_int = atoi(argv[1]);
    }

    if (argc > 4){
        printf("[E] Too many arguments given!\n");
        printf("[h] Use -h to get some help!\n");
        return 1;
    }

    int seconds=s_int;

    if (h_int!=-1){
        seconds=seconds+(h_int*60*60);
    }

    if (m_int!=-1){
        seconds=seconds+(m_int*60);
    }

    countdown(seconds);
    return 0;
}
