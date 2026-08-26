#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *newNode = NULL, *temp = NULL;
    char choice;

    do {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        printf("Enter data for the node: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode; 
            temp = newNode;
        } else {
            temp->next = newNode; 
            temp = newNode;       
        }
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice); 
    } while (choice == 'y' || choice == 'Y');
    printf("\nLinked List Nodes: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    temp = head;
     while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    return 0;
}
