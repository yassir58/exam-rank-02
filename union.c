#include <stdio.h>
#include <unistd.h>


void ft_putchar(char c)
{
    write (1, &c, 1);
}

int locate_chr(char *str, char c)
{
    int i =0;

    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    } 
    return (0);
}

int locate_nchr(char *str, char c, int n)
{
    int i = 0;

    while (str[i] && n--)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void ft_union(char *st1, char *st2)
{
    int i = 0;

    while (st1[i] && st2[i])
    {
        if (!locate_nchr(st1, st1[i], i) && !locate_nchr(st2, st1[i], i+1))
            ft_putchar(st1[i]);
        if ()
            ft_putchar(st2[i]);
        i++;
    }
    ft_putchar('\n');
}


int main(int argc, char *argv[])
{
    if (argc == 1)
        ft_putchar('\n');
    if (argc == 3)
    ft_union(argv[argc - 2], argv[argc - 1]);
    return (0);
}