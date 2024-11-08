#include <stdio.h>

int main() {
    int frames[3] = {-1, -1, -1}; 
    int pages[] = {1, 2, 3, 4, 1, 2, 5}; 
    int pageCount = 7;
    int pageFaults = 0;
    int time[3] = {0, 0, 0}; 

    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int found = 0, least_recent = 0;

        for (int j = 0; j < 3; j++) {
            if (frames[j] == page) {
                found = 1;
                time[j] = i; 
                break;
            }
        }

        if (!found) {
            for (int j = 1; j < 3; j++) {
                if (time[j] < time[least_recent]) {
                    least_recent = j;
                }
            }
            frames[least_recent] = page;  
            time[least_recent] = i;       
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
