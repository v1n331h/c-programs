#include <stdio.h>
#define MAX 5 // Maximum size of the circular queue

int queue[MAX];
int front = 0, rear = -1, count = 0; // Initialize front, rear, and count

// Check if the queue is empty
int isEmpty() {
    return (count == 0);
}

// Check if the queue is full
int isFull() {
    return (count == MAX);
}

// Insert an element into the circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    count++;
    printf("Inserted %d into the queue.\n", value);
}

// Delete an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }
    printf("Deleted %d from the queue.\n", queue[front]);
    front = (front + 1) % MAX;
    count--;
}

// Display the elements in the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < count; i++) {
        int index = (front + i) % MAX;
        printf("%d ", queue[index]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}