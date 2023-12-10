#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int queue[20], n, head, i,j, seek = 0, max, diff, temp, temp1 = 0, temp2 = 0;

    printf("Enter the max range of disk: ");
    scanf("%d", &max);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the size of queue request: ");
    scanf("%d", &n);

    int queue1[20], queue2[20];

    printf("Enter the queue of disk positions to be read:\n");
    for (i = 1; i <= n; i++) 
    {
        scanf("%d", &temp);
        (temp >= head) ? (queue1[temp1++] = temp) : (queue2[temp2++] = temp);
    }

    // Sort queue1 and queue2
    for (i = 0; i < temp1 - 1; i++)
        for (int j = i + 1; j < temp1; j++)
            if (queue1[i] > queue1[j]) {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }

    for (i = 0; i < temp2 - 1; i++)
        for (int j = i + 1; j < temp2; j++)
            if (queue2[i] > queue2[j]) 
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }

    // Merge sorted queues
    for (i = 1,  j = 0; j < temp1; i++, j++)
        queue[i] = queue1[j];

        queue[i] = max;
        queue[i + 1] = 0;

    for (i = temp1 + 3,  j = 0; j < temp2; i++, j++)
        queue[i] = queue2[j];

        queue[0] = head;

    printf("The C-SCAN Sequence is: ");
    for (i = 0; i <= n + 1; i++) 
    {
        diff = abs(queue[i + 1] - queue[i]);
        seek += diff;
        printf("%d ", queue[i + 1]);
    }

    printf("\nTotal seek time is %d\n", seek);

    return 0;
}
