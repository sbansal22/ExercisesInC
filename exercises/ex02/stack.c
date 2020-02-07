/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

/* 

### Stack allocated data

1.  Read `stack.c`, which should be in this directory.  What is it
intended to do?  What would the output be if the program worked as
expected?

The two functions bar and foo are written to created integer arrays - 
foo assigns each element of the array the value 42, while bar sets
each element of the array equal to its index. The main function calls
these two functions and prints out the final array for the user. 
The output would be an array resulted through running bar.

2.  Compile it.  Do you get a warning?  What does it mean?
I got a warning that said specifically, "function returns address of local variable"
It means that we are trying to access the address of a variable that was defined locally
in a block of the program - say, defined locally inside of a function.

3.  Run it.  What happens?  You might get a segmentation fault, or you might get
some strange output.  Can you explain it?  You might find it
helpful to draw a stack diagram.
Running it gives out a segmenetation fault (core dumped). The same reason as I stated in the 
previous answer, this error has occured since a location in the memory is being accessed by
part of the code where it is not locally defined, nor globally defined in the program.

4.  Comment out the `print` statements in `foo()` and `bar()` and run
it again.  What happens now?
It looks like the main function is trying to print pointers or addresses in the stack
that have entered the defined 'array' due to the errors in the code.

*/