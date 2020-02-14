/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

References - https://stackoverflow.com/questions/1085083/regular-expressions-in-c-examples

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "Freddie Freeloader",
    "So What",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    // TODO: fill this in
    regex_t regex;
    int retptr;
    char msgbuf[100];
    
    // Compilation for regex
    // "The regcomp() function will compile the regular 
    // expression contained in the string pointed to by 
    // the pattern argument and place the results in the
    // structure pointed to by retptr.
    if (regcomp(&regex, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
        // stderr. The standard error stream is the default 
        // destination for error messages and other diagnostic warnings.
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }
    
    // Execution for regex
    for (int i = 0; i < NUM_TRACKS; i++) {
        retptr = regexec(&regex, tracks[i], 0, NULL, 0);
        if (!retptr) {
            printf("Track %i: '%s'\n", i, tracks[i]);
			break;
        }
    }
    
    if (retptr != 0){
        regerror(retptr, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
    }
    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);  
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
