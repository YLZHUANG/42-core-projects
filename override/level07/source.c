
int clear_stdin(void)
{
	int result;

	do
	{
		result = getchar();
	}	while ((unsigned char)result != '\n' && (unsigned char)result != 0xFF);
	return result;
}

int get_unum(void)
{
  unsigned int value; // [esp+1Ch] [ebp-Ch] BYREF

  value = 0;
  fflush(stdout);
  scanf("%u", &value);
  clear_stdin();
  return value;
}

int store_number(char *tab)
{
  unsigned int number; // [esp+18h] [ebp-10h]
  unsigned int index; // [esp+1Ch] [ebp-Ch]

  printf(" Number: ");
  number = get_unum();
  printf(" Index: ");
  index = get_unum();
  if ( index == 3 * (index / 3) || HIBYTE(number) == 0xB7 )
  {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    return 1;
  }
  else
  {
    *(unsigned int *)(tab + 4 * index) = number;
    return 0;
  }
}

int read_number(unsigned int *tab)
{
  int index; // [esp+1Ch] [ebp-Ch]

  printf(" Index: ");
  index = get_unum();
  printf(" Number at data[%u] is %u\n", index, tab[index]);
  return 0;
}

// break

int main(int argc, const char **argv, const char **envp)
{
  char tab[400] = {0}; // [esp+24h] [ebp-1B8h] BYREF
  int number = 0; // [esp+1B4h] [ebp-28h]
  char s[24] = {0}; // [esp+1B8h] [ebp-24h] BYREF

  while ( *argv )
  {
    memset((void *)*argv, 0, strlen(*argv));
    ++argv;
  }
  
  while ( *envp )
  {
    memset((void *)*envp, 0, strlen(*envp));
    ++envp;
  }

  puts(
    "----------------------------------------------------\n"
    "  Welcome to wil's crappy number storage service!   \n"
    "----------------------------------------------------\n"
    " Commands:                                          \n"
    "    store - store a number into the data storage    \n"
    "    read  - read a number from the data storage     \n"
    "    quit  - exit the program                        \n"
    "----------------------------------------------------\n"
    "   wil has reserved some storage :>                 \n"
    "----------------------------------------------------\n");
  while ( 1 )
  {
    printf("Input command: ");

    number = 1;
    fgets(s, 20, stdin);
	  s[strlen(s) - 1] = 0;
    // break
	  if ( !memcmp(s, "store", 5u) )
    {
      number = store_number(tab);   // break
    }
    else if ( !memcmp(s, "read", 4u) )
    {
      number = read_number(tab);
    }
    else if ( !memcmp(s, "quit", 4u) )
	  {
      return 0;
	  }

    if ( number )
	  {
      printf(" Failed to do %s command\n", s);
	  }
	  else
	  {
      printf(" Completed %s command successfully\n", s);
	  }
	  memset(s, 0, sizeof(s));
  }
}
