
//lru
//first code

#include <stdio.h>
#include <limits.h>

// Function to check if the incoming page is already in the frame queue
int checkHit(int incomingPage, int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
    {
        if (incomingPage == queue[i])
            return i; // Return the index of the hit page
    }

    return -1; // Return -1 if there is no hit
}

// Function to print the contents of the frame queue
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

    int queue[frames];
    int recentUse[frames];
    int occupied = 0;
    int pagefault = 0;

    printf("\nPage\t Frame1 \t Frame2 \t Frame3\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d:  \t\t", incomingStream[i]);

        int hitIndex = checkHit(incomingStream[i], queue, occupied);

        if (hitIndex != -1)
        {
            // Page hit: Update recent use and print the frame
            recentUse[hitIndex] = i;
            printFrame(queue, occupied);
        }
        else if (occupied < frames)
        {
            // Page fault: Add the incoming page to the frame and update recent use
            queue[occupied] = incomingStream[i];
            recentUse[occupied] = i;
            pagefault++;
            occupied++;

            printFrame(queue, occupied);
        }
        else
        {
            // Page replacement using LRU: Find the least recently used page
            int minIndex = 0;
            for (int j = 1; j < frames; j++)
            {
                if (recentUse[j] < recentUse[minIndex])
                    minIndex = j;
            }

            // Replace the least recently used page
            queue[minIndex] = incomingStream[i];
            recentUse[minIndex] = i;

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


//second code

#include <stdio.h>
#include <stdbool.h>

void printFrames(int frames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] != -1) {
            printf(" %d\t\t\t", frames[i]);
        } else {
            printf(" - \t\t\t");
        }
    }
}

int findLRUIndex(int recent[], int frameCount) {
    int min = recent[0];
    int index = 0;

    for (int i = 1; i < frameCount; i++) {
        if (recent[i] < min) {
            min = recent[i];
            index = i;
        }
    }

    return index;
}

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5};
    int frames = 3;
    int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int framesQueue[frames];
    int recentUse[frames];
    int pageFaults = 0;
    int pageHits = 0;

    for (int i = 0; i < frames; i++) {
        framesQueue[i] = -1;
        recentUse[i] = 0;
    }

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3\n");

    for (int i = 0; i < pages; i++) {
        bool pageFound = false;

        for (int j = 0; j < frames; j++) {
            if (incomingStream[i] == framesQueue[j]) {
                recentUse[j] = i + 1; // Update recent use
                pageHits++;
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            pageFaults++;
            int lruIndex = findLRUIndex(recentUse, frames);
            framesQueue[lruIndex] = incomingStream[i];
            recentUse[lruIndex] = i + 1; // Update recent use
        }

        printf("%d\t\t\t", incomingStream[i]);
        printFrames(framesQueue, frames);
        printf("\n");
    }

    float pageFaultRatio = (float)pageFaults / pages;
    float pageHitRatio = (float)pageHits / pages;

    printf("Total Page Faults:\t%d\n", pageFaults);
    printf("Total Page Hits:\t%d\n", pageHits);
    printf("Page Fault Ratio:\t%.2f\n", pageFaultRatio);
    printf("Page Hit Ratio:\t\t%.2f\n", pageHitRatio);

    return 0;
}
