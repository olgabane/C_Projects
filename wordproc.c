/****
 O. Minkina
 3.7.18
 Program makes a simple word processor
 *****/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void Sort(int size, char**); //prototype Sort function
 
int main(void)
{
	char buffer[80] = {'\0'};
	int i = 0;
	int n = 0;
	char* line_array[80];
	long int len = 0;
	
	while(*buffer != 35 && n < 41) //continue loop until user prints '#' or 40 lines
	{
    	printf("Please input string or '#' to exit\n");
    	fgets(&buffer[0], 80, stdin); //ask user for string
    	len = strlen(buffer);
    	line_array[i] = (char*)malloc(len * sizeof(char)); //allocate memory
    	if(line_array[i] == NULL) //check that memory allocation worked.
    	{
        	printf("Heap Memory Failure\n");
        	exit(EXIT_FAILURE);
    	}
    	
    	strcpy(line_array[i], buffer); //copy buffer allocated memory
    	i++;
    	n++; //counts # of lines inputted by user
	}
	
	//print each line
	printf("\nHere is the user input, printed out:\n");
	for(i = 0; i < (n-1); i++)
    	printf("%s", line_array[i]);
	
	//Move lines 5 and 6 pointers to end (no need to allocate new memory because allocated for 80 lines)
	line_array[i+1] = line_array[4];
	line_array[i+2] = line_array[5];
	
	//Move pointer up two for each pointer after lines 5 and 6
	for(i = 6; i < (n + 2); i++)
    	line_array[i-2] = line_array[i];
	
	//print each resulting line
	printf("\nHere is the user input, with lines 5 and 6 moved to end:\n");
	for(i = 0; i < n; i++)
    	if(*line_array[i] != 35)
        	printf("%s", line_array[i]);
	
	//sort lines alphabetically
	Sort(n, &line_array[0]);
	
	//print each resulting line, starting from last (sort function sorts Z to A)
	printf("\nHere is the user input, sorted alphabetically\n");
	for(i = n-1; i >= 0; i--)
    	if(*line_array[i] != 35)
        	printf("%s", line_array[i]);
	
	//free memory
	for(i = 0; i < (n); i++)
    	free(line_array[i]);
	
	return 0;
}
 
void Sort(int n, char** line_array)//bubble sort strings
{
	for(int j = 0; j < (n); j++) 
    	for(int i = 0; i < (n); i++)
        	if (*line_array[j] > *line_array[i+1])
        	{
            		char *temp = line_array[i+1];
            		line_array[i+1] = line_array[j];
            		line_array[j] = temp;
        	}
}

