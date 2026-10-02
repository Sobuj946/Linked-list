#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// লিংকড লিস্টের শুরু পয়েন্ট
struct Node* start = NULL;

// শুরুতে ইনসার্ট করা
void insertAtBeginning(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = start;
    start = newnode;
}

// যেকোনো নির্দিষ্ট index এ ইনসার্ট করা (0-based index)
void insertAtIndex(int value, int index) {
    if (index == 0) {
        insertAtBeginning(value);
        return;
    }

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;

    struct Node* temp = start;
    for (int i = 0; i < index - 1; i++) {
        if (temp == NULL) {
            printf("Index out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// শেষে ইনসার্ট করা
void insertAtEnd(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
        return;
    }

    struct Node* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// লিস্ট প্রিন্ট করা
void printList() {
    struct Node* temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;

    printf("Enter number of elements to insert at end: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(value);
    }

    printf("Initial List: ");
    printList();

    // শুরুতে ইনসার্ট
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);
    insertAtBeginning(value);
    printList();

    // মাঝখানে ইনসার্ট
    int index;
    printf("Enter index and value to insert at that index: ");
    scanf("%d %d", &index, &value);
    insertAtIndex(value, index);
    printList();

    // শেষে ইনসার্ট
    printf("Enter value to insert at end: ");
    scanf("%d", &value);
    insertAtEnd(value);
    printList();

    return 0;
}
