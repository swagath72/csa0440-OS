#include <stdio.h>

int main() {
    int frames[3] = {-1, -1, -1}; 
    int pages[] = {1, 2, 3, 4, 1, 2, 5};
    int pageCount = 7;
    int pageFaults = 0;

    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int found = 0, replaceIndex = -1, farthest = -1;

        for (int j = 0; j < 3; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            for (int j = 0; j < 3; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;  
                    break;
                }

                
                int nextUse = pageCount;
                for (int k = i + 1; k < pageCount; k++) {
                    if (frames[j] == pages[k]) {
                        nextUse = k;
                        break;
                    }
                }

                
                if (nextUse > farthest) {
                    farthest = nextUse;
                    replaceIndex = j;
                }
            }

            frames[replaceIndex] = page;  
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
