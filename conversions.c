#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct flags
{
    int minus;
    int zero;
    int field;
    int prec;
    int type;
    int flagsize;
};

char *ft_itoa(long d, struct flags flagman)
{
    int neg = 0;
    long len = 0;
    char *slot;
    long ruler = 1;

    printf("in itoa %ld\n",d);

    printf("type %c\n",flagman.type);
    if (d == -2147483648)
        return (strdup("-2147483648"));
    if(d < 0)
    {
        neg = 1;
        d = -d;
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
    slot[len + neg] = '\0';
    //printf("len%zu neg%d end is %lu\n",len, neg, len + neg - 1);
    //printf("mid log slot %s\n",slot);
    while(len > 0)
    {
        slot[--len + neg] = d % 10 + 48;
        //printf("now loading%lu:%c\n",len + neg,slot[len + neg]);
        d /= 10;
    }
    slot[0] = neg == 1 ? '-' : slot[0];
    return (slot);
}

char hexmaker(size_t x, int flag)
{
    if(x > 9 && flag == 'X')
        return (x + 55);
    
    if(x > 9)
        return (x + 87);
    return (x + 48);

    //return x;
}

int hexdigit(int d)
{
    int count = 0;

    if (d < 0)
    {
        //printf("this is minus numb \n");
        return 9;
    }
    if(d == 0)
    {
        count++;
    }
    while(d)
    {
        d /= 16;
       // printf("hexdigit%d\n",d);
        count++;
    }
    count = count + 1;
    return count;
}

char *x_con(size_t d, int flag)
{
    size_t amari = 0;
    int len = 0;
    const char loc[4] = "0x30";
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
    //printf("\nconv:length is %d\n", len);
    if(!(slot = (char*)malloc(sizeof(char)* len)))
        return NULL;
    len--;
    slot[len] = '\0';
    len--;
    while(len >= 0)
    {
      //  printf("now 16is%zu\n",d);
        amari = d % 16;
        //printf("d is %zu amari is %zu\n",d,amari);
        slot[len] = hexmaker(amari, flag);
        //printf("%d len%c::::\n",len,slot[len]);
        //printf("slot detected %c\n",slot[len]);
        //printf("\nslot is %c\n",slot[len]);
       // printf("slot len %c\n",slot[len]);
        d = d / 16;
        len --;
   //printf("perrrrfect %s\n",slot);

    }

    //printf("DOOne :perrrrfect %s\n",slot);
  //  printf("conv:slot is %s\n",slot);
    return slot;
}