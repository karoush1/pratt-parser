#ifndef __LOG__
#define __LOG__

#include <stdarg.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG_INFO(msg, ...) \
{\
    printf("I [%s@%s]: ", __FILENAME__, __func__);\
    printf(msg, __VA_ARGS__);\
}

#define LOG_DEBUG(msg, ...) \
{\
    printf("D [%s@%s]: ", __FILENAME__, __func__);\
    printf(msg, __VA_ARGS__);\
}

#define LOG_WARN(msg, ...) \
{\
    printf("W [%s@%s]: ", __FILENAME__, __func__);\
    printf(msg, __VA_ARGS__);\
}

#define LOG_ERROR(msg, ...) \
{\
    printf("E [%s@%s]: ", __FILENAME__, __func__);\
    printf(msg, __VA_ARGS__);\
}

#endif // __LOG__
