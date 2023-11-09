#include <stdio.h>

#define pi 3.14 // macros definition
#define add(a, b) (a + b) // macro definition

#define CUBE(b) b * b * b

int cube(int a) {
    return a * a * a;
}

int number() {
    return 10;
}

int main() {
    int r = 4, area, circum;

    int a = 10, b = 15, result;


    circum = 2 * pi * r;

    area = pi * r * r;

    printf("Circumference of a circle is: %d\n", circum);

    printf("area a circle is: %d\n", area);

    result = add(a, b);

    printf("Addition of two number is : %d\n", result);

    printf("File name is : %s\n", __FILE__);
    printf("Current Date is : %s\n", __DATE__);
    printf("Current Time is : %s\n", __TIME__);
    printf("The Line # is : %d\n", __LINE__);
    printf("Standard C : %d\n", __STDC__);

    printf("%d\n", number());
    
    printf("%d\n", CUBE(1+2));
    printf("%d\n", cube(1+2));
        
    return 0;
}