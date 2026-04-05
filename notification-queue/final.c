#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of notifications the queue can hold
#define MAX_MSG 100

// Maximum length of each notification text
#define MAX_LEN 100

// Array to store all notifications (like a line of messages)
char queue[MAX_MSG][MAX_LEN];

// front = index of the first (oldest) notification
// rear  = index of the last (newest) notification
// size  = how many notifications are in the queue right now
int front = 0, rear = -1, size = 0;

// Function: check if the queue is empty
int isEmpty() {
    // If size is 0, there are no notifications
    return size == 0;
}

// Function: check if the queue is full
int isFull() {
    // If size equals MAX_MSG, the queue is full
    return size == MAX_MSG;
}

// Function: add a new notification to the queue (enqueue)
// This is like adding a person to the end of the line
void enqueue(const char* msg) {
    // First check if there is space in the queue
    if (isFull()) {
        printf("Notification queue full. Dropping notification.\n");
        return;
    }

    // Move rear to the next position (end of the line)
    rear++;

    // Put the message into the queue at the rear position
    strcpy(queue[rear], msg);
    size++;   // one more notification in the queue

    printf("Notification added: %s\n", msg);
}

// Function: process the next notification (oldest one)
// This is like serving the person at the front of the line
void processNext() {
    // If there are no notifications, we cannot process anything
    if (isEmpty()) {
        printf("No notifications to process.\n");
        return;
    }

    // Read the message at the front (the oldest one)
    char msg[MAX_LEN];
    strcpy(msg, queue[front]);

    // Move all remaining messages one step forward in the array
    // (like everybody in the line moves one step forward)
    for (int i = front; i < rear; i++) {
        strcpy(queue[i], queue[i + 1]);
    }

    // Move the rear backward (one fewer item at the end)
    rear--;
    size--;   // now the queue has one less notification

    // In real life, here you would:
    // - call an SMS/email/push API
    // For students, we just print it
    printf("🔔 Sending notification: %s\n", msg);
}

// Main function: REPL‑style menu loop
int main() {
    // Variable to store the user's choice (1, 2, or 3)
    int choice;

    // Variable to store the notification text (message)
    char msg[MAX_LEN];

    // Title to show the user
    printf("Simple Notification Queue Service (REPL)\n");

    // Infinite loop: keep showing the menu until user chooses Exit
    while (1) {
        // Print the menu options
        printf("\nMenu:\n");
        printf("1. Add notification\n");
        printf("2. Process next notification\n");
        printf("3. Exit\n");
        printf("Choose (1-3): ");

        // Read the user's choice
        scanf("%d", &choice);

        // If user chooses 1: add a new notification
        if (choice == 1) {
            printf("Enter notification text: ");
            scanf(" %[^\n]", msg);   // read the whole line (including spaces)
            enqueue(msg);             // add to the queue
        }

        // If user chooses 2: send the next notification (oldest)
        else if (choice == 2) {
            processNext();
        }

        // If user chooses 3: exit the program
        else if (choice == 3) {
            printf("Bye!\n");
            break;   // exit the loop and end the program
        }

        // If user enters something else (not 1, 2, or 3)
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}