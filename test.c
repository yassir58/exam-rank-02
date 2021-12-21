#include <stdio.h>





int main()
{

    char *tab[5];
    int i = 0;

    tab[0] = "anas";
    tab[1] = "yassir";
    tab[2] = "yahia";
    tab[3] = "rigor";
    tab[4] = NULL;

    while(tab[i])
        printf("%s \n", tab[i++]);

}