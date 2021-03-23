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
// int main()
// // {
// //     struct flags flagman = {0,0,10,10,-1};
// //     char bullet[200] = "11";

// //     sfinisher(flagman, bullet);
// // }

int sfinisher(struct flags flagman, char *bullet)
{
    char *camvas;

    int size;
    int sizec;
    int target;
    int sizebullet = strlen(bullet);

    // printf("\n:flags:\n\n");
    // printf("minus %d\n",flagman.minus);
    // printf("zero %d\n",flagman.zero);
    // printf("fie %d\n",flagman.field);
    // printf("prec %d\n",flagman.prec);
    // printf("type %c\n",flagman.type);
    // printf("flagsize %d\n",flagman.flagsize);
    // printf("bullet %s\n",bullet);
    // printf("\n:flagend:\n");
    if(flagman.zero == 1 && flagman.minus ==1)
        printf("ERRROR");
    
    if((flagman.prec == -1 && flagman.field == -1) || flagman.field <= sizebullet)
        size = strlen(bullet);
    else if((flagman.field > sizebullet || flagman.prec < flagman.field) && flagman.field != -1)
    {
        size = flagman.field;
    }
    else
        size = flagman.prec;

    
    if(!(camvas = (char*)malloc(sizeof(char)* size + 1)))
        return -1;
    camvas[size] = '\0';

    sizec = size;
    //printf("size %d\n",size);
    while (size >= 0)
    {
        if(flagman.zero != -1)
            camvas[size - 1] = '0';
        else 
            camvas[size - 1] = ' ';
        size--;
    }

    if(flagman.prec > sizebullet)
        flagman.prec = sizebullet;

    if(flagman.minus != -1)
        target =  flagman.prec;
    else
        target = sizec;

    // printf("target %d flagman.prec %d\n",target,flagman.prec);

    while(flagman.prec != 0)
    {
        camvas[target - 1] = bullet[flagman.prec - 1];
        // printf("camvas %c bullet %c\n",camvas[target - 1] ,bullet[flagman.prec - 1]);
        target--;
        flagman.prec--;
    }
//char mes[40] = "\nthis is what we write\n";
   // write(1,mes,30);
    // char mes[40] = "\nthis is what we write\n";
    // write(1,mes,40);
    write(1,camvas,strlen(camvas));
    free(camvas);

    return (sizec);
}