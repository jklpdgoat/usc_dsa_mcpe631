#include <stdio.h>

int main() {
    int i, num, fact;
    printf("Enter the number: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
        fact = fact * i;
    printf("Factorial of %d = %d\n", num, fact);

    return 0;
}