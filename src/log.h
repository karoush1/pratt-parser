#ifndef __LOG__
#define __LOG__

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG_INFO(...) \
{\
    printf("I [%s@%s]: ", __FILENAME__, __func__);\
    printf(__VA_ARGS__);\
}

#define LOG_DEBUG(...) \
{\
    printf("D [%s@%s]: ", __FILENAME__, __func__);\
    printf(__VA_ARGS__);\
}

#define LOG_WARN(...) \
{\
    printf("W [%s@%s]: ", __FILENAME__, __func__);\
    printf(__VA_ARGS__);\
}

#define LOG_ERROR(...) \
{\
    printf("E [%s@%s]: ", __FILENAME__, __func__);\
    printf(__VA_ARGS__);\
}

#endif // __LOG__
