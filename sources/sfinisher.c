#include "../includes/ft_printf.h"

// int main()
// // {
// //     struct flags flagman = {0,0,10,10,-1};
// //     char bullet[200] = "11";

// //     sfinisher(flagman, bullet);
// // }

int sfinisher(struct flags flagman, char *bullet)
{
    char *canvas;

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
    // printf("sizebullet %d\n",sizebullet);
    // printf("\n:flagend:\n");

    if(flagman.zero == 1 && flagman.minus ==1)
        printf("ERRROR");
    
    //if(flagman.prec == -1 && flagman.field == -1 && flagman.field <= sizebullet)
    // if(flagman.prec > sizebullet && flagman.prec > flagman.field)
    //     flagman.field = flagman.prec;
    if((flagman.prec == -1 && flagman.field <= sizebullet) || (flagman.prec > sizebullet && flagman.prec > flagman.field && flagman.field != -1))
        size = strlen(bullet);
    else if((flagman.field > sizebullet || flagman.prec < flagman.field) && flagman.field != -1)
    {
        size = flagman.field;
    }
    else
    {
        size = flagman.prec;
    }
    if(!(canvas = (char*)malloc(sizeof(char)* size + 1)))
        return -1;
    canvas[size] = '\0';
    sizec = size;
    // printf("size %d\n",size);
    while (size >= 0)
    {
        if(flagman.zero != -1)
            canvas[size - 1] = '0';
        else 
            canvas[size - 1] = ' ';
        size--;
    }
    //if(flagman.prec != -1 && flagman.prec < sizebullet)
    if(flagman.prec != -1)
    {
        if(flagman.field != -1)
        {
            if(flagman.prec < sizebullet)
                sizebullet = flagman.prec;
        }
        else
            sizebullet = flagman.prec;
    }

    if(flagman.minus != -1 && flagman.field > 0)
    {
        if(flagman.prec != -1 && flagman.prec < sizebullet)
            target =  flagman.prec;
        else
            target = sizebullet;
    }
    else
        target = sizec;
    
    // printf("target %d sbullet %d\n",target, sizebullet);
    while(sizebullet > 0)
    {
        canvas[target - 1] = bullet[sizebullet - 1];
        // printf("canvas %d bullet %d\n",target - 1 ,sizebullet - 1);
        target--;
        sizebullet--;
    }
    write(1, canvas, strlen(canvas));
    free(canvas);

    return (sizec);
}