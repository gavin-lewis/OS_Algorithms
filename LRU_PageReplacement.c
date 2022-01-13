#include<stdio.h>
int pages[50],frames[50],i,j,r,nmiss=0,nhit=0,temp=0,c[50],n,hit,max,pos;
void main()
{
    printf("Enter numberof pages:");
    scanf("%d",&n);
    printf("Enter pages:");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);
    for(i=0;i<3;i++)
        frames[i]=-1;
    for(i=0;i<n;i++)
    {
        hit=0;
        printf("%d\t",pages[i]);
        for(j=0;j<3;j++)
        {
            if(pages[i]==frames[j])
            {
                hit=1;
                nhit++;
                printf("Hit\t");
                break;
            }
        }
        if(hit==0)
        {
            printf("Miss\t");
            nmiss++;
            if(temp<3)
            {
                frames[temp]=pages[i];
                temp++;

            }
            else
            {
                for(r=0;r<3;r++)
                {
                    c[r]=0;
                    for(j=i-1;j>=0;j--)
                    {
                        if(frames[r]!=pages[j])
                            c[r]++;
                        else
                            break;
                    }

                }
                max=c[0];
                pos=0;
                for(r=1;r<3;r++)
                {
                    if(max<c[r])
                    {
                        max=c[r];
                        pos=r;
                    }
                }
                frames[pos]=pages[i];
            }
        }
        for(j=0;j<3;j++)
            printf("%d ",frames[j]);
        printf("\n");
    }
    printf("Hit %d \n Miss:%d",nhit,nmiss);
}
