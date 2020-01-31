/*
* Software Systems Spring 2020 Exercises in C - 1
* Modified By: Sparsh Bansal
* The following licensure information was 
* acquired from the Head First C book.
* Program to evaluate face values.
* Released under the Vegas Public License.
* (c)2014 The College Blackjack Team.
*/

#include <stdio.h>
#include <stdlib.h>

/* The main function calls the supporting functions,
 * keeps track of the count for the game, and takes
 * care of ending the game if the user enter an 'X'
 */ 
int main()
{
	char card_name[3];
	int count = 0;
	do {
		char * card_name = reader();
		int val = determiner(card_name);
		if ((val > 2) && (val < 7)) {
			count++;
		} else if (val == 10) {
			count--;
		}
		printer(count);
	} while (card_name[0]!='X');
	return 0;
}

/* Reads the user input of the chard name
 * Return value: the name of the card in
 * string format
 */
char * reader()
{
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
	return card_name;
}

/*  Determines the name of the card
 *	based on the output from the 
 *	reader() function using a switch
 *	statement
*/
int determiner(card_name)
{
	int val = 0;
	switch(card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case'X':
			break;
		default:
			val = atoi(card_name);
			if ((val < 1)||(val > 10)){
				puts("I don't understand that value!");
				break;
			}
		}
		return val;
}

/* Screen prints the count to the users in
 * the terminal
*/
int printer(count)
{
	printf("Current count: %i\n", count);
	return 0;
}