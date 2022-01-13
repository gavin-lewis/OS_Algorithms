#include<stdio.h>
typedef struct
{
  int wt;
  int bt;
  int pid;
  int tt;
}Process;
void print_table(Process p[],int n);
void print_ganttchart(Process p[],int n);
int main()
{
  Process p[20];
  int i,num,sum_wt=0,sum_tt=0;
  double average_wt,average_tt;
  printf("Enter the number of processes : ");
  scanf("%d",&num);
  printf("Enter the burst time for each process : \n");
  for(i=0;i<num;i++)
  {
    printf("P[%d]:",i+1);
    scanf("%d",&p[i].bt);
    p[i].wt = p[i].tt = 0;
    p[i].pid=i+1;
  }
  p[0].tt = p[0].bt;
  for(i=1;i<num;i++)
  {
    p[i].wt = p[i-1].bt + p[i-1].wt;
    p[i].tt = p[i].bt + p[i].wt;
  }
  for(i=0;i<num;i++)
  {
    sum_wt += p[i].wt;
    sum_tt = sum_tt + p[i].tt;
  }
  average_wt = (double)sum_wt/num;
  average_tt = (double)sum_tt/num;
  puts(" ");
  print_table(p,num);
  printf("Total waiting time is : %d\n",sum_wt);
  printf("Average waiting time is : %.2f\n",average_wt);
  printf("Total turn around time is : %d\n",sum_tt);
  printf("Average Turn around time is : %.2f\n",average_tt);
  puts(" ");
  puts("        GANTT CHART        ");
  puts("        ***********        ");
  print_ganttchart(p,num);
  return 0;
}
void print_table(Process p[],int num)
{
  int i;
  puts("+-----+------------+--------------+-----------------+");
  puts("| PID | Burst Time | Waiting Time | Turnaround Time |");
  puts("+-----+------------+--------------+-----------------+");
  for(i=0;i<num;i++)
  {
    printf("| %2d  |      %2d    |       %2d     |         %2d      |\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
    puts("+-----+------------+--------------+-----------------+");
  }
}
void print_ganttchart(Process p[],int num)
{
  int i,j;
  for(i=0;i<num;i++)
  {
    for(j=0;j<p[i].bt;j++)
      printf("--");
    printf(" ");
  }
  printf("\n|");
  for(i=0;i<num;i++)
  {
    for(j=0;j<p[i].bt-1;j++)
      printf(" ");
    printf("P%d",p[i].pid);
    for(j=0;j<p[i].bt-1;j++)
      printf(" ");
    printf("|");
  }
  printf("\n");
  for(i=0;i<num;i++)
  {
    for(j=0;j<p[i].bt;j++)
      printf("--");
    printf(" ");
  }
  printf("\n");
  printf("0");
  for(i=0;i<num;i++)
  {
    for(j=0;j<p[i].bt;j++)
    {
      printf("  ");
    }
    if(p[i].tt>9)
      printf("\b");
    printf("%d",p[i].tt);
  }
  printf("\n");
}
