#include<stdio.h>
#include<math.h>
int sender(int arr[10],int n)
{
    int checksum,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    printf("SUM IS: %d",sum);
    checksum=~sum;
    printf("\nChecksum at sender is %d",checksum);
    return checksum;
}

int receiver(int arr[10],int n,int sch)
{
    int checksum,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    printf("SUM IS:%d",sum);
    sum=sum+sch;
    checksum=~sum;
    printf("\nChecksum at receiver is %d",checksum);
    return checksum;
}
int main()
{
    int sch,rch,n;
    printf("\nEnter number of bytes: ");
    scanf("%d",&n);
    int arr[n],rec[n];
    printf("\nEnter the data byte wise:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    sch=sender(arr,n);

    printf("\nEnter the data received byte wise:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&rec[i]);
    }
    rch=receiver(rec,n,sch);

    if(rch!=0)
        printf("\nErrors");
    else
        printf("\nno Errors");
}
