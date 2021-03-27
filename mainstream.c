#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

struct flags
{
    int minus;
    int zero;
    int field;
    int prec;
    int type;
    int flagsize;
};

char *ft_itoa(long d, struct flags flagman);
char* x_con(int d, int flag);
struct flags flagmaker(struct flags flagman, char *fmt, va_list ap);
int dfinisher(char *bullet, struct flags flagman);
int xfinisher(char *bullet, struct flags flagman);
int sfinisher(struct flags flagman, char *bullet);



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
                bullet = (char*)malloc(sizeof(char)*2);
                *bullet = c;
                howmanywewrite += sfinisher(flagman, bullet);
            }
            if (*p == 's')
            {
                bullet = va_arg(ap, char *);
                howmanywewrite += sfinisher(flagman, bullet);
            }
            if (*p == 'p')
            {
                bullet = x_con(va_arg(ap, size_t), 'p');
                howmanywewrite += dfinisher(bullet, flagman);
                free (bullet);

            }
            if (*p == 'd')  
            {
                bullet = ft_itoa(va_arg(ap, int), flagman);
                howmanywewrite += dfinisher(bullet, flagman);
                free (bullet);
            }
            if (*p == 'i')
            {
                bullet = ft_itoa(va_arg(ap, int), flagman);                
                howmanywewrite += dfinisher(bullet, flagman);
                free (bullet);

            }
            if (*p == 'u')
            {
                printf("on\n");
                uvalue = va_arg(ap, long);
                printf("uvalue us %zu\n", uvalue);

                bullet = ft_itoa(uvalue, flagman);
                howmanywewrite += dfinisher(bullet, flagman);
                free (bullet);
            }
            if (*p == 'x')
                {
                bullet = x_con(va_arg(ap, long), 'x');
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
            if (*p == '%')
            {
                write(1,p,1);
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

int main()
{
    printf(":%-3.10u\n",-54321);
 ft_printf(":%-3.10u\n",-54321);
}

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
    

//     ft_printf("min%0i%010u%05X%05x\n",1234,1234,124,124);
//        printf("ori%0i%010u%05X%05x\n",1234,1234,124,124);
//        printf("ori%05X%05x\n",127,127);
//     ft_printf("min%05X%05x\n",127,127);
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

// //   printf("ori%%%10.7d%2.1d%3.2s\n",22244,12,"hage");
// // printf("mincount %d\n ",minprintf("s min_ver:\n%14c\n", 'Q'));
// //     printf("oricount %d\n ",printf("s ori_ver:\n%14c\n", 'Q'));
// // printf("min ret%d\n",minprintf("min_ver:%*.*s\n",2,2,stn));
// // printf("ori ret%d\n",   printf("ori_ver:%*.*s\n",2,2,stn));
// // printf("min ret%d\n",minprintf("min_ver:%*.*s\n",6,6,stn));
// // printf("ori ret%d\n",   printf("ori_ver:%*.*s\n",6,6,stn));
// // printf("min ret%d\n",minprintf("min_ver:%*.*s\n",7,7,stn));
// // printf("ori ret%d\n",   printf("ori_ver:%*.*s\n",7,7,stn));
// // printf("min ret%d\n",minprintf("min_ver:%*s\n",2,stn));
// // printf("ori ret%d\n",   printf("ori_ver:%*s\n",2,stn));
// // printf("min ret%d\n",minprintf("min_ver:%*s\n",6,stn));
// // printf("ori ret%d\n",   printf("ori_ver:%*s\n",6,stn));
// // printf("min ret%d\n",minprintf("min_ver:%*s\n",7,stn));
// // printf("ori ret%d\n",   printf("ori_ver:%*s\n",7,stn));

// // minprintf("d min_ver:%*.*x\n",10,20,&stn);
// //         printf("d ori_ver:\n%*.*x\n",10,20, &stn);
// // printf("min ret%d\n",minprintf("Themin_ver:%1.*s\n",2,stn));
// // printf("ori ret%d\n",   printf("Theori_ver:%1.*s\n",2,stn));
// // printf("min ret%d\n",minprintf("smin_ver:%.*s\n",4,stn));
// // printf("ori ret%d\n",   printf("sori_ver:%.*s\n",4,stn));
// // printf("min ret%d\n",minprintf("smin_ver:%.*s\n",6,stn));
// // printf("ori ret%d\n",   printf("sori_ver:%.*s\n",6,stn));
// // printf("min ret%d\n",minprintf("smin_ver:%.*s\n",7,stn));
// // printf("ori ret%d\n",   printf("sori_ver:%.*s\n",7,stn));
// // printf("min ret%d\n",minprintf("smin_ver:%.*s\n",2,stn));
// // printf("ori ret%d\n",   printf("doneori_ver:%.*d\n",2,ssn));
// // printf("min ret%d\n",minprintf("dmin_ver:%.*d\n",4,ssn));
// // printf("ori ret%d\n",   printf("dori_ver:%.*d\n",4,ssn));
// // printf("min ret%d\n",minprintf("dmin_ver:%.*d\n",6,ssn));
// // printf("ori ret%d\n",   printf("dori_ver:%.*d\n",6,ssn));
// // printf("min ret%d\n",minprintf("dmin_ver:%.*d\n",7,ssn));
// // printf("ori ret%d\n",   printf("dori_ver:%.*d\n",7,ssn));
// // printf("min ret%d\n",minprintf("d min_ver:%02.2s\n",stn));
// // printf("ori ret%d\n",   printf("d ori_ver:%02.2s\n",stn));
//     // system("leaks a.out");
//     // char *b = "Congrats!";
//     // char *c = "Congrats!";
//     // char *d = "Congrats!";
//     // unsigned int i = 10;
//     //  int n = 10;
//     //  int e = 10;
//     // unsigned int *t;
//     // int w = -121212121;
//     // int *o;
//     // t = &i;
//     // w = &n;
//     // o = &e;

//     return 0;
// }