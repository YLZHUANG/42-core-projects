with `cat /etc/passwd` we get:
```
flag00:x:3000:3000::/home/flag/flag00:/bin/bash
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash <== HERE IS THE HINT
flag02:x:3002:3002::/home/flag/flag02:/bin/bash
```

but it does not work, it's a hashed code, so we use john to get the original code:

```
root@VM42SM:/home# echo '42hDRfypTqqnw' > hash.txt

root@VM42SM:/home# john hash.txt --wordlist=/usr/share/john/password.lst
    Loaded 1 password hash (descrypt, traditional crypt(3) [DES 128/128 SSE2])
    Will run 6 OpenMP threads
    Press 'q' or Ctrl-C to abort, almost any other key for status
    abcdefg          (?)
    1g 0:00:00:00 100% 100.0g/s 354200p/s 354200c/s 354200C/s 123456..sss
    Use the "--show" option to display all of the cracked passwords reliably
    Session completed

root@VM42SM:/home# john --show hashes.txt
    ?:abcdefg
    1 password hash cracked, 0 left
```

so we get the password : abcdefg
and the flag: f2av5il02puano7naaf6adaaf
