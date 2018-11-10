#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include "gui_manager.h"

// define boolean type
typedef enum{False, True} boolean;


void exitProgram(){
    disableCursesWindow();
    exit(1);
}

int main(int argumentCount, char **arguments){
    initCursesWindow();
    
    char lastChar;
    int8_t clearCounter = 0;
    
    while(1){
        lastChar = (char)getch();
        printf("%c-", lastChar);
        fflush(stdout);
        
        if(lastChar == 'q'){
            exitProgram();
        }
        
        if(++clearCounter == 100){
            clearCounter = 0;
            clearCursesWindow();
        }
    }
    
    disableCursesWindow();
    return 0;
}
