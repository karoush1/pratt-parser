#include "mem_arena.h"

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
