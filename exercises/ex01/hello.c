#include <stdio.h>

// My biggest observation with 
// optimization was fewer lines of 
// executable commands. The -O2 flag
// optimized file had other minor
// changes, for example - 
// The beginning command was changed
// from LBF0 -> LBF23

// My second biggest observation
// was that the print statements
// added about 4-5 lines extra
// inlcuding commands like 
// <xorl>, <call>, <leaq>, <movl>

// With the optimized version,
// sectional commands such as
// <.section .text.startup,"ax",@progbits>
// were prominent, compared to the
// unoptimized versions.

int main() {
    int x = 5;
    int y = x + 1;
    //printf("X: %i\n", x);
    printf("Y: %s\n", y);
    return 0;
}
