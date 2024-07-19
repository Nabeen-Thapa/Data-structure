#include<stdio.h>
#include<conio.h>
typedef struct
{
	int pid;
	int burst;
}process;
void swap(process *a,process *b)
{
	process temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(process p[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(p[j].burst<p[min].burst)
				min=j;
		}
		swap(&p[i],&p[min]);
	}
}
void calculateTime(process p[],int n, int waiting[],int turnaround[])
{
	int i;
	waiting[0]=0;
	turnaround[0] = p[0].burst;
	for(i=1;i<n;i++)
		waiting[i]=waiting[i-1]+p[i-1].burst;
	for(i=1;i<n;i++)
		turnaround[i]=waiting[i]+p[i].burst;	
}
void calculateAverage(process p[],int n)
{
	int i,waiting[n],turnaround[n];
	int totalwaiting = 0, totalturnaround = 0;
	calculateTime(p,n,waiting,turnaround);
	printf("process\t\tBurst time\twaiting time\t turnaround time\n");
	for(i=0;i<n;i++)
	{
		totalwaiting+=waiting[i];
		totalturnaround+=turnaround[i];
		printf("%d\t\t %d\t\t %d\t\t  %d\n",p[i].pid,p[i].burst,waiting[i],turnaround[i]);
	}
	double averagewaiting =(double)totalwaiting/n;
	double averageturnaround =(double)totalturnaround/n;
	printf("\nAverage waiting time : %f",averagewaiting);
	printf("\nAverage turnaround time : %f",averageturnaround);
}
void main()
{
	printf("Nabin Thapa\n\n");
	int i,n;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	process p[n];
	printf("Enter burst time:");
	for(i=0;i<n;i++)
	{
		printf("\nProcess %d:\n",i+1);
		p[i].pid=i+1;
		printf("burst time:");
		scanf("%d",&p[i].burst);
	}
	sort(p,n);
	calculateAverage(p,n);
	getch();
}
