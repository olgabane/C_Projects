#include <stdio.h>

#define STRING1 "rabbit"    //Use #define to easily change strings to compare.
#define STRING2 "cow"

//prototype function that takes two pointers, returns an integer
int  compareStrings (char*, char*); 

int main(void)
{
    char s1[] = STRING1;
    char s2[] = STRING2;
    
    char* s1_ptr;
    char* s2_ptr;
    
    s1_ptr = &s1[0]; //s1_ptr points
    s2_ptr = &s2[0];
    
    int result = compareStrings(s1_ptr, s2_ptr);

    if(result == 0)
        printf("The strings match!\n");
    if(result == -1 || result == 1)
        printf("The strings do not match!\n");
    
    return 0;
}

int compareStrings(char* s1_ptr, char* s2_ptr)
{
    int  answer;
    
    while (*s1_ptr == *s2_ptr && *s1_ptr != '\0'&& *s2_ptr != '\0' ) //* allows you to access value of pointer
        {
            s1_ptr++; //increment location of each pointer by 1
            s2_ptr++;
        }
    
    if ( *s1_ptr < *s2_ptr ) //if 1st  character smaller (differ in value)
        answer = -1;               
    else if ( *s1_ptr == *s2_ptr )  //if two characters are same value
        answer = 0;
    else
        answer = 1;
    
    return answer;

}
