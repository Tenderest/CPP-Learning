#include <stdio.h>
int main(void)
{
    int i;
    char s[8];

    scanf("%s", s);

    printf("#%s#\n", s);

    for (i = 0; i <= 8; i++)
    {
        printf("%c\n", s[i]);
    }

    return 0;
}
