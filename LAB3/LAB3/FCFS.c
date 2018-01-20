#include<stdio.h>
#include<stdlib.h>
int main()
{
	int bt[10],i,at[10],temp[10],n,time,flag=0,t_quantum,wait=0,turnaround_time,count,left;
	printf("enter the number of values\n");
	scanf("%d",&n);
	left = n;
	for(i=0;i<n;i++)
	{
		printf("enter the arrival time and burst time respectively \n");
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
		temp[i]=bt[i];
	}
	
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
	for(i=0,count=0;i<n;i++,count++)
	{	time=time+bt[i];
		printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
		wait=wait+ time-at[count]-bt[count];
		turnaround_time+= time-at[count];
	}
	printf("\nAverage Waiting Time= %f\n",wait*1.0/n); 
  	printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
return 0;
}
