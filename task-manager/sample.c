#include <stdio.h>
#include <stdlib.h>   // for rand()
#include <time.h>     // for random IDs
#include <string.h>   // for strcpy

#define MAX_SIZE 10

char stack[MAX_SIZE][100];
int taskIDs[MAX_SIZE];
int top = -1;   // -1 means stack is empty

// -----------------------------------------------------------------------
// HELPER FUNCTIONS (already done for you — read and understand these!)
// -----------------------------------------------------------------------

void printLine() {
    printf("----------------------------------------\n");
}

int isFull() {
    return top == MAX_SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

int generateID() {
    return rand() % 1000;
}

// -----------------------------------------------------------------------
// TODO 1: addTask()
// Hint: scan user input for the task, assign a random ID,
//       and push the data onto both the stack and taskIDs arrays.
// Note: top starts at -1, so increment it before storing data.
// -----------------------------------------------------------------------
void addTask() {
    // Write your code here

}

// -----------------------------------------------------------------------
// TODO 2: removeTask()
// Hint: save the top task's ID and description in a variable,
//       then pop it off the stack and print what was removed (we store data in variable so that it can be used while displaying).
// -----------------------------------------------------------------------
void removeTask() {
    // Write your code here

}

// -----------------------------------------------------------------------
// TODO 3: displayTasks()
// Hint: loop from top down to 0 and print
//       each task's ID and description.
// -----------------------------------------------------------------------
void displayTasks() {
    // Write your code here

}

// -----------------------------------------------------------------------
// MENU & MAIN — Already done for you, do not modify
// -----------------------------------------------------------------------

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

int main() {
    srand(time(NULL));

    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            addTask();
        } else if (choice == 2) {
            removeTask();
        } else if (choice == 3) {
            displayTasks();
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}

// -----------------------------------------------------------------------
// DETAILED HINTS — Only read these if you are stuck!
// -----------------------------------------------------------------------
//
// addTask():
//   Step 1: Check if the stack is full using isFull()
//           If it is full, print a message and return
//   Step 2: Increment top (top++) so it points to the next empty slot
//   Step 3: Ask the user to type a task description
//           Use: printf("Enter task description: ");
//           Then read input with: scanf(" %[^\n]", stack[top]);
//           (The " %[^\n]" reads everything until the user presses Enter)
//   Step 4: Assign a random ID using generateID() and store in taskIDs[top]
//   Step 5: Print a confirmation message showing the task ID
//
// removeTask():
//   Step 1: Check if the stack is empty using isEmpty()
//           If it is empty, print a message and return
//   Step 2: Save the top task before removing it:
//           int id = taskIDs[top];
//           char task[100];
//           strcpy(task, stack[top]);
//   Step 3: Decrement top (top--) to pop the task off the stack
//   Step 4: Print the removed task's ID and description
//
// displayTasks():
//   Step 1: Check if the stack is empty using isEmpty()
//           If it is, print "Stack is empty." and return
//   Step 2: Print a header using printLine() and a title
//   Step 3: Loop from top down to 0: for (int i = top; i >= 0; i--)
//   Step 4: Inside the loop print each task:
//           printf("ID: %3d | Task: %s\n", taskIDs[i], stack[i]);
//   Step 5: Close with printLine()
