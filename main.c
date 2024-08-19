#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include <panel.h>

#define STRSIZE 255

void printFile(const char* path, WINDOW* win) {
    FILE *fptr; 
    char str[STRSIZE][STRSIZE]; 

    // Open file 
    fptr = fopen(path, "r"); 
    if (fptr == NULL) { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    int i = 0;
    while (fgets(str[i], 50, fptr) != NULL) {
        mvwprintw(win, i + 1, 1, str[i]);
        i++;
    }
  
    fclose(fptr); 
}

int main() {
    WINDOW *my_wins[2];
	PANEL  *my_panels[2];

    initscr();

    my_wins[0] = newwin(LINES, COLS / 2, 0, 0);
	my_wins[1] = newwin(LINES, COLS / 2, 0, COLS / 2); 


    my_panels[0] = new_panel(my_wins[0]);
	my_panels[1] = new_panel(my_wins[1]);

    printFile("test.txt", my_wins[0]);
    printFile("test.txt", my_wins[1]);

    box(my_wins[0], 0, 0);
    box(my_wins[1], 0, 0);

    update_panels();
    doupdate();

    getch();
    endwin();

    return 0;
}

/*

    TODO

\/ 0) draw windows
\/ 1) print a files into windows
2) parse args

*/ 