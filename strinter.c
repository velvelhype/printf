#include <stdio.h>

struct flags
{
    int minus;
    int zero;
    int field;
    int prec;
    int type;
};

int stringter(char *bullet, struct flags *flagman)
{
    char *imp;
    imp = bullet;
    flagman->prec = 777;
    bullet++;
    int i;
    i = bullet - imp;
    printf("bullet %d\n",i);
    return *bullet;
}

int main()
{
    struct flags flagman = {0,0,0,0,0};
    char bullet[10] = "123456789";

    printf("%c\n",*bullet);
    printf("%d\n",flagman.prec);
    stringter(bullet, &flagman);
    printf("%c\n",*bullet);
    printf("%d\n",flagman.prec);
}