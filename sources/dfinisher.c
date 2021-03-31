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

    // printf("\n:flags:\n\n");
    // printf("minus %d\n",flagman.minus);
    // printf("zero %d\n",flagman.zero);
    // printf("fie %d\n",flagman.field);
    // printf("prec %d\n",flagman.prec);
    // printf("type %c\n",flagman.type);
    // printf("flagsize %d\n",flagman.flagsize);
    // printf("bullet %s\n",bullet);
    // printf("\n:flagend:\n"); 


   //if(flagman.prec != -1 && flagman.prec > bulletsize)
    //     if(bulletsize <= flagman.prec && *bullet == '-' && flagman.minus != 1)
    // {
    //     hyperkineticpositionreverser = 1;
    //     *bullet = '0';
    // }
    //     if(flagman.field > bulletsize && *bullet == '-' && flagman.minus != 1)
    // {
    //     hyperkineticpositionreverser = 1;
    //     *bullet = '0';
    // }

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
    // if(bulletsize <= flagman.prec && *bullet == '-')
    //     copy_bullet[flagman.prec - bulletsize ] = '0';
        }
    else
        copy_bullet = strdup(bullet);

    if(flagman.zero == 1 && flagman.minus == 1)
        return -1;

    if(flagman.prec == -1)
    {
        size = strlen(copy_bullet);
    }

    copy_bullet_size = strlen(copy_bullet);

    //originalif(flagman.field > copy_bullet_size || flagman.prec < flagman.field)
    if( flagman.prec < flagman.field && flagman.field > copy_bullet_size)
    {
        size = flagman.field;
    }
    else
    {
        size = strlen(copy_bullet);
    }

    //printf("size %d\n",size);
    // if(bulletsize <= flagman.prec && *bullet == '-')
    // {
    //     hyperkineticpositionreverser = 1;
    // }
    // if(flagman.field > bulletsize && *bullet == '-')
    // {
    //     hyperkineticpositionreverser = 1;
    // }
    if(!(canvas = (char*)malloc(sizeof(char)* size + 1)))
        return -1;
    canvas[size] = '\0';
    sizec = size;
    // printf("aftermath %s\n",copy_bullet);

    int second_precount = flagman.prec;
    // while (size >= 0)
    // {  
    //     if(flagman.zero == 1 && second_precount)
    //     {
    //         canvas[size - 1] = '0';
    //         second_precount--;
    //     }
    //     else
    //     {
    //         canvas[size - 1] = ' ';
    //     }
    //     size--;
    //     printf("%d aftermath %s\n", size, copy_bullet);
    // }
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

    //if(flagman.prec > strlen(zbullet))
    flagman.prec = strlen(copy_bullet);

    if(flagman.minus != -1)
    {
        target =  flagman.prec;
        if(hyperkineticpositionreverser == 1)
        target++;
    }
    else
    {
        target  = sizec;
    }
    // printf("target %d flagman.prec %d\n",target,flagman.prec);
    if(flagman.prec == -1)
        flagman.prec = strlen(bullet);

    if(hyperkineticpositionreverser == 1)
    {
        *canvas = '-';
    }
    // printf("target %d prec %d cb %s\n",target , flagman.prec, copy_bullet);
    while(flagman.prec != 0)
    {
        canvas[target - 1] = copy_bullet[flagman.prec - 1];
        target--;
        flagman.prec--;
    }
    // char mes[40] = "\nthis is what we write\nmin_ver:";
    // write(1,mes,40);
    write(1,canvas,strlen(canvas));
    free(canvas);
    free(copy_bullet);
    //printf("ori:%*.*s",flagman.field , flagman.prec, zbullet);
    return (sizec);
}

// int main()
// {
//     struct flags flagman = {-1,1,10,10,-1};
//     char bullet[200] = "12345";
//     dfinisher(bullet, flagman);
// }