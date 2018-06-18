i) Source code
/***
 string.c
 Program: Capitalize each word and count the number of characters
 Author: O. Minkina
 Date: 3/1/18
 ***/
 
#include <stdio.h>
 
void Cap(char *); //prototype functions
int count(char *);
 
int main()
{
	//initiate and declare string of characters, initiate and declare counter
	char prose[ ] = "To be, or not to be, that is the question— whether 'tis nobler in the mind to suffer the slings and arrows of outrageous fortune, or to take arms against a sea of troubles, and by opposing end them? to die, to sleep— no more; and by a sleep, to say we end the heart-ache, and the thousand natural shocks that flesh is heir to? 'tis a consummation devoutly to be wished. to die, to sleep, to sleep, perchance to dream; aye, there's the rub, for in that sleep of death, what dreams may come, when we have shuffled off this mortal coil, must give us pause.";
	int counter = 0;
	
	char* prose_ptr = &prose[0]; //initiate and declare pointer pointing to first character in prose
	
	Cap(&prose[0]); //invoke function to capitalize all words
	
	while(*prose_ptr != '\0')  //print prose with all letters capitalized
    	printf("%c", *prose_ptr++);
	printf("\n\n");
	
	counter = count(&prose[0]); //invoke function to count words
	printf("The number of words in this prose is: %i\n", counter); //print result of count function
	
	return 0;
	
}
 
void Cap(char * prose_ptr)
{
	while(*prose_ptr != '\0') //do this loop until end of prose
	{
    	if(*prose_ptr >= 97 && *prose_ptr <= 122 && *(prose_ptr-1) == 32) //capitalize lowercase letter
    	{
        	*prose_ptr = *prose_ptr-32;
    	}
    	prose_ptr++;
	}
}
 
int count(char * prose_ptr)
{
	int counter = 1; //this ensures that first words is counted
	while(*prose_ptr != '\0') //do this loop until end of prose
    {
    	if(*prose_ptr == 32 || *prose_ptr == 9) //count spaces
        	counter++; //if encountered space, increment counter by 1
    	prose_ptr++; //increment pointer
	}
	return counter;
}
