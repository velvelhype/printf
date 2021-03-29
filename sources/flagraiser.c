#include "../includes/ft_printf.h"

int typefinder(char s)
{
    if (s == 'c' || s =='s' || s == 'p' || s == 'd')
        return s;
    if (s == 'i' || s == 'u' || s == 'x' || s == 'X' || s == '%')
        return s;
    return 0;
}

struct flags flagmaker(struct flags flagman, char *fmt, va_list ap)
{
    int digitsize = 0;
    char *opoint;

    flagman.minus = -1;
    flagman.zero = -1;
    flagman.field = -1;
    flagman.prec = -1;
    flagman.type = -1;
    flagman.flagsize = -1;
    opoint = fmt;

    if (*fmt == '-')
    {
        flagman.minus = 1;
        fmt++;
    }
    if (*fmt == '0')
    {
        if (flagman.minus != 1)
            flagman.zero = 1;
        fmt++;
    }
    if ('0' <= *fmt && *fmt <= '9')
    {
        flagman.field = 0;
        while (typefinder(*(fmt + digitsize)) == 0 && *(fmt + digitsize) != '.')
            digitsize++;
        while (digitsize > 0)
        {
            flagman.field = (flagman.field * 10 + (*fmt - 48));
            fmt++;
            digitsize--;
        }
    }
    else if (*fmt == '*')
    {
        flagman.field = va_arg(ap, int);
        if(flagman.field < 0)
            {
                flagman.field *= -1 ;
                flagman.minus = 1;
            }
        fmt++;
    }
    else
        flagman.field = -1;

    if (*fmt == '.')
    {
        fmt++;
        if (*fmt == '*')
        {
            flagman.prec = va_arg(ap, int);
            fmt++;
        }
        else
        {
            flagman.prec = 0;
            digitsize = 0;
            while (typefinder(*(fmt + digitsize)) == 0 && *(fmt + digitsize) != '.')
                {
                    flagman.prec = (flagman.prec * 10) + *(fmt + digitsize)  - '0';
                    digitsize++;
                }
            while (digitsize > 0)
            {
                fmt++;
                digitsize--;
            }
        }
    }
    else
    flagman.prec = -1;
    
    flagman.type = typefinder(*fmt);
    flagman.flagsize = fmt - opoint;
    return flagman;
}

// int main()
// {
//     struct flags flagman = {-1, -1, 0, 0, -1};
//     char king[100] = "02329.1234s";
//     flagman = flagmaker(flagman, king);
//     printf("%d\n", flagman.minus);
//     printf("%d\n", flagman.zero);
//     printf("%d\n", flagman.field);
//     printf("%d\n", flagman.prec);
//     printf("%c\n", flagman.type);
// }