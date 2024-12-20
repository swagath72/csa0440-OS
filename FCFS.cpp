#include <stdio.h>

int main() {
    int n, i;
    int arrival_time[20], burst_time[20], waiting_time[20], turnaround_time[20];
    int start_time[20], total_wt = 0, total_tat = 0;
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

    for (i = 0; i < n; i++) {
        if (i == 0) {
            start_time[i] = arrival_time[i];
        } else {

            start_time[i] = (start_time[i - 1] + burst_time[i - 1] > arrival_time[i]) ? 
                            (start_time[i - 1] + burst_time[i - 1]) : arrival_time[i];
        }
        
        waiting_time[i] = start_time[i] - arrival_time[i];
        turnaround_time[i] = waiting_time[i] + burst_time[i];

        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
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
