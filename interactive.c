#include <stdio.h>
#include <time.h>

int main ()
{
	
	clock_t timer;
	int n,s,t,i;

	printf("\n\t\t----Welcome---\n");
	printf("\n\nNow depending on your input frequency will decide the Interactiveness of program\n");
	printf("Enter the no. of processes you want to consider:- \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("For Process %d response stroke :- \n",i);
		while (1)
		{
			scanf("%d",&s);
			if(s!=NULL)
			{
				t=timer;
				break;
			}
		}
		if(s==1)
		{
			printf("\n\tInteractive PRocesss\n");
		
		}
		else
			{printf("\n\tNon-Interactive Process\n");}

	}
	printf( "\n\nThank You .... Visit Again\n\n");

return 0;
}
