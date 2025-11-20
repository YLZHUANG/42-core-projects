
int main(void)
{
  char password[96];
  char ptr[48];
  char username[96];
  int password_len;
  FILE *stream;

  memset(username, 0, sizeof(username));
  memset(ptr, 0, 41);
  memset(password, 0, sizeof(password));
  stream = 0;
  password_len = 0;

  stream = fopen("/home/users/level03/.pass", "r");
  if ( !stream )
  {
    fwrite("ERROR: failed to open password file\n", 1u, 0x24u, stderr);
    exit(1);
  }

  password_len = fread(ptr, 1u, 41, stream);
  ptr[strcspn(ptr, "\n")] = '\0';
  if ( password_len != 41 )
  {
    fwrite("ERROR: failed to read password file\n", 1u, 0x24u, stderr);
    fwrite("ERROR: failed to read password file\n", 1u, 0x24u, stderr);
    exit(1);
  }
  fclose(stream);

  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");
  printf("--[ Username: ");
  fgets(username, 100, stdin);
  username[strcspn(username, "\n")] = '\0';

  printf("--[ Password: ");
  fgets(password, 100, stdin);
  password[strcspn(password, "\n")] = '\0';

  puts("*****************************************");
  if (strncmp(ptr, password, 41) != 0)
  {
    printf(username);
    puts(" does not have access!");
    exit(1);
  }
  printf("Greetings, %s!\n", username);
  system("/bin/sh");
  return 0;
}