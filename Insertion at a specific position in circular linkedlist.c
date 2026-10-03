#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        if (position != 1) {
            printf("Invalid position! List is empty, so position must be 1.\n");
            free(newNode);
            return;
        }
        *head = newNode;
        newNode->next = newNode; // Point to itself
        return;
    }
    if (position == 1) {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    int count = 1;
    while (count < position - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }
    if (count != position - 1) {
        printf("Invalid position! List has fewer nodes.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at position\n");
        printf("2. Display list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter data: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input! Please enter an integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                printf("Enter position: ");
                if (scanf("%d", &position) != 1 || position <= 0) {
                    printf("Invalid position! Must be a positive integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                insertAtPosition(&head, data, position);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}





