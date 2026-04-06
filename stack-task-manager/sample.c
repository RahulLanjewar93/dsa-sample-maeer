// Task Manager — Stack-based implementation (starter file)
// Complete the three TODO functions below to make the program work.

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
// Stack helpers — already done for you, read and understand these!
// -----------------------------------------------------------------------

int isFull()  { 
    return top == MAX_TASKS - 1; 
}

int isEmpty() { 
    return top == -1; 
}

void printDivider() {
    printf("----------------------------------------\n");
}

// -----------------------------------------------------------------------
// TODO 1: addTask()
// Hint: scan user input for the task, assign the next ID,
//       and push the data onto both the tasks and taskIDs arrays.
// Note: top starts at -1, so increment it before storing data.
// -----------------------------------------------------------------------
void addTask() {
    // Write your code here
}

// -----------------------------------------------------------------------
// TODO 2: removeTask()
// Hint: save the top task's ID and description into variables first,
//       then pop it off the stack and print what was removed.
//       (Save before popping so the data is still available to print.)
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
// Menu and entry point — do not modify
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

// -----------------------------------------------------------------------
// DETAILED HINTS — Only read these if you are stuck!
// -----------------------------------------------------------------------
//
// addTask():
//   Step 1: Check if the stack is full using isFull()
//           If it is full, print a message and return
//   Step 2: Increment top (top++) so it points to the next empty slot
//   Step 3: Ask the user to type a task description:
//           printf("Enter task description: ");
//           scanf(" %[^\n]", tasks[top]);
//           (The " %[^\n]" reads everything until the user presses Enter)
//   Step 4: Assign the next ID and store it:
//           taskIDs[top] = nextID++;
//   Step 5: Print a confirmation message showing the task ID
//
// removeTask():
//   Step 1: Check if the stack is empty using isEmpty()
//           If it is empty, print a message and return
//   Step 2: Save the top task before removing it:
//           int id = taskIDs[top];
//           char task[MAX_DESC];
//           strcpy(task, tasks[top]);
//   Step 3: Decrement top (top--) to pop the task off the stack
//   Step 4: Print the removed task's ID and description
//
// displayTasks():
//   Step 1: Check if the stack is empty using isEmpty()
//           If it is, print "Stack is empty." and return
//   Step 2: Print a header using printDivider() and a title
//   Step 3: Loop from top down to 0:
//           for (int i = top; i >= 0; i--)
//   Step 4: Inside the loop, print each task:
//           printf("ID: %3d | %s\n", taskIDs[i], tasks[i]);
//   Step 5: Close with printDivider()
