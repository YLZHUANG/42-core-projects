
int main(int argc, const char **argv, const char **envp)
{
  int stat_loc; // [esp+1Ch] [ebp-9Ch] BYREF
  char str[128]; // [esp+20h] [ebp-98h] BYREF
  int v6; // [esp+A0h] [ebp-18h]
  int v7; // [esp+A4h] [ebp-14h]
  int v8; // [esp+A8h] [ebp-10h]
  __pid_t pid; // [esp+ACh] [ebp-Ch]

  pid = fork();
  memset(str, 0, sizeof(str));
  v8 = 0;
  stat_loc = 0;
  if (pid != 0)
  {
    // Parent
    do
    {
      wait(&stat_loc);
      v6 = stat_loc;
      if ( (stat_loc & 0x7F) == 0 || (v7 = stat_loc, (char)((stat_loc & 0x7F) + 1) >> 1 > 0) )
      {
        puts("child is exiting...");
        return 0;
      }
      v8 = ptrace(PTRACE_PEEKUSER, pid, 44, 0);
    }
    while ( v8 != 11 );
    puts("no exec() for you");
    kill(pid, 9);
  }
  else
  {
    prctl(1, 1);
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    puts("Give me some shellcode, k");
    gets(str);
  }
  return 0;
}
