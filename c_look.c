#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,headposition,i,j,k,seek=0,maxrange=199,difference,temp,temp1=0,temp2=0;
	float averageSeekTime;
	printf("\n \t Nabin Thapa\n\n");
	printf("Enter the number of queue requests:");
	scanf("%d",&n);
	
	int queue[n],queue1[n],queue2[n];
	
	printf("\nEnter the initial head position:");
	scanf("%d",&headposition);
	printf("\nEnter the disk position to be read(queue):");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		if(temp>headposition)
		{
			queue1[temp1]=temp;
			temp1++;
		}
		else{
			queue2[temp2]=temp;
			temp2++;
		}
	}
	for(i=0;i<temp1-1;i++)
	{
		for(j=i+1;j<temp1;j++)
		{
			if(queue1[i]>queue1[j])
			{
				temp=queue1[i];
				queue1[i]=queue1[j];
				queue1[j]=temp;
			}
		}
	}
	for(i=0;i<temp2-1;i++)
	{
		for(j=i+1;j<temp2;j++)
		{
			if(queue2[i]>queue2[j])
			{
				temp=queue2[i];
				queue2[i]=queue2[j];
				queue2[j]=temp;
			}
		}
	}
	for(i=1,j=0;j<temp1;i++,j++)
	{
		queue[i]=queue1[j];
	}
	queue[i]=queue2[0];
	for(i=temp1+1,j=0;j<temp2;i++,j++)
	{
		queue[i]=queue2[j];	
	}
	queue[0]=headposition;
	printf("%d",queue[0]);
	for(j=0;j<n;j++)
	{
		difference=abs(queue[j+1]-queue[j]);
		seek+=difference;
		printf("-->%d ",queue[j+1]);
	}
	averageSeekTime=seek/(float)n;
	printf("\nTotal Seek Time =%d",seek);
	printf("\nAverage Seek Time =%f",averageSeekTime);
	getch();
	return 0;
}
