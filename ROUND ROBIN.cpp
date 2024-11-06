#include <stdio.h>

int main() {
    int n, i, time = 0, remain, quantum;
    int arrival_time[20], burst_time[20], remaining_time[20], waiting_time[20], turnaround_time[20];
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    remain = n;

    
    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    printf("Enter Quantum Time: ");
    scanf("%d", &quantum);

    
    while (remain != 0) {
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] <= quantum && arrival_time[i] <= time) {
                    time += remaining_time[i];
                    waiting_time[i] = time - arrival_time[i] - burst_time[i];
                    turnaround_time[i] = waiting_time[i] + burst_time[i];
                    total_wt += waiting_time[i];
                    total_tat += turnaround_time[i];
                    remaining_time[i] = 0;
                    remain--;
                } else if (arrival_time[i] <= time) {
                    remaining_time[i] -= quantum;
                    time += quantum;
                } else {
                    time++;
                }
            }
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
