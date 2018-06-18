/***
 fibonacci.c
 Program: Creates and adds first 20 number in fibonnaci series
 Author: O. Minkina
 Date: 3/1/18
 ***/
 
#include <stdio.h>
 
void fibonnaci(int*, int size); //prototype fibonnaci function  //&array[0] is same as int*
int Sum(int*, int size);        //prototype Sum function
 
int main (void)
{
    int FibArray[20] = {0}; //declare and initialize array
    int *FibArray_ptr = &FibArray[0]; //declare and initialize pointer to first element in array
    int sum = 0;
    
    fibonnaci(&FibArray[0], 20); //call fibonnaci function
    
    printf("The fibonacci series is:\n"); //print series to make sure it works correctly.
    for(int i = 0; i <20; ++i)
        printf("%5i\n", FibArray[i]);
    printf("\n");
    
    sum = Sum(&FibArray[0], 20); //call Sum function and assign result to sum
    
    printf("The sum of the first 20 Fibonacci number is: %i\n", sum);
    
    return 0;
}
 
void fibonnaci(int* FibArray_ptr, int size)
{
    *FibArray_ptr = 0; //Set pointer that points to first element of FibArray to 0
    *FibArray_ptr++;   //Increment pointer
    *FibArray_ptr = 1; //Set pointer that points to next element of FibArray to 0
    for(int i = 2; i < size; ++i)  //Assign fibonnacci series to next elements of array
    {
        FibArray_ptr++;
        *FibArray_ptr = *(FibArray_ptr-1) + *(FibArray_ptr-2);
    }
}
 
int Sum(int* FibArray_ptr, int size)
{
    int sum = 0;
    for(int i = 0; i < size; ++i) //add each element of array
        sum += FibArray_ptr[i];
    return sum;
}
