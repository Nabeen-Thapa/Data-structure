#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
int main(){
	
	int i,n,k,request[50],move=0,cp,index[50],min,a[50],j=0,mini,cp1;
	printf("\n \t Nabin Thapa\n\n");
	printf("Enter current position:");
	scanf("%d",&cp);
	printf("\nEnter no of request:");
	scanf("%d",&n);
	cp1=cp;
	printf("\nEnter request order:");
	for(i=0;i<n;i++)
		scanf("%d",&request[i]);
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
			index[i]=abs(cp-request[i]);
		min=index[0];
		mini=0;
		for(i=1;i<n;i++){
			if(min>index[i])
			{
				min=index[i];
				mini=i;
			}
		}
		a[j]=request[mini];
		j++;
		cp=request[mini];
		request[mini]=999;
	}
	printf("Sequence is: ");
	printf("%d",cp1);
	move=move+abs(cp1-a[0]);
	for(i=1;i<n;i++){
		move=move+abs(a[i]-a[i-1]);
		printf(" -> %d",a[i]);
	}
	printf("\n Total head movement = %d",move);
	getch();
}

