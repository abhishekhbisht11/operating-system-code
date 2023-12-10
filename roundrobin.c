/*#include<stdio.h>
 
int main()
{
 
  int cnt,j,n,t,remain,flag=0,tq;
  int wt=0,tat=0,at[10],bt[10],rt[10];
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  remain=n;
  for(cnt=0;cnt<n;cnt++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",cnt+1);
    scanf("%d",&at[cnt]);
    scanf("%d",&bt[cnt]);
    rt[cnt]=bt[cnt];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&tq);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(t=0,cnt=0;remain!=0;)
  {
    if(rt[cnt]<=tq && rt[cnt]>0)
    {
      t+=rt[cnt];
      rt[cnt]=0;
      flag=1;
    }
    else if(rt[cnt]>0)
    {
      rt[cnt]-=tq;
      t+=tq;
    }
    if(rt[cnt]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",cnt+1,t-at[cnt],t-at[cnt]-bt[cnt]);
      wt+=t-at[cnt]-bt[cnt];
      tat+=t-at[cnt];
      flag=0;
    }
    if(cnt==n-1)
      cnt=0;
    else if(at[cnt+1]<=t)
      cnt++;
    else
      cnt=0;
  }
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
  printf("Avg Turnaround Time = %f",tat*1.0/n);
  
  return 0;
}



//roundrobin
#include<stdio.h>
 
int main()
{
  int processCount, n, currentTime, remainingProcesses, flag, timeQuantum;
  int totalWaitingTime = 0, totalTurnaroundTime = 0;
  int arrivalTime[10], burstTime[10], remainingTime[10];
  
  // Get the number of processes
  printf("Enter the total number of processes: ");
  scanf("%d", &n);
  remainingProcesses = n;
  
  // Input arrival and burst times for each process
  for(processCount = 0; processCount < n; processCount++)
  {
    printf("Enter Arrival Time for Process %d: ", processCount + 1);
    scanf("%d", &arrivalTime[processCount]);
    printf("Enter Burst Time for Process %d: ", processCount + 1);
    scanf("%d", &burstTime[processCount]);
    remainingTime[processCount] = burstTime[processCount];
  }
  
  // Input time quantum
  printf("Enter Time Quantum: ");
  scanf("%d", &timeQuantum);
  
  printf("\nProcess\t| Turnaround Time\t| Waiting Time\n\n");
  
  currentTime = 0;
  flag = 0;
  
  while (remainingProcesses != 0)
  {
    for (processCount = 0; processCount < n; processCount++)
    {
      if (remainingTime[processCount] <= timeQuantum && remainingTime[processCount] > 0)
      {
        currentTime += remainingTime[processCount];
        remainingTime[processCount] = 0;
        flag = 1;
      }
      else if (remainingTime[processCount] > 0)
      {
        currentTime += timeQuantum;
        remainingTime[processCount] -= timeQuantum;
      }
      
      if (remainingTime[processCount] == 0 && flag == 1)
      {
        remainingProcesses--;
        printf("P%d\t|\t%d\t|\t%d\n", processCount + 1, currentTime - arrivalTime[processCount],
         currentTime - arrivalTime[processCount] - burstTime[processCount]);
        totalWaitingTime += currentTime - arrivalTime[processCount] - burstTime[processCount];
        totalTurnaroundTime += currentTime - arrivalTime[processCount];
        flag = 0;
      }
    }
  }
  
  printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
  printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
  
  return 0;
}



*/
//round robin
// Include required header files  
#include <stdio.h>

// Macro to define maximum number of processes
#define MAX_PROCESSES 5 

// Structure to represent a process
struct Process {
  int pid; // Process ID
  int bt; // CPU burst time
  int wt; // Waiting time
  int tat; // Turn around time
};

int main() {

  // Step 1: Accept number of processes
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);

  // Step 2: Accept burst time for each process
  struct Process proc[MAX_PROCESSES];
  for(int i=0; i<n; i++) {
    proc[i].pid = i+1; 
    printf("Enter burst time for process %d: ", proc[i].pid);
    scanf("%d", &proc[i].bt);
  }

  // Step 3: Accept time quantum 
  int quantum;
  printf("Enter time quantum: ");
  scanf("%d", &quantum);

  // Step 4: Calculate waiting time and turn around time
  int rem_bt[MAX_PROCESSES];
  for(int i = 0; i < n; i++)
    rem_bt[i] = proc[i].bt;
  
 int t = 0; // Current time
  while(1) {
    bool done = true;
    
    // Traverse processes one by one repeatedly
    for(int i = 0; i < n; i++) {
      if(rem_bt[i] > 0) {
        done = false; // There is still at least one pending process
        
        if(rem_bt[i] > quantum) {
          t += quantum;
          rem_bt[i] -= quantum;
        }
        else {
          t += rem_bt[i];
          proc[i].wt = t - proc[i].bt;
          rem_bt[i] = 0;
        }
      }
    }

    // If all processes are done
    if(done == true)
      break;
  }
  
  // Calculate turn around time
  for(int i=0; i<n; i++)
    proc[i].tat = proc[i].bt + proc[i].wt;

  // Step 5: Print process details
  printf("\nProcess  Burst Time  Waiting Time  Turn Around Time");
  for(int i=0; i<n; i++) {
    printf("\nP%d\t\t%d\t\t%d\t\t%d", proc[i].pid, proc[i].bt, proc[i].wt, proc[i].tat);
  }

  return 0;
}
