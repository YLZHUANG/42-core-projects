
int __noreturn main(void)
{
  char s[100]; // [esp+28h] [ebp-70h] BYREF

  fgets(s, 100, stdin);
  for (unsigned int i = 0; i < strlen(s); ++i )
  {
    if (s[i] > 'A' && s[i] <= 'Z')
    {
      s[i] ^= 0x20u;
    }
  }
  printf(s);
  exit(0);
}
