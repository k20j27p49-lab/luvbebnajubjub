#include <stdio.h>
#include "scheduler.h"

Task tasks[MAX];
int taskCount = 0;

void addTaskFile() {

    FILE *fp = fopen("tasks.txt", "a");

    if(fp == NULL) {
        printf("Cannot open tasks.txt\n");
        return;
    }

    Task t;

    printf("Task Name: ");
    scanf("%s", t.name);

    printf("Duration: ");
    scanf("%d ", &t.duration);

    printf("Deadline: ");
    scanf("%d hour(s)", &t.deadline);

    printf("Priority(Important level): ");
    scanf("%d", &t.priority);

    printf("Dependency (-1 if none): ");
    scanf("%d", &t.dependency);

    fprintf(fp,
        "%s %d %d %d %d\n",
        t.name,
        t.duration,
        t.deadline,
        t.priority,
        t.dependency);

    fclose(fp);

    printf("Task added successfully!\n");
}

void loadTasks() {

    FILE *fp = fopen("tasks.txt", "r");

    if(fp == NULL) {
        printf("Cannot open tasks.txt\n");
        return;
    }

    taskCount = 0;

    while(fscanf(fp,
        "%s %d %d %d %d",
        tasks[taskCount].name,
        &tasks[taskCount].duration,
        &tasks[taskCount].deadline,
        &tasks[taskCount].priority,
        &tasks[taskCount].dependency) != EOF)
    {
        taskCount++;
    }

    fclose(fp);
}

void displayTasks() {

    printf("\n=== TASK LIST ===\n");

    for(int i = 0; i < taskCount; i++) {

        printf("%d. %s | Dur:%d | Deadline:%d | Priority:%d | Dep:%d\n",
            i,
            tasks[i].name,
            tasks[i].duration,
            tasks[i].deadline,
            tasks[i].priority,
            tasks[i].dependency);
    }
}
