#include "ft_printf.h"

int ft_printf(char *fmt, ...)
{
    va_list ap;
    struct flags flagman = {-1, -1, -1, -1, -1, 0};
    char *bullet;
    char *p;
    va_start(ap, fmt);
    int howmanywewrite;
    long uvalue;
    char null[7] = "(null)";

    howmanywewrite = 0;
    p = fmt;
    while (*p != '\0')
    {
        if (*p == '%')
        {
            p++;
            flagman = flagmaker(flagman, p, ap);    
            p += flagman.flagsize;

            if (*p == 'c')
            {
                char c = va_arg(ap, int);
                bullet = (char*)malloc(sizeof(char) * 2);
                *bullet = c;
                *(bullet + 1) = '\0';
                if(flagman.prec == 0)
                    flagman.prec = 1;
                howmanywewrite += sfinisher(flagman, bullet);
                free (bullet);
            }
            if (*p == 's')
            {
                bullet = va_arg(ap, char *);
                if(bullet == NULL)
                {
                    howmanywewrite += sfinisher(flagman, null);
                }
                else
                    howmanywewrite += sfinisher(flagman, bullet);
            }
            if (*p == 'd')  
            {
                bullet = ft_itoa(va_arg(ap, int));

                howmanywewrite += dfinisher(bullet, flagman);
                free (bullet);
            }

            if (*p == 'i')
            {
                bullet = ft_itoa(va_arg(ap, int));                
                howmanywewrite += dfinisher(bullet, flagman);
                free (bullet);

            }
            if (*p == 'u')
            {
                uvalue = va_arg(ap, long);
                bullet = ft_itoa(uvalue);
                howmanywewrite += dfinisher(bullet, flagman);
                free (bullet);
            }
            if (*p == 'x')
                {
                bullet = x_con(va_arg(ap, long), 'x');
                //printf(" bullet is %s\n",bullet);
                //bsize = strlen(bullet);
                // if(bsize > flagman.field)
                //     flagman.field = bsize;
                howmanywewrite += dfinisher(bullet, flagman);

                free (bullet);

                }
            if (*p == 'X')
            {
                bullet = x_con(va_arg(ap, size_t), 'X');
                //bsize = strlen(bullet);
                // if(bsize > flagman.field)
                //     flagman.field = bsize;
                howmanywewrite += dfinisher(bullet, flagman);
                free (bullet);
            }
            if (*p == 'p')
            {
                char *unified_bullet;
                const char loc[3] = "0x";
                bullet = x_con(va_arg(ap, size_t), 'x');
                if(*bullet == '0' && *(bullet + 1) == '\0' && flagman.prec == 0)
                    unified_bullet = strdup(loc);
                else
                    unified_bullet = ft_strjoin(loc, bullet);
                howmanywewrite += dfinisher(unified_bullet, flagman);
                free(bullet);
                free(unified_bullet);
            }
            if (*p == '%')
            {
                bullet = (char*)malloc(sizeof(char) * 2);
                *bullet = '%';
                *(bullet + 1) = '\0';
                howmanywewrite += sfinisher(flagman, bullet);
                free (bullet);
            }
        }
        else
        {
            write(1 ,p, 1);
            howmanywewrite++;
        }
        p++;
    }
    va_end(ap);
    return howmanywewrite;
}
