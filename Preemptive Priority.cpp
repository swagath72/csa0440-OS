#include <stdio.h>

int main() {
    int n, i, time = 0, count = 0, highest;
    int arrival_time[10], burst_time[10], remaining_time[10], priority[10], waiting_time[10], turnaround_time[10];
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time, Burst Time, and Priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("P%d Priority: ", i + 1);
        scanf("%d", &priority[i]);
        remaining_time[i] = burst_time[i];
    }

    priority[9] = 9999;
    
    for (time = 0; count != n; time++) {
        highest = 9;
        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= time && priority[i] < priority[highest] && remaining_time[i] > 0) {
                highest = i;
            }
        }
        
        remaining_time[highest]--;
        
        if (remaining_time[highest] == 0) {
            count++;
            waiting_time[highest] = time + 1 - arrival_time[highest] - burst_time[highest];
            turnaround_time[highest] = waiting_time[highest] + burst_time[highest];
            
            total_wt += waiting_time[highest];
            total_tat += turnaround_time[highest];
        }
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("\nP\tAT\tBT\tPri\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
