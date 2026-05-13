#include <stdio.h>
#include "scheduler.h"

int graph[MAX][MAX];

int visited[MAX];
int recStack[MAX];

int stack[MAX];
int top = -1;

void createGraph() {

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < taskCount; i++) {

        int dep = tasks[i].dependency;

        if(dep != -1) {
            graph[dep][i] = 1;
        }
    }
}

int detectCycleDFS(int node) {

    visited[node] = 1;
    recStack[node] = 1;

    for(int i = 0; i < taskCount; i++) {

        if(graph[node][i]) {

            if(!visited[i] && detectCycleDFS(i)) {
                return 1;
            }

            else if(recStack[i]) {
                return 1;
            }
        }
    }

    recStack[node] = 0;

    return 0;
}

int detectCycle() {

    for(int i = 0; i < taskCount; i++) {

        visited[i] = 0;
        recStack[i] = 0;
    }

    for(int i = 0; i < taskCount; i++) {

        if(!visited[i]) {

            if(detectCycleDFS(i)) {
                return 1;
            }
        }
    }

    return 0;
}

void dfs(int node) {

    visited[node] = 1;

    for(int i = 0; i < taskCount; i++) {

        if(graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = node;
}

void topologicalSort() {

    for(int i = 0; i < taskCount; i++) {
        visited[i] = 0;
    }

    top = -1;

    for(int i = 0; i < taskCount; i++) {

        if(!visited[i]) {
            dfs(i);
        }
    }
}

void sortByPriority() {

    for(int i = top; i > 0; i--) {

        for(int j = 0; j < i; j++) {

            int a = stack[j];
            int b = stack[j + 1];

            if(tasks[a].priority > tasks[b].priority) {

                int temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }
}

void printTopo() {

    printf("\n=== ORDER ===\n");

    for(int i = top; i >= 0; i--) {
        printf("%s ", tasks[stack[i]].name);
    }

    printf("\n");
}
