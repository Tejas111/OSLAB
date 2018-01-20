#include<stdio.h>
#include<stdlib.h>
int main()
{
	int bt[10],i,at[10],temp[10],n,time,flag=0,t_quantum,wait=0,turnaround_time,count,left,j,prior[10];
	printf("enter the number of values\n");
	scanf("%d",&n);
	left = n;
	for(i=0;i<n;i++)
	{
		printf("enter priority and burst time respectively \n");
		
		scanf("%d",&prior[i]);
		scanf("%d",&bt[i]);
		temp[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(prior[i]>prior[j])
			{ 
				int temp4 = prior[j];
				prior[j] = prior[i];
				prior[i] = temp4;
				int temp3 = bt[j];
				bt[j]=bt[i];
				bt[i]=temp3;
				int temp2 = temp[j];
				temp[j] = temp[i];
				temp[i] = temp2;
				
			}
		}
	}
	for(i=0;i<n;i++)
	{
		
		printf("%d\n",prior[i]);
		printf("%d\n",bt[i]);
		
	}
				
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
	for(i=0,count=0;i<n;i++,count++)
	{	time=time+bt[i];
		printf("P[%d]\t|\t%d\t|\t%d\n",temp[count],time,time-bt[count]); 
		wait=wait+ time-bt[count];
		turnaround_time+= time;
	}
	printf("\nAverage Waiting Time= %f\n",wait*1.0/n); 
  	printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
return 0;
}

		
