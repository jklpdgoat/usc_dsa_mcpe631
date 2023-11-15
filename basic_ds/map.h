#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <stddef.h>
#include <stdint.h>

typedef struct t_Map {
    size_t count;
    size_t node_size;
    uint8_t *data;
} t_Map;

int t_mapInit(t_Map *m, size_t value_size, size_t init_count);
int t_mapCleanup(t_Map *m);
void *t_mapGet(t_Map *m, uint32_t key);
int t_mapAdd(t_Map *m, uint32_t key, void *object);
int t_mapSet(t_Map *m, uint32_t key, void *object);
int t_mapDel(t_Map *m, uint32_t key);
void *t_mapGetIndex(t_Map *m, size_t idx, uint32_t *key);

#endif // MAP_H_INCLUDED