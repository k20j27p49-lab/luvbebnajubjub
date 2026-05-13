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

extern Task tasks[MAX];
extern int taskCount;

extern int graph[MAX][MAX];

extern int visited[MAX];
extern int recStack[MAX];

extern int stack[MAX];
extern int top;

void addTaskFile();
void loadTasks();
void displayTasks();


void createGraph();
int detectCycleDFS(int node);
int detectCycle();

void dfs(int node);
void topologicalSort();

void sortByPriority();
void printTopo();

void scheduleTasks();
void saveSchedule();

#endif
