#define MAX_BUFFERSIZE_X 400
#define MAX_BUFFERSIZE_Y 100

#include <stdint.h>
#include <stdlib.h>
#include <curses.h>

typedef enum{False, True} boolean;

// inherits the window information
WINDOW* _CGwindow;

// screen buffer to store the characters
volatile char _CGbuffer[MAX_BUFFERSIZE_X][MAX_BUFFERSIZE_Y];

// string to be later printed onto the screen
volatile char* _CGoutputString;

// indicates if the screen buffer has been changed, if yes reassamble the output string
volatile boolean _CGbufferChanged;

// last updates size of the terminal
volatile int16_t _CGtermSizeX;
volatile int16_t _CGtermSizeY;

/* 
 * Starts a new curses window and changes the input mode.
 * Echo will be also disabled so that you do not see the keys you press.
 * 
 */
void CGstart(){
    // initiate a screen buffer
    _CGwindow = initscr();
    
    // disable scrolling
    scrollok(_CGwindow, 0);
    
    cbreak();
    noecho();
    
    // +1 because of linebreaks each line and string terminator
    _CGoutputString = malloc(((MAX_BUFFERSIZE_X + 1) * MAX_BUFFERSIZE_Y + 1) * 8);
    
    // first time the string gets created even if the buffer is empty
    _CGbufferChanged = True;
    
    // get the terminal size
    _CGtermSizeX = COLS;
    _CGtermSizeY = LINES;
    
    // init screen buffer
    for(uint16_t _CGinitX = 0; _CGinitX < MAX_BUFFERSIZE_X; ++_CGinitX){
        for(uint16_t _CGinitY = 0; _CGinitY < MAX_BUFFERSIZE_Y; ++_CGinitY){
            _CGbuffer[_CGinitX][_CGinitY] = 32;
        }
    }
}

/*
 * Kill the open curses window.
 * 
 */
void CGstop(){
    // end the current window and return a code
    short int _CGwindowErrorCode = endwin();
}

/*
 * Reprints the screen buffer if it is needed.
 * 
 */
void CGprintBuffer(){
    _CGbuffer[2][2] = 'a'; // DEBUGGING #####
    
    // check if terminal size has changed
    if(_CGtermSizeX != COLS || _CGtermSizeY != LINES){
        _CGbufferChanged = True;
        
        _CGtermSizeX = COLS;
        _CGtermSizeY = LINES;
    }
    
    // if buffer has changed reprint
    if(_CGbufferChanged == True){
        
        // convert the buffer into a string
        for(uint16_t _CGcreateY = 0; _CGcreateY < _CGtermSizeY; ++_CGcreateY){
            for(uint16_t _CGcreateX = 0; _CGcreateX < _CGtermSizeX; ++_CGcreateX){
                _CGoutputString[_CGcreateY * _CGtermSizeX + _CGcreateX] = _CGbuffer[_CGcreateX][_CGcreateY];
            }
            
            // add line break
            _CGoutputString[_CGcreateY * (_CGtermSizeX + 1)] = '\n';
        }
        
        // set string terminator
        _CGoutputString[(_CGtermSizeX + 1) * _CGtermSizeY + 1] = '\0';
        
        // clear the screen
        wclear(_CGwindow);
        
        // print screen
        printf("%s", _CGoutputString);
        fflush(stdout);
    }
}
