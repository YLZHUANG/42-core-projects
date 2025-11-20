with a `ls -la` we can find two file:
-rwsr-sr-x 1 flag09  level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09  level09   26 Mar  5  2016 token

level09 is a not stripped ELF 32-bit LSB executable
token is a file where we have only read permission

We can try to use `gdb level09` to have a first view of the binary and get a `You should not reverse this` output

we can try some input:
```bash
$ ./level09 abcdef
acegik
$ ./level09 abcdefghijklm
acegikmoqsuwy
$ ./level09 abcdefghijklmopqrstuvwxyz
acegikmoqsuwy|~����������
$ ./level09 zz
z{
```

Look like we have a lead, the code may look smt like this:
```c
#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac == 1)
        return -1;
    
    size_t arg_len;

    arg_len = strlen(av[1]);
    for (size_t i = 0; i < arg_len; i++)
    {
        printf("%c", (char)(av[1][i] + i));
    }
    printf("\n");
    return 0;
}
```

With that we can guess that the token is a output of the level09 binary
We write a small C code to reverse the action done to it to get it back:

```c
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
```

We get the token file:
`scp -P 4242 level09@<ip>:/home/user/level09/token ./token`

and run the decode:
```bash
$ gcc main.c ; ./a.out 
f3iji1ju5yuevaus41q1afiuq
```

with that we can log with `flag09` and run `getflag`
```bash
$ su flag09
Password: 
Don't forget to launch getflag !
$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```