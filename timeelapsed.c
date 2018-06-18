#include <stdio.h>
 
struct time
{
	int hour;
	int minutes;
	int seconds;
};
 
 
int main(void)
{
	//initialized 3 time structures and a function that takes two time structures as arguments.
	struct time time1, time2, time3;
	
	struct time elapsed_time(struct time, struct time);
	
	//ask user for start and end time
	printf("Please input start time followed by end time as h:m:s, h:m:s\n");
	scanf("%2i:%2i:%2i, %2i:%2i:%2i", &time1.hour, &time1.minutes, &time1.seconds, &time2.hour, &time2.minutes, &time2.seconds);
	
	//calculate elapsed time
	time3 = elapsed_time(time1, time2);
	
	//print elapsed time
	printf("Elapsed time = %i:%i:%i\n", time3.hour, time3.minutes, time3.seconds);
	
}
 
struct time elapsed_time(struct time time1, struct time time2)
{
	//initialize new time structure to contain elapsed time and initialize int.
	struct time time3;
	int time_diff_seconds;
	
	//convert time to seconds
	int time1_seconds = time1.seconds + 60*time1.minutes + 60*60*time1.hour;
	int time2_seconds = time2.seconds + 60*time2.minutes + 60*60*time2.hour;
	
	//account for times that cross noon or midnight by adding 12 hours (in seconds)
	if(time2_seconds < time1_seconds)
    	time2_seconds = time2_seconds + 12*60*60;
 
	//calculate time difference in seconds
	time_diff_seconds = time2_seconds - time1_seconds;
	
	//convert time difference to hours, minutes, seconds
	time3.hour = time_diff_seconds/60/60;
	time3.minutes = (time_diff_seconds - time3.hour*60*60)/60;
	time3.seconds = (time_diff_seconds - time3.hour*60*60 - time3.minutes*60);
 
	//return resulting structure time 3.
	return time3;
 
}
