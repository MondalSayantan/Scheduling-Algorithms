#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

void main() {
    int n, bt[20], wt[20], tat[20], p[20], avwt = 0, avtat = 0, pr[20], pos, i, j, temp;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("\nEnter burst time and Priority");
    for(i = 0; i<n; i++) {
        printf("\n%d. Enter burst time: ", i+1);
        scanf("%d", &bt[i]);
        printf("\n%d. Enter Priority: ", i+1);
        scanf("%d", &pr[i]);
        p[i] = p[i+1];   // Enter Process Number
    }

    // Sorting burst time, priority and process number in ascending order
    for(i = 0; i<n; i++) {
        pos = i;
        for(j = i+1; j<n; j++) {
            if(pr[j] < pr[pos]) {
                pos = j;
            }
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
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
        tat[i] = bt[i] + wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d] \t\t%d \t\t%d  \t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avwt/=n;
    avtat/=n;

    printf("\nAverage Waiting Time: %d", avwt);
    printf("\nAverage Turn Around Time: %d", avtat);
}