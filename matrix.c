/*** 
matrix.c
Midterm, Problem #2
Program: creates and populates an 8 x 10 matrix, transposes matrix
Author: O. Minkina
Date: 2/22/18 
***/

#include <stdio.h>

int main (void)
{
//Declare an 8 x 10 matrix containing integers, initialize the first row.
int A[8][10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//Declare and initialize variables.
int i, j = 0;
int counter = 0;

//loop through rows, starting with row 1
for(i = 1; i < 8; ++i)
//loop through columns, populate i'th row, j'th column with integer in //previous row and column
    {
    for(j = 0; j < 10; ++j)
        {
            A[i][j] = A[i-1][j-1];
        }
//Set integer in first column equal to 10, and decrement by 1 for each row //thereafter (using counter)
    A[i][0] = 10 - counter;
    counter++;
    }
    
//print out matrix, one row at a time
printf("Here is the resulting matrix:\n\n");
for(i = 0; i < 8; ++i)
    {
    for(j = 0; j < 10; ++j)
    {
        printf("%2d ", A[i][j]);
    }
    //return after each row
    printf("\n");
    }
//blank row for more readable output
printf("\n");
    
//transpose matrix A
//Declare a new 10 x 8 matrix
int B[10][8];
//loop through rows
for(i = 0; i < 10; ++i)
//loop through columns, populate i'th row, j'th column with integer in //previous row and column
    for(j = 0; j < 8; ++j)
        B[i][j] = A[j][i];
    
//print out transposed matrix
printf("Here is the transposed matrix:\n\n");
for(i = 0; i < 10; ++i)
{
    for(j = 0; j < 8; ++j)
    {
        printf("%2d ", B[i][j]);
    }
    //return after each row
    printf("\n");
}

//blank row for more readable output
printf("\n");
    
//return 0 at end of successful program
return 0;
}
