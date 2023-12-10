//sjf

#include<stdio.h>
#include<stdlib.h>
struct proc
{
    int arrival;
    int brust;
    int comp;
    int turn;
    int wait;
    int done;
    };
    
    int main()
    {
    int n;
    printf("enter the no of process");
    scanf("%d",&n);
    struct proc arr[n];
    for(int i=0;i<n;i++)
    {
    scanf("%d",&arr[i].arrival);
    scanf("%d",&arr[i].brust);
    }
    for(int i=0;i<n;i++)
    {
    arr[i].done=0;
    } 
    struct proc temp;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n-i-1;j++)
    {
    if(arr[j].arrival>arr[j+1].arrival)
    {
    temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
    }
    }
    }
    arr[0].comp=arr[0].arrival+arr[0].brust;
    arr[0].done=1;
    int current=arr[0].comp;
    for(int i=1;i<n;i++)
    {
    if(arr[i].done==0)
    {
    int min=arr[i].brust;
    int k=0;
    for(int j=1;j<n;j++)
    {
    if(arr[j].done==0)
    {
    if(min>arr[j].brust)
    {
    min=arr[j].brust;
    k=j;
    }
    }
    }
    arr[k].comp=arr[k].brust+current;
    current=arr[k].comp;
    arr[k].done=1;
    }
    }
    for(int i=0;i<n;i++)
    {
    if(arr[i].done==0)
    {
    arr[i].comp=arr[i].brust+current;
    arr[i].done=1;
    current=arr[i].comp;
    }
    }
    for(int i=0;i<n;i++)
    {
    arr[i].turn=arr[i].comp-arr[i].arrival;
    }
    for(int j=0;j<n;j++)
    {
    arr[j].wait=arr[j].turn-arr[j].brust;
    }
    float avg=0.0,avgg=0.0;
    for(int i=0;i<n;i++)
    {
    avg+=arr[i].turn;
    avgg+=arr[i].wait;
    }
    avg=avg/5.0;
    avgg=avgg/5.0;
    printf("arrival brust comp turn wait\n");
    for(int i=0;i<n;i++)
    {
    printf("%d %d %d %d %d\n",arr[i].arrival,arr[i].brust,arr[i].comp,arr[i].turn,arr[i].wait);
    }
    printf("the average turn around time %f\n",avg);
    printf("the average waiting time %f\n",avgg);
    return 0; 
}
