#include <stdio.h>
#include "scheduler.h"

int main() {

    int choice;

    while(1) {

        printf("\n===== SMART SCHEDULER =====\n");

        printf("1. Add Task\n");
        printf("2. Generate Schedule\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");

        printf("Choose: ");
        scanf("%d", &choice);

        if(choice == 1) {

            addTaskFile();
        }

        else if(choice == 2) {

            loadTasks();

            createGraph();

            if(detectCycle()) {

                printf("\nCycle Detected!\n");
                printf("Invalid dependency graph.\n");

                continue;
            }

            topologicalSort();

            sortByPriority();

            printTopo();

            scheduleTasks();

            saveSchedule();

            printf("\nSchedule saved to schedule.txt\n");
        }

        else if(choice == 3) {

            loadTasks();

            displayTasks();
        }

        else if(choice == 4) {

            printf("Program Ended.\n");
            break;
        }

        else {

            printf("Invalid Choice\n");
        }
    }

    return 0;
}
