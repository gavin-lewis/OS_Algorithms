#include<stdio.h>
int main()
{
    int i,j,frame[50],n,no,avail,k,a[50],count=0;
    printf("Enter number of pages:");
    scanf("%d",&n);
    printf("Enter the page number:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("Enter number of frames:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
        frame[i]=-1;
    j=0;
    printf("\tRef String \tPage frames\n");
    for(i=1;i<=n;i++)
    {
        printf("\t%d\t",a[i]);
        avail=0;
        for(k=0;k<no;k++)
            if(frame[k]==a[i])
                avail=1;
        if(avail==1)
        {
            for(k=0;k<no;k++)
                printf("%d\t",frame[k]);
            printf("HIT");
        }
        if(avail==0)
        {
            frame[j]=a[i];
            j=(j+1)%no;
            count++;
            for(k=0;k<no;k++)
                printf("%d\t",frame[k]);
            printf("MISS");
        }
        printf("\n");
    }
    printf("Total page faults:%d",count);
    return 0;
}
