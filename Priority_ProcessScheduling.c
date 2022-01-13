#include<stdio.h>
int sum_wt=0,sum_tt=0;
typedef struct
{
  int bt;
  int wt;
  int tt;
  int pid;
  int priority;
}Process;
void sort(Process p[],int num);
void calculate(Process p[],int num);
void print_ganttchart(Process p[],int num);
void print_table(Process p[],int num);
int main()
{
  Process p[20];
  int num,i;
  double average_tt,average_wt;
  printf("Enter the number of processes : ");
  scanf("%d",&num);
  printf("Enter the burst time and priority of each process : \n");
  for(i=0;i<num;i++)
  {
    printf("Priority[%d]:",i+1);
    scanf("%d",&p[i].priority);
    printf("Burst Time[%d]:",i+1);
    scanf("%d",&p[i].bt);
    p[i].pid = i+1;
  }
  sort(p,num);
  calculate(p,num);
  average_wt = (double)sum_wt/num;
  average_tt = (double)sum_tt/num;
  printf("The total waiting time is : %d\n",sum_wt);
  printf("Average waiting time is : %.2f\n",average_wt);
  printf("The total turn around time is : %d\n",sum_tt);
  printf("Average Turn around time is : %.2f\n",average_tt);
  print_table(p,num);
  puts(" ");
  puts("        GANTT CHART        ");
  print_ganttchart(p,num);
  return 0;
}
void sort(Process p[],int num)
{
  int i,j;
  Process temp;
  for(i=0;i<num-1;i++)
  {
    for(j=i+1;j<num;j++)
    {
      if(p[i].priority>p[j].priority)
      {
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
      }
    }
  }
}
  void calculate(Process p[],int num)
  {
    int i;
    p[0].wt=0;
    p[0].tt=p[0].bt;
    for(i=1;i<num;i++)
    {
      p[i].wt=p[i-1].wt+p[i-1].bt;
      p[i].tt=p[i].wt+p[i].bt;
    }
    for(i=0;i<num;i++)
    {
      sum_wt += p[i].wt;
      sum_tt += p[i].tt;
    }
  }
  void print_table(Process p[],int num)
  {
    int i;
    puts("+-----+------------+----------+--------------+-----------------+");
    puts("| PID | Burst Time | Priority | Waiting Time | Turnaround Time |");
    puts("+-----+------------+----------+--------------+-----------------+");
    for(i=0;i<num;i++)
    {
      printf("| %2d  |      %2d    |     %2d   |       %2d     |         %2d      |\n",p[i].pid,p[i].bt,p[i].priority,p[i].wt,p[i].tt);
      puts("+-----+------------+----------+--------------+-----------------+");
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
