#include <stdio.h>
#include <time.h>

typedef struct {
    int day, month, year;
} date;

date sys_date(void);

date sys_date(void) {
    date sys_date;

    time_t T = time(NULL);
    struct tm tm;
    tm = *localtime(&T);

    sys_date.day = tm.tm_mday;
    sys_date.month = tm.tm_mon + 1;
    sys_date.year = tm.tm_year + 1900;

    return sys_date;
}

int main() {
    date today = sys_date();

    printf("%d %d %d\n", today.day, today.month, today.year);

    return 0;
}