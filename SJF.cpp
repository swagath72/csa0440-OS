#include <stdio.h>

int main() {
    int n, i, j, temp;
    int arrival_time[20], burst_time[20], waiting_time[20], turnaround_time[20], completed[20] = {0};
    int total_wt = 0, total_tat = 0, time = 0, min_index;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &burst_time[i]);
    }


    int processes_completed = 0;
    while (processes_completed < n) {
        min_index = -1;
        int min_burst = 10000;

        
        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= time && !completed[i] && burst_time[i] < min_burst) {
                min_burst = burst_time[i];
                min_index = i;
            }
        }

        if (min_index != -1) {
            time += burst_time[min_index];
            waiting_time[min_index] = time - arrival_time[min_index] - burst_time[min_index];
            turnaround_time[min_index] = waiting_time[min_index] + burst_time[min_index];
            completed[min_index] = 1;
            processes_completed++;

            total_wt += waiting_time[min_index];
            total_tat += turnaround_time[min_index];
        } else {
            time++;
        }
    }

    
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    
    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
