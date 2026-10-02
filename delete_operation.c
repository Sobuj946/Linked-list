#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* next;
};

struct Node* start = NULL;

// Insert at end (for initial test data)
void insert_end(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
    } else {
        struct Node* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Delete from the beginning
void delete_beginning() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = start;
    start = start->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Delete from the end
void delete_end() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (start->next == NULL) {
        printf("Deleted: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    struct Node* temp = start;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Delete a specific value (middle or anywhere)
void delete_value(int value) {
    struct Node *temp = start, *prev = NULL;

    // If first node matches
    if (temp != NULL && temp->data == value) {
        start = temp->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    prev->next = temp->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Display the list
void display() {
    struct Node* temp = start;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test
int main() {
    int choice, val;

    // Add some values
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);
    insert_end(50);

    do {
        printf("\nMenu:\n");
        printf("1. Display\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete by Value\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                delete_beginning();
                break;
            case 3:
                delete_end();
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete_value(val);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
