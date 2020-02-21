/*
Author: Sparsh Bansal
Software Systems SP 2020, Homework Exercise 3

A program that implements the function <Tee>

References: Head First C Book
            CA, Prava
*/

// Adding header files for the standard libraries
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
    
    // Obtain the input arguments (inlcuding the filename), and the flags
    while ((ch = getopt(argc, argv, "aip")) != EOF)
        switch(ch) {
            // The case when the append flag [-a] is called
            case 'a':
                append = 1;
            break;
            
            // The case when the ignore flag [-i] is called
            case 'i':
                ignore = 1;
            break;

            // The case when the diagnose flag [-p] is called
            case 'p':
                diagnose = 1;
            break;

            // Handling any flags other than a/i/p
            default: 
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        }
    
    // Program from Head First C
    argc -= optind;
    argv += optind;

    // Getting user input from the command line
    // Reads the keyboard input until the user enters Ctrl+D
    while (fgets(text, sizeof(text), stdin) != NULL) {
        // Iterates through all the typed text
        for (count = 0; count < argc; count++) {
            if (append) {
            // Opens/Creates the required file
            edit = fopen(argv[count],"a");
            // Appends the text to the opened file
            fputs(text, edit);
            // Closes the file at the end of operation to
            // avoid errors
            fclose(edit);
            }

            // For future development: Ignore flag
            if (ignore) {

            }

            // For future development: Diagnose flag
            if (diagnose) {
                
            }
        }
    }
    return 0;
}

// ex03, Question 3

// Problem decomposition worked well - I had planned to 
// break the main function into two main sections - 
// one to parse the command by the user, and the other
// to read the text input and actions w.r.t. the flags.
// For the solution and help, I looked mostly at Head
// First C, and got some help from the CA. That also
// worked out pretty well.
// Assimilation and Integration 
// is where I ran into errors. For future,
// I want to pay more attention to how I am defining
// variables and pointers. That is the biggest area
// where I make errors, currently.

// ex03, Question 4

// Things that are additional in the professional
// code: 1. Detailed Copyright info
// 2. It uses a lot more tools/standard libraries
// than I have used
// 3. It has a clear initial typedef
// 4. A locale has been set
// 5. There is warnings and error handling for most
// of the functions/tasks
