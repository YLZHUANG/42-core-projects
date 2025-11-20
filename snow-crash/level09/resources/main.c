#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int fd;

    fd = open("./token", 0);
    if (fd < 0)
    {
        return -1;
    }

    ssize_t read_value;
    char buf[1024];
 
    read_value = read(fd, buf, 1024);
    if (read_value == -1)
    {
        return -1;
    }

    for (size_t i = 0; i < read_value; i++)
    {
        if (buf[i] == '\n')
        {
            break ;
        }
        printf("%c", (char)(buf[i] - i)); // we changed the sign to -
    }
    printf("\n");
    return 0;
}
