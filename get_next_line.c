#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFER_SIZE 1

char read_ch(int fd)
{
    char c_h;
    int read_return ;

    read_return  = 0;
    read_return = read(fd, &c_h, BUFFER_SIZE);
    if (read_return == -1 || read_return == 0) 
        return (0);
    return (c_h);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int len1;
    int len2;
    int i = 0;

    if (!s1 || !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    str = malloc((len1 + len2 + 1) * sizeof(char));
    if (!str)
        return (NULL);
    while (len1--)
    {
        str[i] = s1[i];
        i++;
    }
    while (len2--)
    {
        str[i] = s2[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *put_ch(char *str, char c)
{
    int len;
    char *new_str;
    int i = 0;

    if (!str)
        return (NULL);
    len =  ft_strlen(str);
    new_str = malloc((len + 2) + sizeof(char));

    while (len--)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = c;
    new_str[i+1] = '\0';
    //free(str);
    return (new_str);
}

char *ft_strdup(char *str)
{
    char *dup;
    int len;
    int i ;

    if (!str)
    return (NULL);
    i = 0;
    len = ft_strlen(str);
    dup = malloc((len + 1)* sizeof(char));
    if (!dup)
        return (NULL);
    while (len--)
    { 
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}



char *get_next_line(int fd)
{
   static char *backup;
    char c_h;
    char *line ;

    line = NULL ;
     c_h = read_ch(fd);

    //printf("buffer read : %c \n", c_h);
    if (fd == - 1 || (c_h == '\0' && !backup))
        return (NULL);
    if (c_h == '\n')
    {
        //printf("line found");
        if (!backup)
        backup = ft_strdup("");
        line  = put_ch(backup, c_h);
         //printf("first line : %s \n", line);
         //printf("first backup : %s \n", backup);
         free(backup);
         free(line);
         backup = NULL ;
    }
    else 
    {
        while (c_h != '\n' && c_h)
        {   
            if (!backup)
                backup = ft_strdup("");
            backup = put_ch(backup, c_h);
            c_h = read_ch(fd);
        }
        //printf("second line : %s \n", line);
        //printf("second backup : %s \n", backup);
         line  = put_ch(backup, c_h);
         free(backup);
         free(line);
         backup = NULL ;
    }
    return (line);
}

int main()
{
    char *str;
    int fd = open("get_next_line.c", O_RDWR);

    while ((str = get_next_line(fd)))
    {
        printf("%s \n", str);
    }
}