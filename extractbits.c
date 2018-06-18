#include <stdio.h>
 
//define parameters
#define source_def 317;
#define start_def 3;
#define count_def 4;
 
int bitpat_get(unsigned int source, int start, int count);
 
int main(void)
{
	int source = source_def;
	int start = start_def;
	int count = count_def;
	bitpat_get(source, start, count);
}
 
int bitpat_get(unsigned int source, int start, int count)
{
	unsigned int source_count = source;
	int length = 0;
	
	//count number of bits required to represent source, call this length
	do
	{
    	source_count = source_count >> 1;
    	length++;
	}
	while(source_count != 0);
	
	//shift source to get rid of right-most unused bits
	source = source >> (length - (start+count));
	//create mask, use & operator to get right-most bits
	unsigned int mask = (1 << count) - 1;
	int result = source & mask;
	
	//print result
	printf("The extracted bits are: %i\n", result);
 
	return 0;
}
