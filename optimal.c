#include <stdio.h>

void displayFrames(int frames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}

int findOptimal(int frames[], int frameCount, int pages[], int currentIndex, int pageCount) {
    int farthest = -1, replaceIndex = -1;

    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = currentIndex + 1; j < pageCount; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        if (j == pageCount) {
            return i; // Page not used in future
        }
    }

    return (replaceIndex == -1) ? 0 : replaceIndex;
}

void optimalPageReplacement(int pages[], int pageCount, int frameCount) {
    int frames[frameCount];
    int pageFaults = 0;

    // Initialize frames to empty
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    printf("Page Reference | Frames\n");
    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) { // Page fault occurs
            pageFaults++;
            int replaceIndex = -1;

            // Check for an empty frame
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // If no empty frame, find the optimal page to replace
            if (replaceIndex == -1) {
                replaceIndex = findOptimal(frames, frameCount, pages, i, pageCount);
            }

            // Replace the page
            frames[replaceIndex] = page;
        }

        // Display current frame status
        printf("%d\t\t| ", page);
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

    optimalPageReplacement(pages, pageCount, frameCount);

    return 0;
}
