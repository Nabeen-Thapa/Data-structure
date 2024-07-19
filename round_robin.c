#include<stdio.h>

typedef struct {
    int pid;
    int burst;
} process;

void totalturnaroundtime(process p[], int n, int waiting[], int turnaround[]) {
    int i;
    for (i = 0; i < n; i++)
        turnaround[i] = waiting[i] + p[i].burst;
}

void waitingTime(process p[], int n, int waiting[], int quantum) {
    int i, rem_bt[n];
    for (i = 0; i < n; i++)
        rem_bt[i] = p[i].burst;
    int t = 0;
    int flag;
    while (1) {
        flag = 1;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                flag = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t = t + rem_bt[i];
                    waiting[i] = t - p[i].burst;
                    rem_bt[i] = 0;
                }
            }
        }
        if (flag == 1)
            break;
    }
}

void calculataTime(process p[], int n, int quantum) {
    int i, waiting[n], turnaround[n], totalwaiting = 0, totalturnaround = 0;
    waitingTime(p, n, waiting, quantum);
    totalturnaroundtime(p, n, waiting, turnaround);
    printf("process \t burst time \t waiting time \t turnaround time\n");
    for (i = 0; i < n; i++) {
        totalwaiting += waiting[i];
        totalturnaround += turnaround[i];
        printf("%d\t\t %d\t\t %d\t\t %d\n", p[i].pid, p[i].burst, waiting[i], turnaround[i]);

    }
    double averagewaiting = (double) totalwaiting / n;
    double averageturnaround = (double) totalturnaround / n;
    printf("\n average waiting time : %f", averagewaiting);
    printf("\n average turnaround time : %f", averageturnaround);
}

int main() {
    int i, n, quantum;
    printf("Nabin Thapa\n\n");
    printf("enter the number of process: ");
    scanf("%d", &n);
    process p[n];
    printf("enter the burst time:");
    for (i = 0; i < n; i++) {
        printf("\nprocess %d: \n", i + 1);
        p[i].pid = i + 1;
        printf("burst time:");
        scanf("%d", &p[i].burst);
    }
    printf("enter quantum size:");
    scanf("%d", &quantum);
    calculataTime(p, n, quantum);

    return 0;
}

