#include<stdio.h>
int n,in[10],b[10],w[10],tt[10],stt=0,sw=0,i,j,temp;
void sjf()
{
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(b[j]>b[j+1])
                {
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;

                    temp=in[j];
                    in[j]=in[j+1];
                    in[j+1]=temp;
                }
            }
        }
        int sum=0;
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<i;j++)
            {
                sum=sum+b[j];
            }
            w[i]=sum;
        }
        printf("Gant Chart for the process is :\n+");
    for(i=0;i<(6*n);i++)
        printf("-");
    printf("\n|");
    for(i=0;i<n;i++)
        printf(" P %d |",in[i]);
    printf("\n+");
    for(i=0;i<(n);i++)
        printf("-----+");
    printf("\n");
    for(i=0;i<n;i++)
        if(w[i]/10==0)
            {printf("%d     ",w[i]);}
        else if(w[i]/100==0)
            {printf("%d    ",w[i]);}
        else
            {printf("%d   ",w[i]);}
    printf("%d     \n",(w[i-1]+b[i-1]));
}

void main()
{
    printf("Enter number of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter burst time of process %d: ",i+1);
        scanf("%d",&b[i]);
        in[i]=i+1;
    }
    sjf();
}
