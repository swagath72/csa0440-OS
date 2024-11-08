#include <stdio.h>

int main() {
    int frames[3] = {-1, -1, -1};  // Fixed to 3 frames for simplicity
    int pages[] = {1, 2, 3, 4, 1, 2, 5};  // Example page sequence
    int pageCount = 7;  // Number of pages
    int pageFaults = 0, current = 0;
    for (int i = 0; i < pageCount; i++) {
        int found = 0;
        for (int j = 0; j < 3; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frames[current] = pages[i];
            current = (current + 1) % 3;
            pageFaults++;
        }

        printf("Frames: ");
        for (int j = 0; j < 3; j++) {
            if (frames[j] == -1) printf("- ");
            else printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}
