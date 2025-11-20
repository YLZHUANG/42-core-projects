We found a binary in the folder. so immediately check the rodada, place where stocks const variables. 

```
level13@SnowCrash:~$ objdump -s -j .rodata level13 

  level13:     file format elf32-i386

  objdump: section 'rodata' mentioned in a -j option, but not found in any input file
  level13@SnowCrash:~$ objdump -s -j .rodata level13 

  level13:     file format elf32-i386

  Contents of section .rodata:
  80486b8 03000000 01000200 30313233 34353600  ........0123456.
  80486c8 55494420 25642073 74617274 65642075  UID %d started u
  80486d8 73206275 74207765 20776520 65787065  s but we we expe
  80486e8 63742025 640a0062 6f655d21 61693046  ct %d..boe]!ai0F
  80486f8 42402e3a 7c4c366c 40413f3e 714a7d49  B@.:|L6l@A?>qJ}I
  8048708 00796f75 7220746f 6b656e20 69732025  .your token is %
  8048718 730a00                               s..             
```

so we use gdb to check the token.
```
level13@SnowCrash:~$ gdb -q level13
  Reading symbols from /home/user/level13/level13...(no debugging symbols found)...done.
  (gdb) break printf if *(char **)( $esp + 4 ) == 0x08048708
  Breakpoint 1 at 0x8048360
  (gdb) run
  Starting program: /home/user/level13/level13 
  UID 2013 started us but we we expect 4242
  [Inferior 1 (process 2990) exited with code 01]
```

we get the hint : `UID 2013 started us but we we expect 4242`. that's why we didn't get to your token is %s.
so we try to set the uid.
```
level13@SnowCrash:~$ gdb -q level13
Reading symbols from /home/user/level13/level13...(no debugging symbols found)...done.
(gdb) break main
Breakpoint 1 at 0x804858f
(gdb) run
Starting program: /home/user/level13/level13 

Breakpoint 1, 0x0804858f in main ()
(gdb) break getuid
Breakpoint 2 at 0xb7ee4cc0
(gdb) commands
Type commands for breakpoint(s) 2, one per line.
End with a line saying just "end".
>return (int)4242
>continue
>end
(gdb) break printf if *(char **)($esp+4) == 0x08048708
Breakpoint 3 at 0xb7e78850
(gdb) continue
Continuing.

Breakpoint 2, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
your token is 2A31L79asukciNyi8uppkEuSx
[Inferior 1 (process 3166) exited with code 050]
```