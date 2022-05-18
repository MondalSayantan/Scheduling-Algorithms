#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

void main() {
    int n, wt[20], bt[20], tat[20], avwt = 0, avtat = 0, p[20], i, j, pos, temp;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("\nEnter burst time");
    for(i = 0; i<n; i++) {
        printf("\nP[%d]: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    for(i = 0; i<n; i++) {
        pos = i;
        for(j = i+1; j<n; j++) {
            if(bt[j] < bt[pos]) {
                pos = j;
            }
        }

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