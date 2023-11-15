#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "map.c"
#include "map.h"

typedef struct TestMap {
    bool a;
    int x;
    uint64_t y;
    double z;
} TestMap;

t_Map tests;

int main() {
    printf("hello\n");
    t_mapInit(&tests, sizeof(TestMap), 2);

    TestMap MapA = {.a = true, .x = 11, .z = 21.0, .y = 30};
    TestMap MapB = {.a = true, .x = 12, .z = 22.0, .y = 35};
    TestMap MapC = {.a = true, .x = 13, .z = 23.0, .y = 40};

    // test resize
    printf("C: %zu\n", tests.count);
    t_mapAdd(&tests, 123, &MapA);
    return 0;
}
