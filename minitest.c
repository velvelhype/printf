#include <stdio.h>
int ft_printf(char *fmt, ...);

int	main(void)
{
       printf("oh%010.0x:\n",0);
    ft_printf("oh%010.0x:\n",0);
       printf("oh%010.*x:\n",0,0);
    ft_printf("oh%010.*x:\n",0,0);
}