#include "../includes/ft_printf.h"

char *ft_itoa(size_t e)
{
    int neg = 0;
    long len = 0;
    char *slot;
    long ruler = 1;
    long d = e;

    if (d == -2147483648)
        return (strdup("-2147483648"));
    if(d < 0)
    {
        neg = 1;
        d = -d;
    }
    if(d < 10)
        len = 1;
    while(ruler <= d && d >= 10)
    {
        ruler *= 10;
        len++;
    }

    if(!(slot = (char*)malloc(sizeof(char)* len + neg + 1)))
         return (NULL);
    slot[len + neg] = '\0';
    // printf("len%zu neg %d end\n",len, neg);
    //printf("mid log slot %s\n",slot);
    while(len > 0)
    {
        slot[--len + neg] = d % 10 + 48;
        // printf("now loading%lu:%c\n",len + neg, slot[len + neg]);
        d /= 10;
    }
    // printf("end loading %s\n", slot);
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

int hexdigit(size_t d)
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
    char *slot;

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
        // printf("now 16is%zx\n",d);
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
    // printf("conv:slot is %s\n",slot);
    return slot;
}