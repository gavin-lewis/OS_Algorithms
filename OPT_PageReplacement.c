#include<stdio.h>
int main()
{
  int pages[20],frames[3],numhit=0,miss=0,hit,temp=-1,num,n,i,j,interval[3],found,pos,max;
  printf("Enter the number of pages : ");
  scanf("%d",&num);
  for(i=0;i<3;i++)
  {
    frames[i] = -1;
  }
  printf("Enter the reference string : \n");
  for(i=0;i<num;i++)
  {
    scanf("%d",&pages[i]);
  }
  for(i=0;i<num;i++)
  {
    hit = 0;
    printf("%d\t",pages[i]);
    for(j=0;j<3;j++)
    {
      if(frames[j] == pages[i])
      {
        hit=1;
        numhit++;
        printf("Hit\t");
        break;
      }
    }
      if(hit!=1)
      {
        miss++;
        printf("Miss\t");
        if(temp==2)
        {
          for(j=0;j<3;j++)
          {
            for(n=i+1;n<num;n++)
            {
              interval[j]=0;
              if(frames[j]==pages[n])
              {
                interval[j]=n-i;
                break;
              }
            }
          }
          found=0;
          for(n=0;n<3;n++)
          {
            if(interval[n]==0)
            {
              pos=n;
              found=1;
              break;
            }
          }
        }
        else
        {
          pos = ++temp;
          found=1;
        }
        if(found==0)
        {
          pos=0;
          max=interval[0];
          for(j=1;j<3;j++)
          {
            if(max<interval[j])
            {
              max=interval[j];
              pos=j;
            }
          }
        }
        frames[pos]=pages[i];
      }
      for(n=0;n<3;n++)
      {
        printf("%d",frames[n]);
        printf(" ");
      }
      printf("\n");
    }
    printf("Total number of hits are : %d\n",numhit);
    printf("Total number of misses are : %d\n",miss);
    return 0;
}
