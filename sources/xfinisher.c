#include "../includes/ft_printf.h"

int xfinisher(char *bullet, struct flags flagman)
{
    char *canvas;
    char *copy_bullet;
    int size;
    int sizec;
    int target;
    int copy_bullet_size;
    int countpre = flagman.prec;
    int bulletsize = strlen(bullet);

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

   if(flagman.prec == 0 && *bullet == '0' && *(bullet + 1) == '\0')
        bullet[strlen(bullet) - 1] = ' ';
    if(flagman.prec > bulletsize)
        {

            if(!(copy_bullet = (char*)malloc(sizeof(char) * flagman.prec + 1)))
                return -1;
            copy_bullet[flagman.prec] = '\0';

            while(countpre > 0)
            {
                copy_bullet[countpre - 1] = '0';
                countpre--;
            }
    //printf("IM ON\n");
    //printf("z bullet is%s fp%d sb %lu\n", zbullet, flagman.prec, strlen(bullet));
            strcpy(&copy_bullet[flagman.prec - bulletsize ] , bullet);
            //strcpy(zbullet+(flaƒgman.prec - strlen(bullet)) , bullet);
    //printf("IM ON\n");
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

    if(flagman.field > copy_bullet_size || flagman.prec < flagman.field)
    {
        size = flagman.field;
    }
    else
    {
                size = strlen(copy_bullet);
    }
    
    if(!(canvas = (char*)malloc(sizeof(char)* size + 1)))
        return -1;
    canvas[size] = '\0';
    sizec = size;

    int second_precount = flagman.prec;
    while (size >= 0)
    {  
        if(flagman.zero != -1 && second_precount)
        {
            canvas[size - 1] = '0';
            second_precount--;
        }
        else
            canvas[size - 1] = ' ';
        size--;
    }
    
    //if(flagman.prec > strlen(zbullet))
    flagman.prec = strlen(copy_bullet);

    if(flagman.minus != -1)
        target =  flagman.prec;
    else
        target  = sizec;
    // printf("target %d flagman.prec %d\n",target,flagman.prec);
    if(flagman.prec == -1)
        flagman.prec = strlen(bullet);
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