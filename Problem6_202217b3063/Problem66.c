#include <stdio.h>

int main() {
    int n;
    float burst_time[20], arrival_time[20], waiting_time[20], turnaround_time[20];
    float total_waiting_time = 0, total_turnaround_time = 0;
    
    printf("enter the number of process ");
    scanf("%d", &n);
    
    printf("enter the burst times ");
    for(int i = 0; i < n; i++) {
        scanf("%f", &burst_time[i]);
    }
    
    printf("enter the arrival times ");
    for(int i = 0; i < n; i++) {
        scanf("%f", &arrival_time[i]);
    }
    
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];
    
    for(int i = 1; i < n; i++) {
        waiting_time[i] = turnaround_time[i-1] - arrival_time[i];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
    
    printf("\nprocess\twaiting time\tturn around time\n");
    for(int i = 0; i < n; i++) {
        printf("p%d\t%.1f\t\t%.1f\n", i, waiting_time[i], turnaround_time[i]);
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    
    printf("the average waiting time is %.6f\n", total_waiting_time / n);
    printf("the average turn around time is %.6f\n", total_turnaround_time / n);
    
    return 0;
}
