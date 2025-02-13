#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>


void convertSeconds(int total_seconds, int *hours, int *minutes, int *seconds) {
    *hours = total_seconds / 3600;         // Get the number of hours
    *minutes = (total_seconds % 3600) / 60; // Get the remaining minutes
    *seconds = total_seconds % 60;          // Get the remaining seconds
}

void countdown(int seconds) {
    initscr();
    noecho();
    curs_set(FALSE);

    int h, m, s;

    for (int i = seconds; i >= 0; i--) {
        clear();
        convertSeconds(i, &h, &m, &s);

        mvprintw(LINES / 2, (COLS / 2) - 2, "%02d:%02d:%02d", h, m, s);
        refresh();
        sleep(1);
    }

    mvprintw(LINES / 2 + 1, (COLS / 2) - 6, "Time's up!");
    refresh();
    sleep(2);

    endwin();
}

int main(int argc, char *argv[]) {
    // Processing CLI input
    int h_int = -1;
    int m_int = -1;
    int s_int = -1;

    if (argc == 1){
        printf("No input given!\n");
        printf("Example inputs:\n");
        printf("1 30 4\n");
        printf("0 69m 0\n");
        printf("5 8\n");
    }
    if (argc == 2){
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
        printf("Too many arguments given!\n");
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
