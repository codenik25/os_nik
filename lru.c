#include <stdio.h>
#include <stdlib.h>

void displayFrames(int frames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int findLRU(int time[], int frameCount) {
    int minTime = time[0], pos = 0;
    for (int i = 1; i < frameCount; i++) {
        if (time[i] < minTime) {
            minTime = time[i];
            pos = i;
        }
    }
    return pos;
}

void lruPageReplacement(int pages[], int pageCount, int frameCount) {
    int frames[frameCount], time[frameCount];
    int pageFaults = 0, currentTime = 0;

    // Initialize frames and time array
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1; // -1 indicates an empty frame
        time[i] = 0;
    }

    printf("Page Reference String | Frames\n");
    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in frames
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                found = 1;
                time[j] = currentTime++; // Update time for LRU tracking
                break;
            }
        }

        if (!found) {
            // Page fault occurred
            int pos = findLRU(time, frameCount);
            frames[pos] = page;
            time[pos] = currentTime++;
            pageFaults++;
        }

        // Display the current state of frames
        printf("%d\t\t\t| ", page);
        displayFrames(frames, frameCount);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pageCount, frameCount;

    printf("Enter the number of pages: ");
    scanf("%d", &pageCount);
    int pages[pageCount];

    printf("Enter the page reference string: ");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);

    lruPageReplacement(pages, pageCount, frameCount);

    return 0;
}
