/*preemptive priority cpu
#include <stdio.h>
 
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    int burst[n],priority[n],index[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
        scanf("%d %d",&burst[i],&priority[i]);
        index[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        int temp=priority[i],m=i;
 
        for(int j=i;j<n;j++)
        {
            if(priority[j] > temp)
            {
                temp=priority[j];
                m=j;
            }
        }
 
        swap(&priority[i], &priority[m]);
        swap(&burst[i], &burst[m]);
        swap(&index[i],&index[m]);
    }
 
    int t=0;
 
    printf("Order of process Execution is\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d is executed from %d to %d\n",index[i],t,t+burst[i]);
        t+=burst[i];
    }
    printf("\n");
    printf("Process Id\tBurst Time\tWait Time\n");
    int wait_time=0;
    int total_wait_time = 0;
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t%d\n",index[i],burst[i],wait_time);
        total_wait_time += wait_time;
        wait_time += burst[i];
    }
    
    float avg_wait_time = (float) total_wait_time / n;
    printf("Average waiting time is %f\n", avg_wait_time);
    
    int total_Turn_Around = 0;
    for(int i=0; i < n; i++){
        total_Turn_Around += burst[i];
    }
    float avg_Turn_Around = (float) total_Turn_Around / n;
    printf("Average TurnAround Time is %f",avg_Turn_Around);
    return 0;
}

*/

//preemptive
#include <stdio.h>

int main() {
    int a[10], b[10], x[10];
    int waiting[10], turnaround[10], completion[10], p[10];
    int i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;

    printf("\nEnter the number of Processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter arrival time of process: ");
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter burst time of process: ");
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter priority of process: ");
        scanf("%d", &p[i]);
    }

    for (i = 0; i < n; i++)
        x[i] = b[i];

    p[9] = -1;
    for (time = 0; count != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (a[i] <= time && p[i] > p[smallest] && b[i] > 0)
                smallest = i;
        }
        b[smallest]--;

        if (b[smallest] == 0) {
            count++;
            end = time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }

    printf("Process\tburst-time\tarrival-time\twaiting-time\tturnaround-time\tcompletion-time\tPriority\n");
    for (i = 0; i < n; i++) {
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, x[i], a[i], waiting[i], turnaround[i], completion[i], p[i]);
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }

    printf("\n\nAverage waiting time = %lf", avg / n);
    printf("\nAverage Turnaround time = %lf\n", tt / n);

    return 0;
}

