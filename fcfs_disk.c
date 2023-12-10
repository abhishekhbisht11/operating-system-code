/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,req[50],cp,mov=0,i;
    printf("enter head current position:\n");
    scanf("%d",&cp);

    printf("enter no of tracks:\n");
    scanf("%d",&n);

    printf("enter order of request:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }

    mov=mov+abs(cp-req[0]);
    printf("%d->%d",cp,req[0]);

    for(int i=1;i<n;i++)
    {
        mov=mov+abs(req[i]-req[i-1]);
        printf("->%d",req[i]);
    }    
    printf("\n");
    printf("total head movement or seek time=%d\n",mov);
}
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,n,TotalHeadMoment=0,initial;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    
    // logic for FCFS disk scheduling
    
    for(i=0;i<n;i++)
    {
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    
    printf("Total head moment is %d",TotalHeadMoment);
    return 0;
}