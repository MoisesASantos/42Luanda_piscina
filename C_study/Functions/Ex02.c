#include <stdio.h>

int find_substring(const char *s1, const char *s2)
{
    int i = 0;
    char *p, *p2;

    for(i = 0; s1[i]; i++)
    {
        p = &s1[i];
        p2 = s2;
        while(*p2 && *p == *p2)
        {
            p++;
            p2++;
        }
        if(*p2 == '\0')
        {
            return (i);
        }
    }
    return (-1);
}
int main(void)
{
    if(find_substring("Adolfo abc", "abc") != -1)
    {
        printf("Não Encontrou\n");
    }
    return (0);
}