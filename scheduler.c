#include <stdio.h>
#include "scheduler.h"

void scheduleTasks() {

    int currentTime = 0;

    printf("\n=== SCHEDULE ===\n");

    for(int i = top; i >= 0; i--) {

        int idx = stack[i];

        int start = currentTime;
        int end = start + tasks[idx].duration;

        printf("%s : %d -> %d",
            tasks[idx].name,
            start,
            end);

        if(end > tasks[idx].deadline) {
            printf(" [MISSED DEADLINE]");
        }

        printf("\n");

        currentTime = end;
    }
}

void saveSchedule() {

    FILE *fp = fopen("schedule.txt", "w");

    if(fp == NULL) {
        printf("Cannot create schedule.txt\n");
        return;
    }

    int currentTime = 0;

    for(int i = top; i >= 0; i--) {

        int idx = stack[i];

        int start = currentTime;
        int end = start + tasks[idx].duration;

        fprintf(fp,
            "%s : %d -> %d",
            tasks[idx].name,
            start,
            end);

        if(end > tasks[idx].deadline) {
            fprintf(fp, " [MISSED DEADLINE]");
        }

        fprintf(fp, "\n");

        currentTime = end;
    }

    fclose(fp);
}
