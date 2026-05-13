#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX 100

typedef struct {
    char name[50];
    int duration;
    int deadline;
    int priority;
    int dependency;
} Task;

/* GLOBAL VARIABLES */

extern Task tasks[MAX];
extern int taskCount;

extern int graph[MAX][MAX];

extern int visited[MAX];
extern int recStack[MAX];

extern int stack[MAX];
extern int top;

/* TASK MANAGER */

void addTaskFile();
void loadTasks();
void displayTasks();

/* GRAPH */

void createGraph();

int detectCycleDFS(int node);
int detectCycle();

void dfs(int node);
void topologicalSort();

void sortByPriority();

void printTopo();

/* SCHEDULER */

void scheduleTasks();
void saveSchedule();

#endif
