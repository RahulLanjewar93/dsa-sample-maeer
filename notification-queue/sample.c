#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of notifications the queue can hold
#define MAX_MSG 100

// Maximum length of each notification text
#define MAX_LEN 100

// Array to store all notifications (like a line of people waiting)
char queue[MAX_MSG][MAX_LEN];

// front = index of the first (oldest) notification
// rear  = index of the last (newest) notification
// size  = how many notifications are currently in the queue
int front = 0, rear = -1, size = 0;

// -----------------------------------------------------------------------
// HELPER FUNCTIONS (already done for you — read and understand these!)
// -----------------------------------------------------------------------

// Returns 1 (true) if the queue has no notifications
int isEmpty() {
    return size == 0;
}

// Returns 1 (true) if the queue has reached its maximum capacity
int isFull() {
    return size == MAX_MSG;
}

// -----------------------------------------------------------------------
// TODO 1: enqueue()
// Hint: move rear forward,
//       copy the message into the queue at the rear position, and update size.
// Note: rear starts at -1, so increment it before storing the message.
// -----------------------------------------------------------------------
void enqueue(const char* msg) {
    // Write your code here

}

// -----------------------------------------------------------------------
// TODO 2: processNext()
// Hint: print the message at front,
//       shift all remaining messages one step forward, then update rear and size.
// Note: The front of the queue is always index 0 — the oldest message is served first.
// -----------------------------------------------------------------------
void processNext() {
    // Write your code here

}

// -----------------------------------------------------------------------
// MAIN — Already done for you, do not modify
// -----------------------------------------------------------------------

int main() {
    int choice;
    char msg[MAX_LEN];

    printf("Simple Notification Queue Service (REPL)\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add notification\n");
        printf("2. Process next notification\n");
        printf("3. Exit\n");
        printf("Choose (1-3): ");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter notification text: ");
            scanf(" %[^\n]", msg);
            enqueue(msg);
        } else if (choice == 2) {
            processNext();
        } else if (choice == 3) {
            printf("Bye!\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// -----------------------------------------------------------------------
// DETAILED HINTS — Only read these if you are stuck!
// -----------------------------------------------------------------------
//
// enqueue():
//   Step 1: Check if the queue is full using isFull()
//           If it is, print a message and return
//   Step 2: Increment rear (rear++) so it points to the next empty slot
//   Step 3: Copy the message into the queue at position rear:
//           strcpy(queue[rear], msg);
//   Step 4: Increment size (size++) to reflect one more item in the queue
//   Step 5: Print a confirmation message showing the added notification
//
// processNext():
//   Step 1: Check if the queue is empty using isEmpty()
//           If it is, print a message and return
//   Step 2: Save the message at the front before removing it:
//           char msg[MAX_LEN];
//           strcpy(msg, queue[front]);
//   Step 3: Shift all remaining messages one step forward so front stays at index 0:
//           for (int i = front; i < rear; i++)
//               strcpy(queue[i], queue[i + 1]);
//   Step 4: Decrement rear (rear--) and size (size--)
//   Step 5: Print the processed message
//           Example: printf("Sending notification: %s\n", msg);
