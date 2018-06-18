#include <stdio.h>
 
//define parameters
#define source_def 0xe1f4
#define pattern_def 0x5
#define n_def 3
 
int bitpat_search(int source, int pattern, int n);
 
int main(void)
{
	unsigned int source = source_def;
	unsigned int pattern = pattern_def;
	unsigned int n = n_def;
	
	bitpat_search(source, pattern, n);
}
 
int bitpat_search(int source, int pattern, int n)
{
	//need to mask pattern
	unsigned int mask = (1 << n) - 1;
	int pattern_shifted = pattern & mask;
	int i = 0;
	int j = 1;
	int source_shifted;
	int source_count = source;
	int count = 0;
	
	//count number of bits required to represent source
	do
	{
    	source_count =  source_count >> 1;
    	count++;
	}
	while(source_count != 0);
	
	while(i <= count && j != 0)  //while(source_shifted != 0 && j != 0)
	{
    	//take rightmost n of source shifted
    	source_shifted = source >> (count - n - i);
    	//take rightmost n of source shifted
    	source_shifted = (source_shifted & mask);
    	//if pattern and current bits of source match, set j to 0, exit loop
    	if((source_shifted ^ pattern_shifted) == 0)
        	j = 0;
    	i++;
	}
	
	if(j == 0)
    	printf("The pattern in the source begins with bit number: %i\n ", i-1);
	else
    	printf("The pattern is not found in the source.\n");
	return 0;
}
