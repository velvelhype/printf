#include "../includes/ft_printf.h"

int dfinisher(char *bullet, struct flags flagman)
{
    char *canvas;
    char *copy_bullet;
    int size;
    int sizec;
    int target;
    int copy_bullet_size;
    int countpre = flagman.prec;
    int bulletsize = strlen(bullet);
    int hyperkineticpositionreverser = -1;

//         printf("\n:flags:\n\n");
//     printf("minus %d\n",flagman.minus);
//     printf("zero %d\n",flagman.zero);
//     printf("prec %d\n",flagman.prec);
//     printf("type %c\n",flagman.type);
//     printf("flagsize %d\n",flagman.flagsize);
//     printf("\nbullet %s\n",bullet);
//     printf("c %d\n",*bullet);
//    // printf("sizebullet %d\n",sizebullet);
//     printf("\n:flagend:\n");
           


        if(flagman.zero == 1 && flagman.field > bulletsize && *bullet == '-' && flagman.prec == -1)
    {
        hyperkineticpositionreverser = 1;
        *bullet = '0';
    }

    if(flagman.field <= 1 && flagman.prec == 0 && bulletsize == 1 && *bullet  == '0')
    {
        write(1,NULL,1);
        return 0;
    }

   if(flagman.prec == 0 && *bullet == '0' && *(bullet + 1) == '\0')
        bullet[strlen(bullet) - 1] = ' ';

    if(flagman.prec >= bulletsize && *bullet == '-')
    {
        if(!(copy_bullet = (char*)malloc(sizeof(char) * flagman.prec + 2)))
            return -1;
        copy_bullet[flagman.prec + 1] = '\0';
        countpre++;
            while(countpre > 0)
            {
                copy_bullet[countpre - 1] = '0';
                countpre--; 
            }
        strcpy(&copy_bullet[flagman.prec - bulletsize + 2] , bullet + 1);
        *copy_bullet = '-';
    }
    else if(flagman.prec > bulletsize)
        {

            if(!(copy_bullet = (char*)malloc(sizeof(char) * flagman.prec + 1)))
                return -1;
            copy_bullet[flagman.prec] = '\0';

            while(countpre > 0)
            {
                copy_bullet[countpre - 1] = '0';
                countpre--;
            }
            strcpy(&copy_bullet[flagman.prec - bulletsize ] , bullet);
        }
    else
        copy_bullet = strdup(bullet);

//     if(flagman.zero == 1 && flagman.minus == 1)
//         return -1;
    //printf("\nbullet %s\n",bullet);

    if(flagman.prec == -1)
        size = strlen(copy_bullet);

    copy_bullet_size = strlen(copy_bullet);

    if( flagman.prec < flagman.field && flagman.field > copy_bullet_size)
        size = flagman.field;
    else
        size = strlen(copy_bullet);

    if(!(canvas = (char*)malloc(sizeof(char)* size + 1)))
        return -1;
    canvas[size] = '\0';
    sizec = size;

    int second_precount = flagman.prec;

    while (size > 0)
    {  
        if(flagman.zero == 1 && second_precount)
        {
            canvas[size - 1] = '0';
            second_precount--;
        }
        else
        {
            canvas[size - 1] = ' ';
        }
        size--;
    }

    flagman.prec = strlen(copy_bullet);

    if(flagman.minus != -1)
    {
        target =  flagman.prec;
        if(hyperkineticpositionreverser == 1)
        target++;
    }
    else
        target  = sizec;
    if(flagman.prec == -1)
        flagman.prec = strlen(bullet);


    if(hyperkineticpositionreverser == 1)
        *canvas = '-';
    while(flagman.prec != 0)
    {
        canvas[target - 1] = copy_bullet[flagman.prec - 1];
        target--;
        flagman.prec--;
    }
    if(hyperkineticpositionreverser == 1)
        *canvas = '-';


    write(1,canvas,strlen(canvas));
    free(canvas);
    free(copy_bullet);


    return (sizec);
}
