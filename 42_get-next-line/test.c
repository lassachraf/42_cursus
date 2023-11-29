# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include "get_next_line.h"

int main()
{
    int fd = open("a.txt", O_RDWR, 0777);
    
    printf("buff 1 => %s\n", get_next_line(fd));
}   