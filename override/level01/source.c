
char a_user_name[64] = {};

bool verify_user_name(void)
{
    puts("verifying username....\n");
    return (memcmp(a_user_name, "dat_wil", 7) != 0);
}

bool verify_user_pass(const char *pass)
{
    return (memcmp(pass, "admin", 5) != 0);
}

int main(void)
{
    char pass[64];
    bool check;

    memset(pass, 0, sizeof(s));
    check = false;
    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(a_user_name, 256, stdin);
    check = verify_user_name();
    if (check == true)
    {
        puts("nope, incorrect username...\n");
    }
    else
    {
        puts("Enter Password: ");
        fgets(pass, 100, stdin);
        check = verify_user_pass(pass);
        puts("nope, incorrect password...\n");
    }
    return 1;
}