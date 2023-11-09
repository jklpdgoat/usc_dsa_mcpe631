#include <stdio.h>

/* structure declaration */
struct employee {
    char name[30];
    int empId;
    float salary;
};

struct point {
    double x;
    double y;
};

void func(pf) struct point *pf;
{
    pf->x = 9.0;
    pf->y = 8.0;
    printf("func %f %f\n", pf->x, pf->y);
}

int main() {
    struct point pm;

    pm.x = 3.0;
    pm.y = 4.0;

    printf("main %f %f\n", pm.x, pm.y);
    func(&pm);
    printf("back %f %f\n", pm.x, pm.y);

    struct employee emp;

    printf("\nEnter Details:\n");
    printf("Name?: ");
    fgets(emp.name, 30, stdin);
    printf("ID?: ");
    scanf("%d", &emp.empId);
    printf("Salary?: ");
    scanf("%f", &emp.salary);

    printf("\nEntered Information:\n");
    printf("Name: %s", emp.name);
    printf("Id: %d\n", emp.empId);
    printf("Salary: %0.2f\n", emp.salary);
}