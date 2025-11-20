
#include <stddef.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
  if (ac != 2)
  {
    printf("%s <login>\n", av[0]);
    return 0;
  }

  char *login = av[1];

  int v5 = strnlen(login, 32);

  if (v5 <= 5)
  {
    printf("login is too short!\n");
    return 1;
  }

  int v4;

  v4 = (login[3] ^ 0x1337) + 6221293;
  for ( size_t i = 0; i < v5; ++i )
  {
    if ( login[i] <= 31 )
    {
        printf("invalid login character!\n");
        return 1;
    }
    v4 += (v4 ^ (unsigned int)login[i]) % 0x539;
  }
  printf("serial: %u\n", v4);
  return 0;
}