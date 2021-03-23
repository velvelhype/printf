#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

char* dcon(int d);
char* xcon(int d, int flag);
struct flags flagmaker(struct flags flagman, char *fmt, va_list ap);
int dfinisher(char *bullet, struct flags flagman);
int sfinisher(struct flags flagman, char *bullet);

struct flags
{
    int minus;
    int zero;
    int field;
    int prec;
    int type;
    int flagsize;
};

int minprintf(char *fmt, ...)
{
    va_list ap;
    struct flags flagman = {-1, -1, -1, -1, -1, 0};
    char *bullet;
    char *p, *sval;
    char *twinbite;
    va_start(ap, fmt);
    int howmanywewrite;

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
                free(bullet);
                *bullet = c;
                howmanywewrite += sfinisher(flagman, bullet);
                // write(1, &c, 1);
                // write(1, va_arg(ap, char*), 3);
                // howmanywewrite++;
            }
            if (*p == 's')
            {
                bullet = va_arg(ap, char *);
                howmanywewrite += sfinisher(flagman, bullet);
            }
            if (*p == 'p')
            {
                bullet = xcon(va_arg(ap, size_t), 'p');
                howmanywewrite += dfinisher(bullet, flagman);
            }
            if (*p == 'd')  
            {
                bullet = dcon(va_arg(ap, int));
                howmanywewrite += dfinisher(bullet, flagman);
            }
            if (*p == 'i')
            {
                bullet = dcon(va_arg(ap, int));                
                howmanywewrite += dfinisher(bullet, flagman);

            }
            if (*p == 'u')
            {
                bullet = dcon(va_arg(ap, int));                
                howmanywewrite += dfinisher(bullet, flagman);
            }
            if (*p == 'x')
                {
                bullet = xcon(va_arg(ap, size_t), 'x');
                howmanywewrite += dfinisher(bullet, flagman);
                }
            if (*p == 'X')
            {
                bullet = xcon(va_arg(ap, size_t), 'X');
                howmanywewrite += dfinisher(bullet, flagman);
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
    // minprintf("min_ver:%9d\n",13);
    //    printf("ori_ver:\n%9d\n",13);
    char stn[200] = "12345";
    int ssn = 12345;
    

    //minprintf("min%%%10.7d%2.1d%3.2s\n",22244,12,"hage");
    

    minprintf("min%10.7d\n",22244);
       printf("ori%10.7d\n",22244);
       printf("min%%%10.7d%2.1d\n",22244,12);
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
// printf("min ret%d\n",minprintf("Themin_ver:%1.*s\n",2,stn));
// printf("ori ret%d\n",   printf("Theori_ver:%1.*s\n",2,stn));
// printf("min ret%d\n",minprintf("smin_ver:%.*s\n",4,stn));
// printf("ori ret%d\n",   printf("sori_ver:%.*s\n",4,stn));
// printf("min ret%d\n",minprintf("smin_ver:%.*s\n",6,stn));
// printf("ori ret%d\n",   printf("sori_ver:%.*s\n",6,stn));
// printf("min ret%d\n",minprintf("smin_ver:%.*s\n",7,stn));
// printf("ori ret%d\n",   printf("sori_ver:%.*s\n",7,stn));
// printf("min ret%d\n",minprintf("smin_ver:%.*s\n",2,stn));
// printf("ori ret%d\n",   printf("doneori_ver:%.*d\n",2,ssn));
// printf("min ret%d\n",minprintf("dmin_ver:%.*d\n",4,ssn));
// printf("ori ret%d\n",   printf("dori_ver:%.*d\n",4,ssn));
// printf("min ret%d\n",minprintf("dmin_ver:%.*d\n",6,ssn));
// printf("ori ret%d\n",   printf("dori_ver:%.*d\n",6,ssn));
// printf("min ret%d\n",minprintf("dmin_ver:%.*d\n",7,ssn));
// printf("ori ret%d\n",   printf("dori_ver:%.*d\n",7,ssn));
// printf("min ret%d\n",minprintf("d min_ver:%02.2s\n",stn));
// printf("ori ret%d\n",   printf("d ori_ver:%02.2s\n",stn));
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

    return 0;
}