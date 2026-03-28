#include <stddef.h>

int _write(int fd, const void *buf, size_t count)
{
    (void)fd;
    (void)buf;
    (void)count;
    return (int)count;
}

int _read(int fd, const void *buf, size_t count)
{
    (void)fd;
    (void)buf;
    (void)count;
    return 0;
}
