#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    char usn[20];
    char dept[50];
    float marks1;
    float marks2;
    float marks3;
    struct node* prev;
    struct node* next;
} *first = NULL, *last = NULL;

struct node* create() {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    printf("Enter the name:\n");
    scanf(" %[^\n]", temp->name);
    printf("Enter USN:\n");
    scanf(" %[^\n]", temp->usn);
    printf("Enter Department:\n");
    scanf(" %[^\n]", temp->dept);
    printf("Enter CIE-1 DSA Marks:\n");
    scanf("%f", &temp->marks1);
    printf("Enter CIE-2 DSA Marks:\n");
    scanf("%f", &temp->marks2);
    printf("Enter CIE-3 DSA Marks:\n");
    scanf("%f", &temp->marks3);

    temp->prev = temp->next = NULL;

    return temp;
}

void insertfront() {
    struct node* temp = create();
    if (temp == NULL) return;

    if (first == NULL) {
        first = last = temp;
    } else {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    printf("Node inserted at the front.\n");
}

void insertrear() {
    struct node* temp = create();
    if (temp == NULL) return;

    if (last == NULL) {
        first = last = temp;
    } else {
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
    printf("Node inserted at the rear.\n");
}

void deletefront() {
    if (first == NULL) {
        printf("List is empty. Cannot delete from the front.\n");
        return;
    }

    struct node* temp = first;
    if (first == last) { // Single node case
        first = last = NULL;
    } else {
        first = first->next;
        first->prev = NULL;
    }
    printf("Deleted node from the front: %s\n", temp->name);
    free(temp);
}

void deleterear() {
    if (last == NULL) {
        printf("List is empty. Cannot delete from the rear.\n");
        return;
    }

    struct node* temp = last;
    if (first == last) { // Single node case
        first = last = NULL;
    } else {
        last = last->prev;
        last->next = NULL;
    }
    printf("Deleted node from the rear: %s\n", temp->name);
    free(temp);
}

void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = first;
    printf("Doubly Linked List:\n");
    while (temp != NULL) {
        printf("Name: %s, USN: %s, Dept: %s, Marks: %.2f, %.2f, %.2f\n",
               temp->name, temp->usn, temp->dept, temp->marks1, temp->marks2, temp->marks3);
        temp = temp->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertfront();
                break;
            case 2:
                insertrear();
                break;
            case 3:
                deletefront();
                break;
            case 4:
                deleterear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}