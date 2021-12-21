#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int locate_chr(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}
int locate_nchr(char *str, char c,int n)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && n--)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}
void ft_putchar(char c)
{
    write (1, &c,1);
}



int inter(char *s1, char *s2)
{
    int i = 0;
    
    if (!s1 || !s2)
        return 0;
    while (s1[i])
    {
        if (locate_chr(s2, s1[i]) && !locate_nchr(s1,s1[i], i))
        {
            ft_putchar(s1[i]);
        }
        i++;
    }
    ft_putchar('\n');
    return 1;
}


int main(int argc, char *argv[])
{
    printf ("argc %d | \n", argc);
    if (argc == 1)
        ft_putchar('\n');
    else
    {
        inter(argv[argc - 2], argv[argc - 1]);
    }
    return (0);
}