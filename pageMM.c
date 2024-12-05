#include <stdio.h>
#include <stdlib.h>

void displayPageTable(int pageTable[], int pageCount) {
    printf("\nPage Table (Page -> Frame):\n");
    for (int i = 0; i < pageCount; i++) {
        printf("Page %d -> Frame %d\n", i, pageTable[i]);
    }
}

void pagingSimulation(int pageCount, int frameCount, int pageSize) {
    int pageTable[pageCount]; // To store page-to-frame mapping
    int logicalAddress, pageNumber, offset, frameNumber, physicalAddress;

    // Initialize page table with random frame numbers (for simulation)
    for (int i = 0; i < pageCount; i++) {
        pageTable[i] = i % frameCount; // Frames are reused cyclically
    }

    displayPageTable(pageTable, pageCount);

    while (1) {
        printf("\nEnter a logical address (-1 to exit): ");
        scanf("%d", &logicalAddress);

        if (logicalAddress == -1) break;

        // Calculate page number and offset
        pageNumber = logicalAddress / pageSize;
        offset = logicalAddress % pageSize;

        if (pageNumber >= pageCount) {
            printf("Invalid logical address! Page number exceeds total pages.\n");
            continue;
        }

        // Find the frame number using the page table
        frameNumber = pageTable[pageNumber];

        // Calculate physical address
        physicalAddress = frameNumber * pageSize + offset;

        printf("Logical Address: %d -> Physical Address: %d (Page: %d, Offset: %d, Frame: %d)\n",
               logicalAddress, physicalAddress, pageNumber, offset, frameNumber);
    }
}

int main() {
    int pageCount, frameCount, pageSize;

    printf("Enter the number of pages: ");
    scanf("%d", &pageCount);

    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);

    printf("Enter the size of each page (in bytes): ");
    scanf("%d", &pageSize);

    pagingSimulation(pageCount, frameCount, pageSize);

    return 0;
}
