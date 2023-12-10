#include <stdio.h>
#include <limits.h>

int checkHit(int incomingPage, int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
    {
        if (incomingPage == queue[i])
            return 1;
    }

    return 0;
}

void printFrame(int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
        printf("%d\t\t\t", queue[i]);
}

int main()
{
    int frames;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int n;
    printf("Enter the number of pages in the incoming stream: ");
    scanf("%d", &n);

    int incomingStream[n];

    printf("Enter the page numbers in the incoming stream:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Page %d: ", i + 1);
        scanf("%d", &incomingStream[i]);
    }

    int queue[n];
    int distance[n];
    int occupied = 0;
    int pagefault = 0;

    printf("\nPage\t Frame1 \t Frame2 \t Frame3\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d:  \t\t", incomingStream[i]);

        if (checkHit(incomingStream[i], queue, occupied))
        {
            printFrame(queue, occupied);
        }
        else if (occupied < frames)
        {
            queue[occupied] = incomingStream[i];
            pagefault++;
            occupied++;

            printFrame(queue, occupied);
        }
        else
        {
            int max = INT_MIN;
            int index;

            for (int j = 0; j < frames; j++)
            {
                distance[j] = 0;
                for (int k = i - 1; k >= 0; k--)
                {
                    ++distance[j];

                    if (queue[j] == incomingStream[k])
                        break;
                }

                if (distance[j] > max)
                {
                    max = distance[j];
                    index = j;
                }
            }
            queue[index] = incomingStream[i];
            printFrame(queue, occupied);
            pagefault++;
        }

        printf("\n");
    }

    float pageFaultRatio = (float)pagefault / n;
    float pageHitRatio = 1 - pageFaultRatio;

    printf("\nPage Fault Ratio: %.2f\n", pageFaultRatio);
    printf("Page Hit Ratio: %.2f\n", pageHitRatio);

    return 0;
}
