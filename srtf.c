//srtf
#include <stdio.h>
#include <stdlib.h>

struct proc
{
    int arrival;
    int burst;
    int comp;
    int turn;
    int wait;
};

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct proc arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arr[i].arrival);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &arr[i].burst);
        arr[i].comp = 0;
        arr[i].turn = 0;
        arr[i].wait = 0;
    }

    int currentTime = 0;
    int completed = 0;
    while (completed < n)
    {
        int shortestRemainingTime = -1;
        int selectedProcess = -1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i].arrival <= currentTime && arr[i].burst > 0)
            {
                if (shortestRemainingTime == -1 || arr[i].burst < shortestRemainingTime)
                {
                    shortestRemainingTime = arr[i].burst;
                    selectedProcess = i;
                }
            }
        }

        if (selectedProcess == -1)
        {
            currentTime++;
        }
        else
        {
            arr[selectedProcess].burst--;
            currentTime++;
            if (arr[selectedProcess].burst == 0)
            {
                completed++;
                arr[selectedProcess].comp = currentTime;
                arr[selectedProcess].turn = arr[selectedProcess].comp - arr[selectedProcess].arrival;
                arr[selectedProcess].wait = arr[selectedProcess].turn - arr[selectedProcess].burst;
            }
        }
    }

    float avgTurnaroundTime = 0.0, avgWaitingTime = 0.0;
    for (int i = 0; i < n; i++)
    {
        avgTurnaroundTime += arr[i].turn;
        avgWaitingTime += arr[i].wait;
    }
    avgTurnaroundTime /= n;
    avgWaitingTime /= n;

    printf("Arrival Burst Completion Turnaround Waiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", arr[i].arrival, arr[i].burst, arr[i].comp, arr[i].turn, arr[i].wait);
    }
    printf("Average Turnaround Time: %f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %f\n", avgWaitingTime);

    return 0;
}
