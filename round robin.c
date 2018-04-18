 #include<stdio.h>
struct proc
{
        int idno;
        int arrival_time;
        int burst_time;
        int rem;
        int wait_time;
        int finish;
        int turnaround_time;
        float ratio;
}process[10]; //structure to hold the process information
struct proc temp;
int num;
int check_process(int);
int next_process();
 void roundrobin(int, int, int[], int[]);
 
int main()
{
          int n,time_quantum,choice;
          int bt[10],st[10],i,j,k;
for(; ;)
{
printf(" 1.Round Robin\n");

switch(choice)
{
case 1:
printf("Round Robin scheduling algorithm\n");
printf("Enter number of processes:\n");
  scanf("%d",&n);
  printf("Enter burst time for sequences:");
  for(i=0;i<n;i++)
   {
     scanf("%d",&bt[i]);
     st[i]=bt[i];        //service time
   }
   printf("Enter time quantum:");
   scanf("%d",&time_quantum);
   roundrobin(n,time_quantum,st,bt);
   break;
}// end of switch
}// end of for
}//end of main()


void roundrobin(int n,int time_quantum,int st[],int bt[])

 {                 
int time=0;
          int tat[10],wt[10],i,count=0,swt=0,stat=0,temp1,sq=0,j,k;
          float awt=0.0,atat=0.0;
         while(1)
           {
                     for(i=0,count=0;i<n;i++)
                     {
       temp1=time_quantum;
       if(st[i]==0) // when service time of a process equals zero then
  //count value is incremented
       {
         count++;
         continue;
       }
       if(st[i]>time_quantum) // when service time of a process greater than time
//quantum then time
                st[i]=st[i]-time_quantum; //quantum value subtracted from service time
       else
        if(st[i]>=0)
        {
                 temp1=st[i]; // temp1 stores the service time of a process
                 st[i]=0; // making service time equals 0
        }
        sq=sq+temp1; // utilizing temp1 value to calculate turnaround time
        tat[i]=sq; // turn around time
     } //end of for
     if(n==count) // it indicates all processes have completed their task because the count value
     break; // incremented when service time equals 0
   } //end of while
   for(i=0;i<n;i++) // to calculate the wait time and turnaround time of each process
   {
    wt[i]=tat[i]-bt[i]; // waiting time calculated from the turnaround time - burst time
    swt=swt+wt[i]; // summation of wait time
    stat=stat+tat[i]; // summation of turnaround time
   }
   awt=(float)swt/n; // average wait time
   atat=(float)stat/n; // average turnaround time
   printf("Process_no        Burst time        Wait time        Turn around time\n");
   for(i=0;i<n;i++)
    printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    printf("Avg wait time is %f\n Avg turn around time is %f\n",awt,atat);
 }// end of Round Robin


int chkprocess(int s) // function to check process remaining time is zero or not

{
        int i;
        for(i = 1; i <= s; i++)
        {
                if(process[i].rem != 0)
                        return 1;
        }
        return 0;
} // end of chkprocess


int nextprocess() // function to idnoentify the next process to be executed

{
        int min, l, i;
        min = 32000; //any limit assumed
        for(i = 1; i <= num; i++)
        {
                if( process[i].rem!=0 && process[i].rem < min)
                {
                        min = process[i].rem;
                        l = i;
                }
        }
        return 1;
} // end of nextprocess
