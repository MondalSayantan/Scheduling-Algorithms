#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

void main() {
    int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("\nEnter Process Burst Time");
    for(i = 0; i<n; i++) {
        printf("\nP[%d]: ", i+1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for(i = 1; i<n; i++) {
        wt[i] = 0;
        for(j = 0; j<i; j++) {
            wt[i]+=bt[j];
        }
    }
    printf("\nProcess \tBurst Time \tWait Time \tTurn Around Time");
    for(i = 0; i<n; i++) {
        tat[i] = wt[i] + bt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d] \t\t%d \t\t%d  \t\t%d", i+1, bt[i], wt[i], tat[i]);
    }

    avwt/=i;
    avtat/=i;
    printf("\nAverage Waiting Time: %d", avwt);
    printf("\nAverage Turn Around Time: %d", avtat);
}