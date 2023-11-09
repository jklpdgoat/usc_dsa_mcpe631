#ifndef CUSTOMER_H
#define CUSTOMER_H

// A struct representing a customer
typedef struct RegularCustomer {
    int regular_pn; // priority number slip for regular customers
    struct RegularCustomer *next;
} RegularCustomer;

typedef struct SpecialCustomer {
    int size;
    int special_pn; // priority number slip for special customers
    struct SpecialCustomer *snext;
} SpecialCustomer;

#endif