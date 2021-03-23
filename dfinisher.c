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

int dfinisher(char *bullet, struct flags flagman)
{
    char *camvas;
    char *zbullet;
    int iullet = 12345;
    int size;
    int sizec;
    int ztarget;
    int target;
    int zbulletsize;
    int countpre = flagman.prec;

    // printf("\n:flags:\n\n");
    // printf("minus %d\n",flagman.minus);
    // printf("zero %d\n",flagman.zero);
    // printf("fie %d\n",flagman.field);
    // printf("prec %d\n",flagman.prec);
    // printf("type %c\n",flagman.type);
    // printf("flagsize %d\n",flagman.flagsize);
    // printf("bullet %s\n",bullet);
    // printf("\n:flagend:\n");



   if(flagman.prec != -1 && flagman.prec > strlen(bullet))
        {

            if(!(zbullet = (char*)malloc(sizeof(char) * flagman.prec + 1)))
                return -1;
            zbullet[flagman.prec] = '\0';

            while(countpre >= 0)
            {
                zbullet[countpre - 1] = '0';
                countpre--;
            }
    printf("IM ON\n");
    printf("z bullet is%s fp%d sb %lu\n", zbullet, flagman.prec, strlen(bullet));
            //strcpy(&zbullet[flagman.prec - strlen(bullet)] , bullet);
            strcpy(zbullet+(flagman.prec - strlen(bullet)) , bullet);
    printf("IM ON\n");

        }
    else
        zbullet = strdup(bullet);

    printf("ihi cleared\n");

    if(flagman.zero == 1 && flagman.minus == 1)
        return -1;

    if(flagman.prec == -1)
    {
        size = strlen(zbullet);
    }
 
    zbulletsize = strlen(zbullet);

    if(flagman.field > zbulletsize || flagman.prec < flagman.field)
    {
        size = flagman.field;
    }
    else
        size = strlen(zbullet);
    
    if(!(camvas = (char*)malloc(sizeof(char)* size + 1)))
        return -1;
    camvas[size] = '\0';

    sizec = size;

    while (size >= 0)
    {  
        if(flagman.zero != -1)
            camvas[size - 1] = '0';
        else 
            camvas[size - 1] = ' ';
        size--;
    }

    //if(flagman.prec > strlen(zbullet))
    flagman.prec = strlen(zbullet);

    if(flagman.minus != -1)
        target =  flagman.prec;
    else
        target = sizec;
    // printf("target %d flagman.prec %d\n",target,flagman.prec);
    if(flagman.prec == -1)
        flagman.prec = strlen(bullet);
    while(flagman.prec != 0)
    {
        camvas[target - 1] = zbullet[flagman.prec - 1];
        target--;
        flagman.prec--;
    }
    // char mes[40] = "\nthis is what we write\nmin_ver:";
    // write(1,mes,40);
    write(1,camvas,strlen(camvas));

    free(camvas);
    free(zbullet);
    //printf("ori:%*.*s",flagman.field , flagman.prec, zbullet);

    return (sizec);
}

// int main()
// {
//     struct flags flagman = {-1,1,10,10,-1};
//     char bullet[200] = "12345";

//     dfinisher(bullet, flagman);
// }