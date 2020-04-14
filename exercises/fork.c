/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

/* 
   Comments and Observations - 
   I tested this code with 3 children for Global, Static,
   and Heap access for children vs. parent processes.
   My observation is that the globally defined variable (globe)
   is stored at the same address for both the parent and the 
   child processes, and containts the same value. The variables
   defined statically inside the i child processes seemingly have
   the same address, but it is different from statically defined
   variable addresses for the parent process. As for the dynamically
   allocated variables on the heap, the values and addresses are shared
   across the parent and child processes since they are the same.
   I'm not sure how I can test for the exact similarity in code segments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>


// errno is an external global variable that contains
// error information
extern int errno;

// Creating a global variable
int globe = 7;

// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}

void child_code(int i,int *heapv)
{
    sleep(i);
    int stat = i;
    printf("Hello from child %d.\n", i);
    printf("Child - Global access - Value: %d Address: %p\n", globe, &globe);
    printf("Child - Static access - Value: %d Address: %p\n", stat, &stat);
    printf("Child - Heap access - Value: %d Address: %p\n", *heapv, heapv);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;

    // Creating a static variable
    int stat = 7;
    
    // Creating a heap variable
    int* heapv = malloc (sizeof(int));
    *heapv = 7; 

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {
        *heapv += 1;
        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            child_code(i,heapv);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");
    printf("Parent - Global access - Value: %d Address: %p\n", globe, &globe);
    printf("Parent - Static access - Value: %d Address: %p\n", stat, &stat);
    printf("Parent - Heap access - Value: %d Address: %p\n", *heapv, heapv);

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}