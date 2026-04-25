#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    char name[50];
    int duration;
    int deadline;
    int priority;
    int dependency;
    struct node*next;
    struct node*prev;
};

struct node* createNode(struct node Task) {
    struct node* newNode = malloc(sizeof(struct node));
    *newNode = Task;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void getinfo(struct node** tasks) {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct node temp;

        printf("Enter name of task %d: ", i + 1);
        scanf("%s", temp.name);

        printf("Enter duration of task %d (in hours): ", i + 1);
        scanf("%d", &temp.duration);

        printf("Enter deadline of task %d (in hours): ", i + 1);
        scanf("%d", &temp.deadline);

        printf("Enter priority of task %d (1-10): ", i + 1);
        scanf("%d", &temp.priority);

        printf("Enter dependency of task %d (index or -1): ", i + 1);
        scanf("%d", &temp.dependency);

        struct node* newNode = createNode(temp);

        if (*tasks == NULL) {
            *tasks = newNode;
        } else {
            struct node* current = *tasks;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }
}
