#include <stdio.h>

int main() {
    int n, i, smallest, time, count = 0;
    int arrival_time[10], burst_time[10], remaining_time[10], waiting_time[10], turnaround_time[10];
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    remaining_time[9] = 9999;

    for (time = 0; count != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= time && remaining_time[i] < remaining_time[smallest] && remaining_time[i] > 0) {
                smallest = i;
            }
        }
        
        remaining_time[smallest]--;
        
        if (remaining_time[smallest] == 0) {
            count++;
            waiting_time[smallest] = time + 1 - arrival_time[smallest] - burst_time[smallest];
            turnaround_time[smallest] = waiting_time[smallest] + burst_time[smallest];
            
            total_wt += waiting_time[smallest];
            total_tat += turnaround_time[smallest];
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

