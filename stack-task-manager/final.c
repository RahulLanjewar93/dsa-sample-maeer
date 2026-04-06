// Task Manager — Stack-based implementation
// Each new task is pushed onto the top; removal always takes the most recent task (LIFO).

#include <stdio.h>
#include <string.h>

// -----------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------

#define MAX_TASKS 10   // Maximum number of tasks the stack can hold
#define MAX_DESC  100  // Maximum length of a task description

// -----------------------------------------------------------------------
// Global state
// -----------------------------------------------------------------------

char tasks[MAX_TASKS][MAX_DESC];  // Task descriptions
int  taskIDs[MAX_TASKS];          // Corresponding task IDs
int  top    = -1;                 // Index of the top of the stack (-1 = empty)
int  nextID = 1;                  // Auto-incrementing ID counter

// -----------------------------------------------------------------------
// Stack helpers
// -----------------------------------------------------------------------

int isFull()  { return top == MAX_TASKS - 1; }
int isEmpty() { return top == -1; }

void printDivider() {
    printf("----------------------------------------\n");
}

// -----------------------------------------------------------------------
// Core operations
// -----------------------------------------------------------------------

// Push a new task onto the stack
void addTask() {
    if (isFull()) {
        printf("Stack is full. Cannot add more tasks.\n");
        return;
    }

    top++;
    printf("Enter task description: ");
    scanf(" %[^\n]", tasks[top]);

    // Assign the next available ID
    taskIDs[top] = nextID++;

    printf("Task added (ID: %d)\n", taskIDs[top]);
}

// Pop the most recent task off the stack
void removeTask() {
    if (isEmpty()) {
        printf("Stack is empty. Nothing to remove.\n");
        return;
    }

    printf("Removed (ID: %d): %s\n", taskIDs[top], tasks[top]);
    top--;
}

// Print all tasks from top (newest) to bottom (oldest)
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

// -----------------------------------------------------------------------
// Menu
// -----------------------------------------------------------------------

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

// -----------------------------------------------------------------------
// Entry point
// -----------------------------------------------------------------------

int main() {
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Enter 1-4.\n");
        }
    }
}
