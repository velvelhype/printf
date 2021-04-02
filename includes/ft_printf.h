#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

struct flags
{
    int minus;
    int zero;
    int field;
    int prec;
    int type;
    int flagsize;
};


char *ft_itoa(size_t d);
char *x_con(long d, int flag);
struct flags flagmaker(struct flags flagman, char *fmt, va_list ap);
int dfinisher(char *bullet, struct flags flagman);
int xfinisher(char *bullet, struct flags flagman);
int sfinisher(struct flags flagman, char *bullet);
int ft_printf(char *fmt, ...);


#endif