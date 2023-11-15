#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

char *hello = "Hello Embedded Investors!";

/*
 * This is the main function
 *
 */

int main() {

    int num = 5;
    int *pi = &num;

    printf("Address of num: %d Value: %d\n",&num, num);
    printf("Address of pi: %d Value: %d\n",&pi, pi);

    puts("\n");

    printf("Address of pi: %d Value: %d\n", &pi, pi);
    printf("Address of pi: %x Value: %x\n", &pi, pi);
    printf("Address of pi: %o Value: %o\n", &pi, pi);
    printf("Address of pi: %p Value: %p\n", &pi, pi);

    printf("Value of pi: %p\n", (void *)pi);

    printf("%d\n", *pi);
    // change the value of pi
    *pi = 200;
    printf("%d\n", *pi);
    printf("%d\n", num);

    printf("Value of pi: %p\n", pi);
    void *pv = pi;
    pi = (int *) pv;
    printf("Value of pi: %p\n", pi);

    size_t sizet = -5;
    printf("%ld\n", sizet);
    printf("%zu\n", sizet);

    sizet = 5;
    printf("%ld\n", sizet);
    printf("%zu\n", sizet);

    printf("Size of *char: %lu\n", sizeof(char *));

    int num2;
    uintptr_t *pu = (uintptr_t *)&num;

    char c;
    uintptr_t *pc = (uintptr_t*)&c;

    int vector[] = {28, 41, 7};
    int *pvec = vector;
    pvec += 3;
    printf("Value [%p] and [%p] shoulde be the same?\n", &pvec, &vector);

    printf("Value [%d] is at address [%p]\n", *pvec, &vector[0]);
    pvec++;
    printf("Value [%d] is at address [%p]\n", *pvec, &vector[1]);
    pvec++;
    printf("Value [%d] is at address [%p]\n", *pvec, &vector[2]);

    puts("\n");

    short s;
    short *ps = &s;
    char c;
    char *pc = &c;

    printf("Content of ps before: d\n");

    printf("%s \n", hello);

    return 0;
}
