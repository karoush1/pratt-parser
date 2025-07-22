#ifndef __MEM_ARENA__
#define __MEM_ARENA__

#include <stddef.h>

#define DEFAULT_ARENA_SIZE (200 * 1024)

typedef struct {
    const void *buf;
    size_t offset;
    size_t len;
}arena_t;

void* arena_init(size_t size);
void* arena_malloc(arena_t *arena, size_t size);
void arena_free(arena_t *arena);

#endif// __MEM_ARENA__
