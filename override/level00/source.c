int main(void)
{
    int value;

    puts("***********************************");
    puts("* \t     -Level00 -\t\t *");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &value);
    if (value == 5276)
    {
        puts("\nAuthenticated!");
        system("/bin/sh");
        return 0;
    }
    puts("\nInvalid Password!");
    return 1;
}