#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_DESC  100

char tasks[MAX_TASKS][MAX_DESC];
int  taskIDs[MAX_TASKS];
int  top   = -1;
int  nextID = 1;

int  isFull()   { return top == MAX_TASKS - 1; }
int  isEmpty()  { return top == -1; }

void printDivider() {
    printf("----------------------------------------\n");
}

void addTask() {
    if (isFull()) {
        printf("Stack is full. Cannot add more tasks.\n");
        return;
    }
    top++;
    printf("Enter task description: ");
    scanf(" %[^\n]", tasks[top]);
    taskIDs[top] = nextID++;
    printf("Task added (ID: %d)\n", taskIDs[top]);
}

void removeTask() {
    if (isEmpty()) {
        printf("Stack is empty. Nothing to remove.\n");
        return;
    }
    printf("Removed (ID: %d): %s\n", taskIDs[top], tasks[top]);
    top--;
}

void displayTasks() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printDivider();
    printf("           TASK STACK (TOP TO BOTTOM)\n");
    printDivider();
    for (int i = top; i >= 0; i--)
        printf("ID: %3d | %s\n", taskIDs[i], tasks[i]);
    printDivider();
}

void printMenu() {
    printf("\n");
    printDivider();
    printf("           STACK TASK MANAGER\n");
    printDivider();
    printf("1. Add task\n");
    printf("2. Remove task\n");
    printf("3. Display all tasks\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

int main() {
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask();      break;
            case 2: removeTask();   break;
            case 3: displayTasks(); break;
            case 4: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice. Enter 1-4.\n");
        }
    }
}
