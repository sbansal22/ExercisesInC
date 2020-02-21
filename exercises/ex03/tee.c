/*
Author: Sparsh Bansal
Software Systems SP 2020, Homework Exercise 3

A program that implements the function <Tee>

References: Head First C Book
            CA, Prava
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char ch;
    char filepath[100];
    char text[100000];
    int append = 0;
    int ignore = 0;
    int diagnose = 0;
    int count = 0;
    FILE *edit;
    
    while ((ch = getopt(argc, argv, "aip")) != EOF)
        switch(ch) {
            case 'a':
                append = 1;
            break;

            default: 
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        }
    
    argc -= optind;
    argv += optind;


    while (fgets(text, sizeof(text), stdin) != NULL) {
        for (count = 0; count < argc; count++) {
            if (append) {
            edit = fopen(argv[count],"a");
            fputs(text, edit);
            fclose(edit);
            }
            if (ignore) {

            }
            if (diagnose) {
                
            }
        }
    }
    return 0;
}