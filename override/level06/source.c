bool auth(char *login, int serial)
{
  int v4; // [esp+18h] [ebp-10h]
  int v5; // [esp+1Ch] [ebp-Ch]

  login[strcspn(login, "\n")] = 0;
  v5 = strnlen(login, 32);
  if ( v5 <= 5 )
  {
    return true;
  }

  if ( ptrace(PTRACE_TRACEME, 0, 1, 0) == -1 )
  {
    puts("\x1B[32m.---------------------------.");
    puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
    puts("\x1B[32m'---------------------------'");
    return 1;
  }
  else
  {
    v4 = (login[3] ^ 0x1337) + 6221293;
    for (int  i = 0; i < v5; ++i )
    {
      if ( login[i] <= 31 )
      {
        return 1;
      }
      v4 += (v4 ^ (unsigned int)login[i]) % 0x539;
    }
    return serial != v4;
  }
}

int main(int argc, const char **argv, const char **envp)
{
  int serial; // [esp+2Ch] [ebp-24h] BYREF
  char login[32]; // [esp+30h] [ebp-20h] BYREF

  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  fgets(login, 32, stdin);
  puts("***********************************");
  puts("***** NEW ACCOUNT DETECTED ********");
  puts("***********************************");
  printf("-> Enter Serial: ");
  scanf("%u", &serial);
  if ( auth(login, serial) != false)
  {
    return 1;
  }

  puts("Authenticated!");
  system("/bin/sh");
  return 0;
}


