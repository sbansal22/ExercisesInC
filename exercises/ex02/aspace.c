/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
    // A randomnly selected number - 30
    void *ra = malloc(30);
    void *rb = malloc(30);
    // void *p = malloc(128);
    // The systems heap grows upwards
    // void *b = malloc(1280);
    // char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    local(var2);
    printf ("Address of var2 is %p\n", &var2);
    // printf ("p points to %p\n", p);
    // printf ("b points to %p\n", b);
    // printf ("s points to %p\n", s);
    printf ("ra points to %p\n", ra);
    printf ("rb points to %p\n", rb);
    // The distance between them turns out to be -28
    return 0;
}

int local (int var)
{
    // The memory space grows toward lower addresses
    printf ("Address of function2 is %p\n", local);
    printf ("Address of variable %i is: %p\n", var, &var);
}
