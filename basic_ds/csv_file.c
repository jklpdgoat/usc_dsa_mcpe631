#include <ncurses.h>
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("./csv_files/user_data.csv", "a+");

    char name[50];
    int accountno;
    float amount;

    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }

    printf("\nEnter Account Holder Name\n");
    scanf("%s", name);
    printf("\nEnter Account Number\n");
    scanf("%d", &accountno);
    printf("\nEnter Available Amount\n");
    scanf("%f", &amount);

    // Saving data in file
    fprintf(fp, "%s, %d, %0.2f\n", name, accountno, amount);

    printf("\nNew Account added to record");

    fclose(fp);

    return 0;
}