

int decrypt(char a1)
{
  unsigned int len; // [esp+24h] [ebp-24h]
  char str[28]; // [esp+2Bh] [ebp-1Dh] BYREF

  *(_DWORD *)&v4[17] = __readgsdword(0x14u);

  strcpy(str, "Q}|u`sfg~sf{}|a3");
  len = strlen(str);
  for (unsigned int i = 0; i < len; ++i )
  {
    str[i] ^= a1;
  }
  if (strcmp(str, "Congratulations!") == 0)
  {
    return system("/bin/sh");
  }
  return puts("\nInvalid Password");
}

int test(int a1, int a2)
{
  int result;
  int random;

  switch ( a2 - a1 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
      result = decrypt(a2 - a1);
      break;
    default:
      random = rand();
      result = decrypt(random);
      break;
  }
  return result;
}

int main(void)
{
  time_t time_value;
  int password;

  time_value = time(0);
  srand(time_value);
  puts("***********************************");
  puts("*\t\tlevel03\t\t**");
  puts("***********************************");
  printf("Password:");
  scanf("%d", &password);
  test(password, 322424845);
  return 0;
}
