#include "main.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
    int n1, n2;
    // // char s;

    // int len;
    // int len2, n1, n2;
    // unsigned int ui;
    // void *addr;
    // char *s1;
    char str[] = "ABCDEFGZYX abcdefgzyx";

   n1 =  _printf("%R\n", str);
   n2 = printf("%R\n", str);
   printf("Cmpare ours: %d    original: %d\n", n1, n2);
    // s1 = NULL;
    // len = _printf("Let's try to printf a simple sentence.\n");
    // len2 = printf("Let's try to printf a simple sentence.\n");
    // ui = (unsigned int)INT_MAX + 1024;
    // addr = NULL;
    // _printf("Length:[%d, %i]\n", len, len);
    // printf("Length:[%d, %i]\n", len2, len2);
//     _printf("Negative:[%d]\n", -762534);
//     printf("Negative:[%d]\n", -762534);
//     _printf("Unsigned:[%u]\n", ui);
//     printf("Unsigned:[%u]\n", ui);
//     _printf("Unsigned octal:[%o]\n", ui);
//     printf("Unsigned octal:[%o]\n", ui);
//     n1 = _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
//     n2 = printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
//    printf("Cmpare mine: %d    original: %d\n", n1, n2);
//     _printf("Character:[%c]\n", 'H');
//     printf("Character:[%c]\n", 'H');
//     n1 = _printf("%s\n", s1);
//     n2 = printf("%s\n", s1);
//     n1 = _printf("s%");
//     n2 = printf("s%");
//    printf("Cmpare mine: %d    original: %d\n", n1, n2);
//    n1=  _printf("Address:[%p]\n", addr);
//    n2 = printf("Address:[%p]\n", addr);
//     printf("after pointer\n");
//     printf("Cmpare mine: %d    original: %d\n", n1, n2);
//    len = _printf("Percent:[%%]\n");
//    len2 = printf("Percent:[%%]\n");
//    printf("Cmpare mine: %d    original: %d\n", len, len2);
//     _printf("Len:[%d]\n", len);
//     printf("Len:[%d]\n", len2);
//    n1 = _printf("Unknown:[%r]\n");
//     n2 = printf("Unknown:[%r]\n");
//    printf("Cmpare mine: %d    original: %d\n", n1, n2);
    return (0);
}
