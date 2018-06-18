/*** 
grades.c
Program: Calculates frequency of grades A-F.
Author: O. Minkina
Date: 2/27/18
***/

#include <stdio.h>

int main(void)
{
    //Declare and initialize array of grades
    char grade[32] = {
                    'A', 'B', 'C', 'D', 'f', 'I',
                    'b', 'C', 'd', 'F', 'I', 'a',
                    'C', 'D', 'F', 'I', 'A', 'B',
                    'D', 'F', 'I', 'A', 'B', 'c',
                    'I' , 'D', 'F', 'Q', 'A', 'B',
                    'a', 'b'
                    };
    
    //Declare and initialize hist_grade array to count grades
    int hist_grade[6] = {0};
    
    //Loop through grade array, increase value of grade in hist_grade array
    for(int i=0; i < 32; ++i)
        {
        switch (grade[i]) {
            case 'A':
            case 'a':
                hist_grade[0] += 1;
                break;
            case 'B':
            case 'b':
                hist_grade[1] += 1;
                break;
            case 'C':
            case 'c':
                hist_grade[2] += 1;
                break;
            case 'D':
            case 'd':
                hist_grade[3] += 1;
                break;
            case 'F':
            case 'f':
                hist_grade[4] += 1;
                break;
            case 'I':
                hist_grade[5] += 1;
                break;
            default:
                break;
            }
        }
    
    //print table of grade frequencies to make sure program works as expected.
    printf("Grade   Frequency\n");
    for (int i = 0; i < 4; i++)
        printf("%c %10i\n", 65+i, hist_grade[i]);
    printf("%c %10i\n", 70, hist_grade[4]);
    printf("%c %10i\n", 73, hist_grade[5]);
    
    return 0;
}
