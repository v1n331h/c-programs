#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef, x, y, z;
    struct node* next;
};

struct node* create_node(int coef, int x, int y, int z) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->coef = coef;
    temp->x = x;
    temp->y = y;
    temp->z = z;
    temp->next = NULL;
    return temp;
}

struct node* insert(struct node* head, int coef, int x, int y, int z) {
    struct node* temp = create_node(coef, x, y, z);
    if (!head) {
        head = temp;
    } else {
        struct node* ptr = head;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}

void display(struct node* head) {
    if (!head) {
        printf("Polynomial is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp) {
        printf("%dx^%d y^%d z^%d", temp->coef, temp->x, temp->y, temp->z);
        if (temp->next) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

struct node* add_polynomials(struct node* head1, struct node* head2) {
    struct node* result = NULL;
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;

    while (ptr1 && ptr2) {
        if (ptr1->x == ptr2->x && ptr1->y == ptr2->y && ptr1->z == ptr2->z) {
            result = insert(result, ptr1->coef + ptr2->coef, ptr1->x, ptr1->y, ptr1->z);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->x > ptr2->x || 
                  (ptr1->x == ptr2->x && ptr1->y > ptr2->y) || 
                  (ptr1->x == ptr2->x && ptr1->y == ptr2->y && ptr1->z > ptr2->z)) {
            result = insert(result, ptr1->coef, ptr1->x, ptr1->y, ptr1->z);
            ptr1 = ptr1->next;
        } else {
            result = insert(result, ptr2->coef, ptr2->x, ptr2->y, ptr2->z);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1) {
        result = insert(result, ptr1->coef, ptr1->x, ptr1->y, ptr1->z);
        ptr1 = ptr1->next;
    }

    while (ptr2) {
        result = insert(result, ptr2->coef, ptr2->x, ptr2->y, ptr2->z);
        ptr2 = ptr2->next;
    }

    return result;
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;

    int n1, n2;

    // Input for the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the terms of the first polynomial (coefficient, powers of x, y, z):\n");
    for (int i = 0; i < n1; i++) {
        int coef, x, y, z;
        scanf("%d %d %d %d", &coef, &x, &y, &z);
        poly1 = insert(poly1, coef, x, y, z);
    }

    // Input for the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    printf("Enter the terms of the second polynomial (coefficient, powers of x, y, z):\n");
    for (int i = 0; i < n2; i++) {
        int coef, x, y, z;
        scanf("%d %d %d %d", &coef, &x, &y, &z);
        poly2 = insert(poly2, coef, x, y, z);
    }

    // Display the polynomials
    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    // Add the polynomials and display the result
    struct node* result = add_polynomials(poly1, poly2);
    printf("Resultant Polynomial after Addition: ");
    display(result);

    return 0;
}


