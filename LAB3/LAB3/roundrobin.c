#include<stdio.h>
#include<stdlib.h>
int main()
{
	int bt[10],i,at[10],temp[10],n,time,flag=0,t_quantum,wait_time=0,turnaround_time,count,left;
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
	printf("enter the time quantum\n");
	scanf("%d",&t_quantum);
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
	for(count=0,time=0;left!=0;)
	{
		if(temp[count]<=t_quantum && temp[count]>0)
		{
			time = time + temp[count];
			temp[count] = 0;
			flag =1;
		}
		else if(temp[count]>0)
		{
			time =time + t_quantum;
			temp[count]= temp[count]-t_quantum;
		}
		if(temp[count]==0 && flag ==1)
		{
			left--;
			printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
			wait_time+=time-at[count]-bt[count]; 
			turnaround_time+=time-at[count]; 
			flag=0; 
		} 
		
		if(count == n-1)
		{
			count = 0;
		}
		else if(at[count+1]<= time)
		{
			count++;
		}
		else
		{
			count =0;
		}
	}

		printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  		printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}
