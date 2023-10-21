#include <ncurses.h>
#include <stdlib.h>

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void printing();
void moving_and_sleeping();
void colouring();

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(void) {
    initscr();

    addstr("-----------------\n| hello.com |\n| ncurses Demo  "
           "|\n-----------------\n\n");
    refresh();

    // printing();

    moving_and_sleeping();

    // colouring();

    addstr("\npress any key to exit...");
    refresh();

    getch();

    endwin();

    return EXIT_SUCCESS;
}

void printing() {
    addstr("This was printed using addstr\n\n");
    refresh();

    addstr("The following letter was printed using addch:- ");
    addch('a');
    refresh();

    printw("\n\nThese numbers were printed using printw\n%d\n%f\n", 123, 456.789);
}

void moving_and_sleeping() {
    int row = 5;
    int col = 0;

    curs_set(0);

    for(char c = 65; c <= 90; c++) {
        move(row++, col++);
        addch(c);
        refresh();
        napms(100);
    }

    row = 5;
    col = 3;

    for(char c = 97; c <= 122; c++) {
        mvaddch(row++, col++, c);
        refresh();
        napms(100);
    }

    curs_set(1);

    addch('\n');
}