#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <curses.h>

// handles the text user interface (tui)
#include "consolegraphics.h"

int main(int argumentCount, char **arguments){
    char lastChar;
    int8_t clearCounter = 0;
    
    CGstart();
    while(1){
        lastChar = (char)getch();
        printf("%d-", lastChar);
        CGprintBuffer();
        
        if(lastChar == 'q'){
            CGstop();
            exit(1);
        }
        
        if(++clearCounter == 100){
            clearCounter = 0;
        }
    }
    CGstop();
    
    return 0;
}
