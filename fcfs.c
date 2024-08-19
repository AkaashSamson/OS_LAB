#include <stdio.h>

void fcfs(int processes[], int n, int burst_time[], int arrival_time[]) {
    int completion_time[n], waiting_time[n], turnaround_time[n],i;
   
    // Calculate completion time for each process
    completion_time[0] = burst_time[0];
    for (i = 1; i < n; i++) {
        completion_time[i] = completion_time[i-1] + burst_time[i];
    }
   
    // Calculate turnaround time and waiting time for each process
    for (i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }
   
    // Displaying the Gantt chart and process details
    printf("Gantt Chart:\n");
    printf("|");
    for (i = 0; i < n; i++) {
        printf(" P%d |", processes[i]);
    }
    printf("\n");
    printf("0");
    for (i = 0; i < n; i++) {
        printf("\t%d", completion_time[i]);
    }
    printf("\n\n");
   
    printf("Process \tBurstTime\tArrivalTime\tCompletionTime \tWaiting Time\tTurnaroundTime\n");
    for (i = 0; i < n; i++) {
        printf("P%d   \t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i], burst_time[i], arrival_time[i], completion_time[i], waiting_time[i], turnaround_time[i]);
    }
   
    // Calculating average waiting time and average turnaround time
    int total_waiting_time = 0, total_turnaround_time = 0;
    for (i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
   
    float average_waiting_time = (float) total_waiting_time / n;
    float average_turnaround_time = (float) total_turnaround_time / n;
   
    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

int main() {
    int n, choice,i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
   
    int processes[n];
    int burst_time[n];
    int arrival_time[n];
   
    // Asking user whether arrival times are provided or not
    printf("Are arrival times provided? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
   
    // Inputting burst times and arrival times accordingly
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        if (choice == 1) {
            printf("Enter arrival time for process P%d: ", i + 1);
            scanf("%d", &arrival_time[i]);
        } else {
            arrival_time[i] = 0; // Default arrival time is 0
        }
        processes[i] = i + 1;
    }
   
    // Calling FCFS function with input data
    fcfs(processes, n, burst_time, arrival_time);
   
    return 0;
}
