#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randRange(int n) {
    int limit;
    int r;

    limit = RAND_MAX - (RAND_MAX % n);

    while ((r = rand()) >= limit)
        ;

    return r % n;
}

int main(int argc, char **argv) {
    int i;

    srand(time(0));

    for (i = 0; i < 40; i++) {
        printf("%d ", randRange(6) + 1);
    }

    putchar('\n');

    return 0;
}