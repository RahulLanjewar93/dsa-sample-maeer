// Music Playlist — Singly linked list implementation
// Each node represents one song. Songs are added to the front of the playlist;
// removal searches by song name.

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
// Helper
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
// Core operations
// -----------------------------------------------------------------------

// Read song details from the user and add the song at the front of the playlist
void addSong() {
    char name[MAX_NAME], artist[MAX_ARTIST], genre[MAX_GENRE];

    printf("Song name: ");
    scanf(" %[^\n]", name);
    printf("Artist:    ");
    scanf(" %[^\n]", artist);
    printf("Genre:     ");
    scanf(" %[^\n]", genre);

    struct Node* newNode = createNode(name, artist, genre);

    // Point the new node to the current head, then update head
    newNode->next = head;
    head = newNode;

    printf("Added: \"%s\" by %s\n", name, artist);
}

// Ask the user for a song name and remove it from the playlist
void removeSong() {
    char name[MAX_NAME];

    printf("Enter song name to remove: ");
    scanf(" %[^\n]", name);

    if (head == NULL) {
        printf("Playlist is empty. Nothing to remove.\n");
        return;
    }

    // Special case: the song to remove is at the front
    if (strcmp(head->name, name) == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Removed \"%s\" from the playlist.\n", name);
        return;
    }

    // Walk the list to find the node just before the one to remove
    struct Node* current = head;
    while (current->next != NULL && strcmp(current->next->name, name) != 0)
        current = current->next;

    // Reached the end without finding the song
    if (current->next == NULL) {
        printf("\"%s\" not found in the playlist.\n", name);
        return;
    }

    // Unlink the target node and free its memory
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);

    printf("Removed \"%s\" from the playlist.\n", name);
}

// Print all songs in the playlist
void displayPlaylist() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\n%-30s %-25s %-15s\n", "Song", "Artist", "Genre");
    printf("%-30s %-25s %-15s\n",
           "------------------------------",
           "-------------------------",
           "---------------");

    struct Node* current = head;
    while (current != NULL) {
        printf("%-30s %-25s %-15s\n", current->name, current->artist, current->genre);
        current = current->next;
    }
}

// -----------------------------------------------------------------------
// Menu
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
