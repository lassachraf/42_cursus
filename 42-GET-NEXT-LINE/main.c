#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char *s = "hello world!!";
    int fd = open("a.txt", O_CREAT | O_WRONLY, 0777);
    write(fd, s, strlen(s));

    int read();
    close(fd);
}