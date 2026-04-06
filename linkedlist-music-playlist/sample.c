// Music Playlist — Singly linked list implementation (starter file)
// Complete the three TODO functions below to make the program work.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------

#define MAX_NAME   100  // Maximum length of a song name
#define MAX_ARTIST 100  // Maximum length of an artist name
#define MAX_GENRE   50  // Maximum length of a genre

// -----------------------------------------------------------------------
// Node structure
// -----------------------------------------------------------------------

// Each node represents one song in the playlist
struct Node {
    char         name[MAX_NAME];     // Song title
    char         artist[MAX_ARTIST]; // Artist name
    char         genre[MAX_GENRE];   // Genre (e.g. Pop, Rock, Jazz)
    struct Node* next;               // Pointer to the next song
};

// -----------------------------------------------------------------------
// Global state
// -----------------------------------------------------------------------

struct Node* head = NULL;  // Pointer to the first song (NULL means playlist is empty)

// -----------------------------------------------------------------------
// Helper — already done for you, read and understand this!
// -----------------------------------------------------------------------

// Allocates and returns a new song node with the given details
struct Node* createNode(const char* name, const char* artist, const char* genre) {
    // Allocate memory for one Node on the heap
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Copy the song details into the node
    // (we copy because the original strings may be local variables that disappear)
    strcpy(newNode->name,   name);
    strcpy(newNode->artist, artist);
    strcpy(newNode->genre,  genre);

    // The new node has no next song yet
    newNode->next = NULL;

    return newNode;
}

// -----------------------------------------------------------------------
// TODO 1: addSong()
// Hint: read name, artist, and genre from the user, create a new node,
//       point it to the current head, then update head to the new node.
// -----------------------------------------------------------------------

void addSong() {
    // Write your code here

}

// -----------------------------------------------------------------------
// TODO 2: removeSong()
// Hint: read the song name from the user, then handle two cases —
//       (a) the song to remove is at the front (head),
//       (b) the song is somewhere further in the list.
//       Use strcmp() to compare song names. free() the removed node.
// -----------------------------------------------------------------------

void removeSong() {
    // Write your code here

}

// -----------------------------------------------------------------------
// TODO 3: displayPlaylist()
// Hint: start at head and walk forward using current = current->next
//       until you reach NULL. Print each song's details along the way.
// -----------------------------------------------------------------------

void displayPlaylist() {
    // Write your code here

}

// -----------------------------------------------------------------------
// Menu and entry point — do not modify
// -----------------------------------------------------------------------

void printMenu() {
    printf("\n----------------------------------------\n");
    printf("           MUSIC PLAYLIST\n");
    printf("----------------------------------------\n");
    printf("1. Add song\n");
    printf("2. Remove song\n");
    printf("3. Display playlist\n");
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
                addSong();
                break;
            case 2:
                removeSong();
                break;
            case 3:
                displayPlaylist();
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
// addSong():
//   Step 1: Declare local variables and read input from the user:
//           char name[MAX_NAME], artist[MAX_ARTIST], genre[MAX_GENRE];
//           printf("Song name: "); scanf(" %[^\n]", name);
//           printf("Artist:    "); scanf(" %[^\n]", artist);
//           printf("Genre:     "); scanf(" %[^\n]", genre);
//   Step 2: Call createNode(name, artist, genre) to allocate a new node
//   Step 3: Set newNode->next = head
//           (the new node should point to whatever was the first song)
//   Step 4: Set head = newNode
//           (the new node is now the first song in the playlist)
//   Step 5: Print a confirmation message
//
// removeSong():
//   Step 1: Read the song name to remove from the user
//   Step 2: Check if head == NULL; if so, print "Playlist is empty." and return
//   Step 3: Check if the front song matches (strcmp(head->name, name) == 0):
//             struct Node* temp = head;
//             head = head->next;
//             free(temp);
//             print confirmation and return
//   Step 4: Otherwise, walk the list to find the node BEFORE the target:
//             struct Node* current = head;
//             while (current->next != NULL && strcmp(current->next->name, name) != 0)
//                 current = current->next;
//   Step 5: If current->next == NULL, the song was not found — print a message and return
//   Step 6: Unlink and free the target node:
//             struct Node* temp = current->next;
//             current->next = temp->next;
//             free(temp);
//             print confirmation
//
// displayPlaylist():
//   Step 1: Check if head == NULL; if so, print "Playlist is empty." and return
//   Step 2: Print a header row with column labels: Song, Artist, Genre
//   Step 3: Walk the list with a pointer starting at head:
//             struct Node* current = head;
//             while (current != NULL) { ... current = current->next; }
//   Step 4: Inside the loop, print each song's name, artist, and genre
