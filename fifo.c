#include <stdio.h>

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5};
    int frames = 3;
    int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int temp[frames];
    int pageFaults = 0;

    for (int m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3\n");

    for (int m = 0; m < pages; m++) {
        int s = 0;

        for (int n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                s++;
                pageFaults--;
            }
        }

        pageFaults++;

        if ((pageFaults <= frames) && (s == 0)) {
            temp[m] = incomingStream[m];
        } else if (s == 0) {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        printf("%d\t\t\t", incomingStream[m]);

        for (int n = 0; n < frames; n++) {
            if (temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }

        printf("\n");
    }

    printf("Total Page Faults:\t%d\n", pageFaults);

    return 0;
}
