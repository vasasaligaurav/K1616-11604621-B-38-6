#include<stdio.h>
	int gav_pid[11],gav_at[11],gav_bt[11],gav_rt[11],gav_end,i,k,gav_lrgst,gav_gnt[25],uniq;
	int rmn=0,g,gav_time,s_wait=0,s_trnarnd=0;
void input()
{
	printf("\t\t******************SHORTEST EXUCUTION TIME FIRST***********************\nEnter no of Processes :");
    scanf("%d",&g);
    for(k=0;k<g;k++)
    {
		printf("Give u r input for PROCESS ID:-- %d : ",k+1);
		scanf("%d",&gav_pid[k]);
		
		printf("Give input of their ARRIVAL TIME :-- %d : ",k+1);
		scanf("%d",&gav_at[k]);
		if(gav_at[k]>10)
		{
				printf("plz enter the process arrival with less than 10 value\n");
				scanf("%d",&gav_at[k]);
			
		}
		printf("Give the input of their BURST TIME:-- %d : ",k+1);
		scanf("%d",&gav_bt[k]);
		
			if(gav_bt[k]>10)
		{
				printf("plz enter the process burst with less than 10 value\n");
				scanf("%d",&gav_bt[k]);
			
		}
		
		gav_rt[k]=gav_bt[k];
	}
	
	


}
void show()
{
	
		printf("\n\nProcess\t||Turnaround Time|| Waiting Time\n\n");
gav_rt[9]=9999;
for(gav_time=0;rmn!=g;gav_time++)
{
gav_lrgst=9;
for(i=0;i<g;i++)
{
if(gav_at[i]<=gav_time && gav_rt[i]<gav_rt[gav_lrgst] && gav_rt[i]>0)
{
gav_gnt[gav_time]=i;
gav_lrgst=i;
}
}
gav_rt[gav_lrgst]--;
if(gav_rt[gav_lrgst]==0)
{
rmn++;
gav_end=gav_time+1;
printf("\nP[%d]\t||\t%d\t||\t%d",gav_lrgst+1,gav_end-gav_at[gav_lrgst],gav_end-gav_bt[gav_lrgst]-gav_at[gav_lrgst]);
s_wait+=gav_end-gav_bt[gav_lrgst]-gav_at[gav_lrgst];
s_trnarnd+=gav_end-gav_at[gav_lrgst];
}
}

}
void show1()
{
	printf("\nAverage   Waiting Time = %f\n",s_wait*1.0/g);
printf("\nAverage Turnaround  Time = %f\n\n",s_trnarnd*1.0/5);
for(i=1;i<=gav_time;i++)
{
	if(i<gav_time)
	{
		printf("%d->P%d \n",i,gav_gnt[i]+1);
		uniq=gav_gnt[i]+1;
	}
	else
	{
		printf("%d->P%d \n",i,uniq);
	}
}
}
int main()
{
input();
show();
show1();
	
}

