#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *ft_itoa(int d)
{
    int neg = 0;
    size_t len = 0;
    char *slot;

    size_t ruler = 1;
    size_t count = 0;

    if (d == -2147483648)
        return (strdup("-2147483648"));
    if(d < 0)
    {
        neg = 1;
        d = -1 * d;
    }
    if(d < 10)
        len = 1;
    while(ruler < d && d > 10)
    {
        ruler *= 10;
        len++;
    }

    if(!(slot = (char*)malloc(sizeof(char)* len + neg + 1)))
         return (NULL);
    free(slot);
    slot[len + neg] = '\0';
    while(len > 0)
    {
        slot[--len + neg] = d % 10 + 48;
        d /= 10;
    }
    slot[0] = neg == 1 ? '-' : slot[0];
    return (slot);
}

char* dcon(int d)
{
    int count = 0;
    unsigned int dx = 0;
    return(ft_itoa(d));
}

char hexmaker(size_t x, int flag)
{
    if(x > 9 && flag == 'X')
        return (x + 55);
    if(x > 9)
        return (x + 87);
    return (x + 48);

    return x;
}

int hexdigit(int d)
{
    int count = 0;

    if (d < 0)
    {
        //printf("this is minus numb \n");
        return 9;
    }
    while(d)
    {
        d /= 16;
        count++;
    }
    count = count + 1;

    return count;
}

char *xcon(size_t d, int flag)
{
    size_t amari = 0;
    size_t shou = 0;
    size_t len = 0;
    char loc[4] = "0x30";
    char *slot;

    if(flag == 'p')
        write(1,&loc,4);
    if(d < 0)
    {
        //printf("heywattttt\n");
        d = 4294967295 + d;
       // printf("minus:not ori %x\n", d);
    }
    len = hexdigit(d);
    //printf("len is %zu\n", len);
    if(!(slot = (char*)malloc(sizeof(char)* len)))
        return NULL;
    free(slot);
    slot[len] = '\0';
    len--;

    while(len--)
    {
        amari = d % 16;
        //printf("d is %zu amari is %zu\n",d,amari);
        slot[len] = hexmaker(amari, flag);
        d = d / 16;
    }

    return slot;
}