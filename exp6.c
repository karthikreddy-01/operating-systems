#include <stdio.h>
int main() {
    int n;
    int at[10], bt[10], pr[10];
    int rt[10], wt[10], tat[10], ct[10];
    int completed = 0, time = 0;
    int min_priority, index;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        rt[i] = bt[i];  // Remaining time
    }
    while (completed != n) {
        min_priority = 9999;
        index = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && pr[i] < min_priority) {
                min_priority = pr[i];
                index = i;
            }
        }
        if (index == -1) {
            time++;
        } else {
            rt[index]--;
            time++;
            if (rt[index] == 0) {
                completed++;
                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
            }
        }
    }
    printf("\nProcess\tAT\tBT\tPR\tWT\tTAT");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);
    }
    return 0;
}
