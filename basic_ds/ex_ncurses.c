#include <ncurses.h>

int main() {
    WINDOW *w;
    char c;

    w = initscr();
    timeout(3000);
    c = getch();
    endwin();

    printf("received\t %c\t (%d)\n", c, (int)c);
}
