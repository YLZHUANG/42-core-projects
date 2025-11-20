we find that in `~/` directory we have a `level02.pcap` file
we use `scp` to copy the file in your system and start wireshark to analyze it
with a follow TCP Stream option we can follow the full TCP, and we can see something that looks like a login page:

`
Linux 2.6.38-8-generic-pae (::ffff:10.1.1.2) (pts/10)

..wwwbugs login: l.le.ev.ve.el.lX.X
..
Password: ft_wandr...NDRel.L0L
.
..
Login incorrect
wwwbugs login: 
`

If we check the value in a C-Array like the `.` input we see it's in realty a DEL input, so we can re-write the password as `ft_waNDReL0L` and get the flag