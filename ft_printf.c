#include "ft_printf.h"

int ft_printf(char *fmt, ...)
{
    va_list ap;
    struct flags flagman = {-1, -1, -1, -1, -1, 0};
    char *bullet;
    char *p;
    va_start(ap, fmt);
    int howmanywewrite;
    int bsize;
    long uvalue;
    char null[7] = "(null)";

    howmanywewrite = 0;
    p = fmt;
    while (*p != '\0')
    {
        if (*p == '%')
        {

            p++;
            flagman = flagmaker(flagman, p, ap);//pointer wo susumeru hituyou            
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
                bullet = x_con(va_arg(ap, size_t), 'x');
                bsize = strlen(bullet);
                if(bsize > flagman.field)
                    flagman.field = bsize;
                howmanywewrite += xfinisher(bullet, flagman);
                free (bullet);

                }
            if (*p == 'X')
            {
                bullet = x_con(va_arg(ap, size_t), 'X');
                bsize = strlen(bullet);
                if(bsize > flagman.field)
                    flagman.field = bsize;
                howmanywewrite += xfinisher(bullet, flagman);
                free (bullet);
            }
            if (*p == 'p')
            {
                char *unified_bullet;
                const char loc[3] = "0x";
                if(flagman.prec == 0)
                {
                    bullet = (char*)malloc(sizeof(char) * 1);
                    *bullet = '\0';
                }
                else
                    bullet = x_con(va_arg(ap, size_t), 'p');
                // if(*bullet == '0' && *(bullet + 1) == '\0')
                // {
                //     free(bullet);
                //     bullet = (char*)malloc(sizeof(char) * 1);
                //     *bullet = '\0';
                // }
                //printf("bullet%s\n",bullet);
                unified_bullet = ft_strjoin(loc, bullet);
                howmanywewrite += xfinisher(unified_bullet, flagman);
                free (bullet);
                free(unified_bullet);
            }
            if (*p == '%')
            {
                bullet = (char*)malloc(sizeof(char) * 2);
                *bullet = '%';
                *(bullet + 1) = '\0';
                //printf("\nbullet %s\n",bullet);
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

// int main()
//  {
//      printf(":%-21c\n",'X');
//   ft_printf(":%-21c\n",'X');
//      printf(":%3c\n",'X');
//   ft_printf(":%3c\n",'X');
//      printf(":%-3c\n",'X');
//   ft_printf(":%-3c\n",'X');
//      printf(":%3c\n",'X');
//   ft_printf(":%3c\n",'X');
//     printf(":ori %2c\n",'X');
//  ft_printf(":min %2c\n",'X');
// }

// int main()
// {
//     printf("test 54321\n");
//         printf("%.10d\n",54321);
//      ft_printf("%.*d\n",10,54321);
//      ft_printf("%.10d\n",54321);
// }
// int main()
// {
//     // minprintf("min_ver:%9d\n",13);
//     //    printf("ori_ver:\n%9d\n",13);
//     //minprintf("min%%%10.7d%2.1d%3.2s\n",22244,12,"hage");
//     int a;

//     printf("%d\n",ft_printf("min%0i%010u%05X%05x\n",1234,1234,124,124) - printf("ori%0i%010u%05X%05x\n",1234,1234,124,124));
//     printf("%d\n",ft_printf("ori%p\n",&a) - printf("ori%p\n",&a));

//        printf("ori%0i%010u%05X%05x\n",1234,1234,124,124);
//        printf("ori%5s%5s\n","127","127");
//     ft_printf("min%5s%5s\n","127","127");
//        printf("ori%05X\n",127);
//     ft_printf("min%05X\n",127);
//        printf("ori%05X\n",222222);
//     ft_printf("min%05X\n",222222);
//        printf("ori%05X\n",42222222);
//     ft_printf("min%05X\n",42222222);
//        printf("ori%05X\n",222222224);
//     ft_printf("min%05X\n",222222224);
//        printf("ori%05X\n",2);
//     ft_printf("min%05X\n",2);

//   printf("ori%%%10.7d%2.1d%3.2s\n",22244,12,"hage");
// printf("mincount %d\n ",minprintf("s min_ver:\n%14c\n", 'Q'));
//     printf("oricount %d\n ",printf("s ori_ver:\n%14c\n", 'Q'));
// printf("min ret%d\n",minprintf("min_ver:%*.*s\n",2,2,stn));
// printf("ori ret%d\n",   printf("ori_ver:%*.*s\n",2,2,stn));
// printf("min ret%d\n",minprintf("min_ver:%*.*s\n",6,6,stn));
// printf("ori ret%d\n",   printf("ori_ver:%*.*s\n",6,6,stn));
// printf("min ret%d\n",minprintf("min_ver:%*.*s\n",7,7,stn));
// printf("ori ret%d\n",   printf("ori_ver:%*.*s\n",7,7,stn));
// printf("min ret%d\n",minprintf("min_ver:%*s\n",2,stn));
// printf("ori ret%d\n",   printf("ori_ver:%*s\n",2,stn));
// printf("min ret%d\n",minprintf("min_ver:%*s\n",6,stn));
// printf("ori ret%d\n",   printf("ori_ver:%*s\n",6,stn));
// printf("min ret%d\n",minprintf("min_ver:%*s\n",7,stn));
// printf("ori ret%d\n",   printf("ori_ver:%*s\n",7,stn));

// minprintf("d min_ver:%*.*x\n",10,20,&stn);
//         printf("d ori_ver:\n%*.*x\n",10,20, &stn);

    // system("leaks a.out");
    // char *b = "Congrats!";
    // char *c = "Congrats!";
    // char *d = "Congrats!";
    // unsigned int i = 10;
    //  int n = 10;
    //  int e = 10;
    // unsigned int *t;
    // int w = -121212121;
    // int *o;
    // t = &i;
    // w = &n;
    // o = &e;

//     return 0;
// }