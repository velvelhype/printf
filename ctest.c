#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

//int system(const char *command);

int twocaller(char *fmt,va_list ap)
{
    printf("%d\n",va_arg(ap, int));
    printf("%d\n",va_arg(ap, int));
    printf("%d\n",va_arg(ap, int));
    printf("%d\n",va_arg(ap, int));
    printf("%d\n",va_arg(ap, int));
    printf("%d\n",va_arg(ap, int));

    return 0;
}

int listcaller(char *fmt,...)
{
    va_list ap;
    va_start(ap, fmt);

    twocaller(fmt,ap);
    
    return 0;

}

int main()
{

    int a = 'x';
    char b[2] = "x";
    char *c;
    
    listcaller("***",10,20,30);

   // system("leaks a.out");
    return 0;

}