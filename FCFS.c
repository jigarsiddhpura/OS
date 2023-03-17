#include <stdio.h>
#include <stdlib.h>

double mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / (double)n;
}

int main() {
    int arrTime[] = {0, 1, 2, 3, 4};
    int burstTime[] = {4, 3, 1, 2, 5};
    int n = sizeof(arrTime) / sizeof(arrTime[0]);
    int ganttC[n+1];
    ganttC[0] = 0;
    int dict[n][2];
    int compTime = burstTime[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        dict[i][0] = arrTime[i];
        dict[i][1] = burstTime[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (dict[i][0] > dict[j][0]) {
                int temp1 = dict[i][0];
                int temp2 = dict[i][1];
                dict[i][0] = dict[j][0];
                dict[i][1] = dict[j][1];
                dict[j][0] = temp1;
                dict[j][1] = temp2;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ganttC[i+1] = sum + dict[i][1];
        sum += dict[i][1];
    }

    int turnAroundTime[n];
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = ganttC[i+1] - arrTime[i];
    }

    int weightingTime[n];
    for (int i = 0; i < n; i++) {
        weightingTime[i] = turnAroundTime[i] - burstTime[i];
    }

    double avgWT = mean(weightingTime, n);
    double avgTAT = mean(turnAroundTime, n);

    printf("%f %f", avgTAT, avgWT);
    return 0;
}
