/*
Exercise #02, Software Systems SP 20;
Author: Sparsh Bansal;
*/

// Including the required header files and supporting functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Addition function -
* Input arguments: integer array containing the integers that the user has supplied
* Output: An addition of the integers contained in the input integer array
*/

void addr(int arr2[])
{
    int sm = 0;
    int len = strlen(arr2);
    for ( int x = 0; x < 10 ; x++ )
    {
        sm = sm + arr2[x];
    }
    printf("Sum of the integers that you entered is: %i\n", sm);
}

/* Reader function - 
 * Input Arguments - none
 * Output - Prints out the input that the user supplied the program with;
 * Processes - Checks for the rules that are applied on the types of acceptable inputs to the program
 *            Converts the string inputs to integers and stores them in an integer array
 *            Calls the addition function when the user input has ended
*/

void read_terminal()
{
    char arr1[4];
    int arr2[10];
    memset(arr2, 0, 10 * sizeof(int));
    int count = 0;
    int buffer_int;
    
    printf("Welcome to the adder program. \n Please start entering your desired 
    integers, one per line. \n Remember, that you can only add up to 10 integers
     using this program, and you are restricted to input numbers with 4 or 
     fewer number of digits: \n");
    
    while (fgets(arr1, sizeof(arr1), stdin) != NULL)
    {   
        if (arr1[strlen(arr1)-1] != '\n')
        {
            printf("Please enter an integer not exceding 4 digits! \n"); 
            break;
        }
        
        if (count == 10)
        {
            printf("You are only allowed to enter 10 numbers to the adder! \n");
        }
        
        if (atoi(arr1) == 0)
        {
            printf("Please enter a non-zero number! \n");
        }
        
        {
            arr2[count] = atoi(arr1);             
            count++;
        }
    }
    addr(arr2);
}

/* The main function calls the reader function only. */

int main()
{
    read_terminal();
    return 0;
}