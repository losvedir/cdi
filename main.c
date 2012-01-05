#include <ncurses.h>
#include "model/dir.h"
#include "model/dirent.h"

int main(int argc, char **argv) {
    int ch;

    initscr();              /* initialize curses mode */
    cbreak();               /* handle ctrl-c, etc for me */
    noecho();               /* don't echo keypresses to the screen */
    keypad(stdscr, TRUE);   /* for handling arrow keys, fn, etc */
    
    printw("Hello World !!!\n");
    while ((ch = getch())) {
        refresh();
    } 
    endwin();
    return 0;
}
