#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include <panel.h>

#define STRSIZE 255

void printFile(const char* path) {
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
        printf("%s", str[i]);
        i++;
    }
  
    fclose(fptr); 
}

int main() {
    WINDOW *my_wins[3];
	PANEL  *my_panels[3];

    int x = 0;
    int y = 0;

    initscr();

    my_wins[0] = newwin(LINES, COLS / 2, y, x);
	my_wins[1] = newwin(LINES, COLS / 2, y, COLS / 2); 

    box(my_wins[0], 0, 0);
    box(my_wins[1], 0, 0);

    my_panels[0] = new_panel(my_wins[0]);
	my_panels[1] = new_panel(my_wins[1]);

    update_panels();
    doupdate();

    wprintw(my_wins[0], "");

    printFile("test.txt");
    // refresh();

    getch();
    endwin();

    return 0;
}

/*

    TODO

0) draw the windows
1) print a file
2) print a second file near by a first

*/ 