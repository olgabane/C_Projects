#include <stdio.h>

int main(void)
{
    int n;
    int m, d, p;
    int o = 0;
    
    printf("Please input an integer\n");
    scanf("%i", &n);
   
    //reverse number
    p = n;
    while (p > 0)
        {
            d = p%10;
            o = o*10 + d;
            p = p/10;
        }
    
    //print word corresponding to each digit of reversed number
    //divide by 10 and take remainder until no more digits. 
    do
        {
            m = o%10;
            switch(m)
                {
                    case 9:
                        printf("nine");
                        break;
                    case 8:
                        printf("eight");
                        break;
                    case 7:
                        printf("seven");
                        break;
                    case 6:
                        printf("six");
                        break;
                    case 5:
                        printf("five");
                        break;
                    case 4:
                        printf("four");
                        break;
                    case 3:
                        printf("three");
                        break;
                    case 2:
                        printf("two");
                        break;
                    case 1:
                        printf("one");
                        break;
                    case 0:
                        printf("zero");
                }
            printf(" ");
            o = o/10;
        }
    while (o > 0);
    
    
    //if there is a 0 at the end of a non-zero integer, print 0.
    //use while loop to account for numbers that end with multiple 0s.
    while (n%10 == 0 && n != 0)
        {
            printf("zero ");
            n=n/10;
        }
    
    printf("\n");
    return 0;
    
}
