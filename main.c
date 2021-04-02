#include "ft_printf.h"
int main()
{
ft_printf(" %*.*x %*.*x\n", 1, 10, 10, 1, 0, 10);
   printf(" %*.*x %*.*x\n", 1, 10, 10, 1, 0, 10);

ft_printf(" %*.*x %*.*x\n", 1, 10, 10, 1, 0, 10);
   printf(" %*.*x %*.*x\n", 1, 10, 10, 1, 0, 10);

ft_printf(" %*.*x %*.*x\n", 1, 10, 10, 1, 0, 10);
   printf(" %*.*x %*.*x\n", 1, 10, 10, 1, 0, 10);



   printf("%*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
ft_printf("%*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);

//    printf(" %*x %*X %*i %*u\n", 10, 547, 1, 300, 100, -55, 1, -60);
// ft_printf(" %*x %*X %*i %*u\n", 10, 547, 1, 300, 100, -55, 1, -60);
//    printf("%*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
// ft_printf("%*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
// ft_printf("%p %s",  &t, "42");
// ft_printf("%p %s", &t, "42");
// ft_printf("%d %p",  t, &t);
// ft_printf("%p %d", &t, t);
// ft_printf("s: %s, p: %p, d:%d", "a string", &t, 42);
// ft_printf("s: %s, p: %p, d:%d", "a string", &t, 42);
// ft_printf("one %s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
// ft_printf("honesty%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
// ft_printf(" is sucha lovery word %s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
// ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
// ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
// ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
// ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
// ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
// ft_printf("s: %s, p: %p, d:%d", "a string\n", &t, 42);
// ft_printf("s: %s, p: %p, d:%d", "a string\n", &t, 42);
//ft_printf("%s %d %p %% %x", "bonjour \n", 42, &free, 42);
//ft_printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
// ft_printlo "%s %d %s %d\n","bobo",12,"brazill",3000);
// ft_printf("%s %d %p %% %x\n", "bonjour ", 42, &free, 42);
// ft_printf("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');
// ft_printf("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');
   // int t;
// ft_printf("%-135.118s%0*.i%--40.43s\n" ,"\r2XRwX=GoS+icVV,7K\fFyQiN]T",-172,1489821092,"4hn)u'}xg3;O");
// ft_printf("***************%*s%*d**************%*u*************\n", 10, "coucou", 10, 10, -50, 20);
//    printf("***************%*s%*d**************%*u*************\n", 10, "coucou", 10, 10, -50, 20);

   // printf("%-135.118s%0*.i%--40.43s\n" ,"\r2XRwX=GoS+icVV,7K\fFyQiN]T",-172,1489821092,"4hn)u'}xg3;O");
   //ft_printf("%--10.100d\n",123);
// ft_printf("%--15.72i%-*.136d%000126.117%" ,-1441162113,-125,-7144);
   //ft_printf("%-15.72i%-*.136d%000126.117%" ,-1441162113,-125,-7144);
// ft_printf("%-15.72i%-*.136d%000126.117%" ,-1441162113,-125,-7144);
   // printf("%--15.72i%-*.136d%000126.117%" ,-1441162113,-125,-7144);

// ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n", (char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138, (char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149, (char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160, (char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171, (char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182, (char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193, (char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204, (char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215, (char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226, (char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237, (char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248, (char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
//    printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n", (char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138, (char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149, (char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160, (char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171, (char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182, (char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193, (char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204, (char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215, (char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226, (char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237, (char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248, (char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);


// ft_printf("{%3c}\n", 0);
//    printf("{%3c}\n", 0);
// ft_printf("...%-5c...\n", '\0');
//    printf("...%-5c...\n", '\0');
// ft_printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
//    printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
// ft_printf("%.*s\n", -10, "42");
//    printf("%.*s\n", -10, "42");

//    ft_printf("...%5c...\n", 0);
//       printf("...%5c...\n", 0);
// ft_printf("...%3c...\n", 0);
//    printf("...%3c...\n", 0);
//    printf("two\n");
//    ft_printf("{%3c}\n", 0);
//       printf("{%3c}\n", 0);
       
         // ft_printf("..%-5c...\n", '\0');
    //    printf("..%-5c...\n", '\0');
    // ft_printf("..%-5s...\n", "\0");
    //    printf("..%-5s...\n", "\0");
    // ft_printf("%010d\n", -54);
    //    printf("%010d\n", -54);
    // ft_printf("%04d\n", -54);
    //    printf("%04d\n", -54);
    // ft_printf("%04.d\n", -54);
    //    printf("%04.d\n", -54);
    // ft_printf("%03d\n", -54);
    //    printf("%03d\n", -54);
    // ft_printf("%01d\n", -54);
    //    printf("%01d\n", -54);
    //    printf("1\n");
    // ft_printf("%4.14d\n", 424242);
    //    printf("2\n");
    //    printf("%4.14d\n", 424242);
    //    printf("1\n");
    // ft_printf("%4.15d\n", 424242);
    //    printf("2\n");
    //    printf("%4.15d\n", 424242);
    //    printf("f1\n");
    // ft_printf("%.15d\n", 424242);
    //    printf("f2\n");
    //    printf("%.15d\n", 424242);
    //    printf("f3\n");
    // ft_printf("%01.15d\n", 424242);
    //    printf("f4\n");
    //    printf("%01.15d\n", 424242);
    //    printf("1\n");
    // ft_printf("%4.16d\n", 424242);
    //    printf("2\n");
    //    printf("%4.16d\n", 424242);

// printf("ft\n");
// ft_printf("%5.d...\n", 0);
// printf("ori\n");
//    printf("%5.d...\n", 0);
//    printf("%5.0d...\n", 0);
//    printf("%5.d...\n", 1);
//    printf("%5.0d...\n", 1);
// ft_printf("%5.0d, %5.0d\n", 0, 0);
//    printf("%5.0d, %5.0d\n", 0, 0);
//  ft_printf("%1.0d, %5.0d\n", 0, 0);
//    printf("%0.0d, %5.0d\n", 0, 0);

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
   //  system("leaks a.out");
}