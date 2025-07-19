#ifndef __MEM_ARENA__
#define __MEM_ARENA__

#include <stdlib.h>

#define DEFAULT_ARENA_SIZE 200 * 1024

typedef struct {
    const void *buf;
    size_t offset;
    size_t len;
}arena_t;

void* arena_init(size_t size)
{
    arena_t *arena = malloc(sizeof(arena_t));
    char *buf = malloc(size);
    *arena = (arena_t){
        .buf = buf,
        .offset = 0,
        .len = size
    };

    return arena;
}

void* arena_malloc(arena_t *arena, size_t size)
{
    arena->offset += size;
    return (char*)(arena->buf) + arena->offset;
}

void arena_free(arena_t *arena)
{
    free(arena);
}

#endif// __MEM_ARENA__
