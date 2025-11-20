
typedef struct {
    char message[140];
    char username[40];
    int max_msg_len;
} envelope_t;

void secret_backdoor(void)
{
    char s[128]; // [rsp+0h] [rbp-80h] BYREF

    fgets(s, 128, stdin);
    system(s);
    return ;
}

void set_username(envelope_t *env)
{
    char buf[140];
    int i;

    memset(buf, 0, 128);
    puts(">: Enter your username");
    printf(">>: ");

    fgets(buf, 128, stdin);

    for (i = 0; i <= 40 && s[i]; ++i)
    {
        env->username[i] = s[i];
    }
    printf(">: Welcome, %s", env->username);
    return ;
}

void set_msg(envelope_t *env)
{
    char buf[1024] = {0};

    puts(">: Msg @Unix-Dude");
    printf(">>: ");

    fgets(buf, 1024, stdin);
    strncpy(env->message, buf, env->max_msg_len);
    return ;
}

void handle_msg(void)
{
    envelope_t env = {0};

    env.max_msg_len = 140;
    set_username(env);
    set_msg(env);
    puts(">: Msg sent!");
    return ;
}

int main(void)
{
    puts("--------------------------------------------\n"
         "|   ~Welcome to l33t-m$n ~    v1337        |\n"
         "--------------------------------------------");
    
    handle_msg();
    return 0;
}
