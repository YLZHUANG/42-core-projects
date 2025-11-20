nothing found with usual checking. so we explore the getflag with gdb.

```
level14@SnowCrash:~$ whereis getflag
getflag: /bin/getflag

level14@SnowCrash:~$ gdb -q /bin/getflag
Reading symbols from /bin/getflag...(no debugging symbols found)...done.
(gdb) set disassembly-flavor intel
(gdb) break main
Breakpoint 1 at 0x804894a
(gdb) disassemble /r main
Dump of assembler code for function main:
  0x08048946 <+0>:     55      push   ebp
  0x08048947 <+1>:     89 e5   mov    ebp,esp
  0x08048949 <+3>:     53      push   ebx
  .........
  0x08048afd <+439>: call   0x80484b0 <getuid@plt>  ==> hint
  0x08048b02 <+444>: mov    DWORD PTR [esp+0x18],eax
  0x08048b06 <+448>: mov    eax,DWORD PTR [esp+0x18]
  0x08048b0a <+452>: cmp    eax,0xbbe               ==> hint
  .........

level14@SnowCrash:~$ id flag14
uid=3014(flag14) gid=3014(flag14) groups=3014(flag14),1001(flag)

level14@SnowCrash:~$ gdb -q /bin/getflag
Reading symbols from /bin/getflag...(no debugging symbols found)...done.
(gdb) break ptrace
Breakpoint 1 at 0x8048540
(gdb) commands
Type commands for breakpoint(s) 1, one per line.
End with a line saying just "end".
>return (long)0
>continue
>end
(gdb) break getuid
Breakpoint 2 at 0x80484b0
(gdb) commands
Type commands for breakpoint(s) 2, one per line.
End with a line saying just "end".
>return (int)0xbbe
>continue
>end
(gdb) run
Starting program: /bin/getflag 

Breakpoint 1, 0xb7f146d0 in ptrace () from /lib/i386-linux-gnu/libc.so.6

Breakpoint 2, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
[Inferior 1 (process 2222) exited normally]
```

















































































































































































