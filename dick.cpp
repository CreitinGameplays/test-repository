#include <curses.h>

int main(){
    initscr();
    printw("Hello mr penis.");
    refresh();
    getch();
    endwin();
    return 0;
}