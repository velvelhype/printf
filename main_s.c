//#inclsde "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
int ft_printf(char *fmt, ...);

int	main(void)
{
	   printf("ori%*s\n",10,"12345");
	ft_printf("min%*s\n",10,"12345");
	   printf("ori%-*.*s\n",20,20,"12345");
	ft_printf("min%-*.*s\n",20,20,"12345");

	//system("leaks a.out");
}