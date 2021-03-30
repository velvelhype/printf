#include "ft_printf.h"
int main()
{
    int a;

ft_printf("%5.c\n", 'a');
   printf("%5.c\n", 'a');
ft_printf("%5.0c\n", 'a');
   printf("%5.0c\n", 'a');
ft_printf("%5.1c\n", 'a');
   printf("%5.1c\n", 'a');
ft_printf("%5.2c\n", 'a');
   printf("%5.2c\n", 'a');

printf("ss\n");
 ft_printf("%5.s\n", "a");
    printf("%5.s\n", "a");
ft_printf("%5.0s\n", "a");
   printf("%5.0s\n", "a");
ft_printf("%5.1s\n", "a");
   printf("%5.1s\n", "a");
ft_printf("%5.2s\n", "a");
   printf("%5.2s\n", "a");


       
// ft_printf("%%\n");
//    printf("%%\n");
//  ft_printf("ft %.c\n",'a');
//     printf("or %.c\n",'a');
//  ft_printf("ft:%.c\n",'c');
//     printf("or:%.c\n",'c');
}