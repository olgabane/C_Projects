/****
 O. Minkina
 3.10.18
 Concatenate two strings
 *****/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
//prototype function
char* string_cat(char*, char*);
 
int main(void)
{
	//continue until user says no
	while(1)
	{
    	char s1[80] = {'\0'};
    	char s2[40] = {'\0'};
    	char* s1_ptr;
    	s1_ptr = &s1[0];
    	char* s2_ptr;
    	s2_ptr = &s2[0];
    	int flag = 1;
    	char* n;
    	
    	printf("Please input string 1:\n"); //ask use for first string
    	fgets(&s1[0], 81, stdin);
    	s1[strlen(s1_ptr)-1] = '\0'; //end string with null terminated character instead of return
    	printf("Please input string 2:\n"); //ask use for second string
    	fgets(&s2[0], 41, stdin);
    	s2[strlen(s2_ptr)-1] = '\0'; //end string with null terminated character instead of return
    	
    	//Print two strings
    	printf("String 1 is: %s\n", &s1[0]);
    	printf("String 2 is: %s\n", &s2[0]);
    	
    	n = string_cat(s1_ptr, s2_ptr);
    	
    	//print concatenated string
    	printf("Concatenated string: %s\n", s1_ptr);
    	
    	//Ask user if they want to continue program
    	printf("Continue? 0 for No, 1 for Yes\n");
    	scanf("%i", &flag);
    	if(flag == 0) break; //if user answered No, exit.
    	getchar(); //eat up return
    	
	}
	return 0;
}
 
//concatenate two strings
char* string_cat(char* s1_ptr, char* s2_ptr)
{
	//calculate length of two strings together, ensure that sum < 80
	int i = (int)(strlen(s1_ptr) + strlen(s2_ptr));
	if(i > 80)
	{
    	printf("\nSum of length of strings should be less than 80\n");
    	return NULL;
	}
	
	//print expected length of concatenated string
	printf("Length of concatenated string: %i\n", (strlen(s1_ptr) + strlen(s2_ptr)));
	
	//move pointer to end of s1
	while(*s1_ptr != '\0')
	{
    	s1_ptr++;
	}
	
	//assign the value of s2_ptr to location to which s1 points and increment pointers. Do until null termination character reached.
	//while(*s1_ptr++ = *s2_ptr++); would work here too!
	while(*s2_ptr != '\0')
	{
    	*s1_ptr = *s2_ptr;
    	s1_ptr++;
    	s2_ptr++;
	}
	
	//append null terminated character to s1
	*s1_ptr = '\0';
	
	//return pointer to s1
	return s1_ptr;
}
