#include <unistd.h>
#include <stdio.h>
 
int main()
{
  char str[3];
  scanf("%s\n", str);
 
  write(1,(str + 1),1);
  write(1,(str + 2),1);
  write(1,(str),1);
}