
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    int fd2;

    fd = open("test.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    close(fd);
    close(fd2);
}