#include "ft_printf.h"
int main()
{
    int a;
printf("ft\n");
ft_printf("%5.d...\n", 0);
printf("ori\n");
   printf("%5.d...\n", 0);
   printf("%5.0d...\n", 0);
   printf("%5.d...\n", 1);
   printf("%5.0d...\n", 1);
ft_printf("%5.0d, %5.0d\n", 0, 0);
   printf("%5.0d, %5.0d\n", 0, 0);
 ft_printf("%1.0d, %5.0d\n", 0, 0);
   printf("%0.0d, %5.0d\n", 0, 0);

   //printf("%8.5x\n", 34);

    // printf("-4.7\n");
    // ft_printf("%-4.7s\n", "hello");
    // printf("%-4.7s\n", "hello");
    // printf("-5.7\n");
    // ft_printf("%-5.7s\n", "hello");
    // printf("%-5.7s\n", "hello");
    // printf("5.7\n");
    // ft_printf("%5.7s\n", "hello");
    // printf("%5.7s\n", "hello");
    // printf("7\n");
    // ft_printf("%7s\n", "hello");
    // printf("%7s\n", "hello");
    // printf("6.7\n");
    // ft_printf("%6.7s\n", "hello");
    // printf("%6.7s\n", "hello");
    // printf("7.7\n");
    
    // ft_printf("%7.7s\n", "hello");
    // printf("%7.7s\n", "hello");
    // printf("8.7\n");
    // ft_printf("%8.7s\n", "hello");
    // printf("%8.7s\n", "hello");
    // ft_printf("%10.6d\n", -1024);
    //    printf("%10.6d\n", -1024);
    // ft_printf("%10.5d\n", -1024);
    //    printf("%10.5d\n", -1024);
    // ft_printf("%10.4d\n", -1024);
    //    printf("%10.4d\n", -1024);
    // ft_printf("%6d\n", -1024);
    //    printf("%6d\n", -1024);
    // ft_printf("%5d\n", -1024);
    //    printf("%5d\n", -1024);
    // ft_printf("%4d\n", -1024);
    //    printf("%4d\n", -1024);

    // ft_printf("%.p\n", NULL);
    //    printf("%.p\n", NULL);
    // ft_printf("%1.p\n", NULL);
    //    printf("%1.p\n", NULL);
    // ft_printf("%1p\n", NULL);
    //    printf("%1p\n", NULL);

    // ft_printf("%5.0c\n", 'a');
    //    printf("%5.0c\n", 'a');
    // ft_printf("%5.1c\n", 'a');
    //    printf("%5.1c\n", 'a');
    // ft_printf("%5.2c\n", 'a');
    //    printf("%5.2c\n", 'a');

    // printf("ss\n");
    //  ft_printf("%5.s\n", "a");
    //     printf("%5.s\n", "a");
    // ft_printf("%5.0s\n", "a");
    //    printf("%5.0s\n", "a");
    // ft_printf("%5.1s\n", "a");
    //    printf("%5.1s\n", "a");
    // ft_printf("%5.2s\n", "a");
    //    printf("%5.2s\n", "a");

    // ft_printf("%%\n");
    //    printf("%%\n");
    //  ft_printf("ft %.c\n",'a');
    //     printf("or %.c\n",'a');
    //  ft_printf("ft:%.c\n",'c');
    //     printf("or:%.c\n",'c');
    // system("leaks a.out");
}