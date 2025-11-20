
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char test[29];
    char str[] = "Congratulations!";
    char res[] = "Q}|u`sfg~sf{}|a3";

    
    for (size_t i = 0; i <= 21; i++)
    {
        size_t len;

        strcpy(test, str);
        len = strlen(test);
        for (size_t j = 0; j < len; j++)
        {
            test[j] ^= i;
        }
        if (strcmp(test, res) == 0)
        {
            printf("value: %ld\n", i);
            return 0;
        }
    }
    return 0;
}