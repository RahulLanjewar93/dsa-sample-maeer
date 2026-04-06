// Notification Queue — Array-based queue implementation
// Notifications are added at the rear and processed from the front (FIFO).

#include <stdio.h>
#include <string.h>

// -----------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------

#define MAX_MSG 100  // Maximum number of notifications the queue can hold
#define MAX_LEN 100  // Maximum length of each notification text

// -----------------------------------------------------------------------
// Global state
// -----------------------------------------------------------------------

char queue[MAX_MSG][MAX_LEN];     // Notification messages
int  front = 0, rear = -1;        // front = oldest item, rear = newest item
int  size  = 0;                   // Number of notifications currently in the queue

// -----------------------------------------------------------------------
// Queue helpers
// -----------------------------------------------------------------------

int isEmpty() { 
    return size == 0; 
}
int isFull()  { 
    return size == MAX_MSG; 
}

// -----------------------------------------------------------------------
// Core operations
// -----------------------------------------------------------------------

// Add a new notification to the rear of the queue
void enqueue(const char* msg) {
    if (isFull()) {
        printf("Notification queue full. Dropping notification.\n");
        return;
    }

    // Advance rear to the next empty slot and store the message
    rear++;
    strcpy(queue[rear], msg);
    size++;

    printf("Notification added: %s\n", msg);
}

// Process (remove and send) the oldest notification at the front
void processNext() {
    if (isEmpty()) {
        printf("No notifications to process.\n");
        return;
    }

    // Save the front message before shifting the array
    char msg[MAX_LEN];
    strcpy(msg, queue[front]);

    // Shift all remaining messages one step forward so front stays at index 0
    for (int i = front; i < rear; i++)
        strcpy(queue[i], queue[i + 1]);

    rear--;
    size--;

    printf("Sending notification: %s\n", msg);
}

// -----------------------------------------------------------------------
// Entry point
// -----------------------------------------------------------------------

int main() {
    int  choice;
    char msg[MAX_LEN];

    printf("Simple Notification Queue Service (REPL)\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add notification\n");
        printf("2. Process next notification\n");
        printf("3. Exit\n");
        printf("Choose (1-3): ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter notification text: ");
                scanf(" %[^\n]", msg);
                enqueue(msg);
                break;
            case 2:
                processNext();
                break;
            case 3:
                printf("Bye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
