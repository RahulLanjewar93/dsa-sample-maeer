#include <stdio.h>
#include <stdlib.h>   // for rand()
#include <time.h>     // for random IDs
#include <string.h>   // for strcpy

// Define a fixed maximum size using #define (compile‑time constant)
#define MAX_SIZE 10

// Global array to store task descriptions (our stack)
char stack[MAX_SIZE][100];   // 10 tasks, each up to 100 characters

// Global array to store the random ID for each task
int taskIDs[MAX_SIZE];

// Global variable to track the top of the stack
int top = -1;   // -1 means stack is empty

// Helper: print a horizontal line (for UI)
void printLine() {
    printf("----------------------------------------\n");
}

// Function: check if stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function: check if stack is empty
int isEmpty() {
    return top == -1;
}

// Function: generate a random ID for a task
int generateID() {
    // rand() % 1000 gives a number from 0 to 999
    return rand() % 1000;
}

// Function: add a task to the top of the stack (push)
void addTask() {
    if (isFull()) {
        printf("Cannot add more tasks. Stack is full!\n");
        return;
    }

    // Move top to the next position
    top++;

    // Ask user to type the task description
    printf("Enter task description: ");
    // Read all characters except newline (\n). 
    scanf(" %[^\n]", stack[top]);

    // Give this task a random ID
    taskIDs[top] = generateID();

    printf("Task added to stack (ID: %d).\n", taskIDs[top]);
}

// Function: remove the top task (pop)
void removeTask() {
    if (isEmpty()) {
        printf("Stack is empty. No task to remove.\n");
        return;
    }

    // Read the top task's ID and description
    int id = taskIDs[top];
    char task[100];
    strcpy(task, stack[top]);   // copy the string

    // Actually remove it by moving top down
    top--;

    printf("Task removed (ID: %d): %s\n", id, task);
}

// Function: display all tasks in a “pretty” stack view (top to bottom)
void displayTasks() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    printLine();
    printf("           TASK STACK (TOP TO BOTTOM)\n");
    printLine();

    // We go from top down to bottom (top is last added, at the top)
    int i;
    for (i = top; i >= 0; i--) {
        printf("ID: %3d | Task: %s\n", taskIDs[i], stack[i]);
    }

    printLine();
}

// Function: show the menu (REPL style)
void printMenu() {
    printf("\n");
    printLine();
    printf("           STACK TASK MANAGER\n");
    printLine();
    printf("1. Add task (push)\n");
    printf("2. Remove task (pop)\n");
    printf("3. Display all tasks (pretty stack view)\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

// Main function (REPL loop)
int main() {
    // Seed the random number generator
    srand(time(NULL));

    int choice;

    // Main loop: show menu and handle user choice
    while (1) {
        printMenu();

        // Read the user's choice
        scanf("%d", &choice);

        if (choice == 1) {
            addTask();          // push a task onto the stack
        } else if (choice == 2) {
            removeTask();       // pop the top task
        } else if (choice == 3) {
            displayTasks();     // show stack in pretty order
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}