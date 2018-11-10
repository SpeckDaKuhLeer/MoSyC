#include <curses.h>

WINDOW* mainCursesWindow;

void initCursesWindow(){
    // init main window
    mainCursesWindow = initscr();
    
    // create a new curses window and change input mode
    cbreak();
    
    // disable key echo
    noecho();
}

void clearCursesWindow(){
    wclear(mainCursesWindow);
    fflush(stdout);
}

void disableCursesWindow(){
    // end the current window and return a code
    short int windowErrorCode = endwin();
}
