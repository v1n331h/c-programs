#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a BST node
typedef struct Node {
    char name[50];
    char phone[15];
    struct Node* left;
    struct Node* right;
}Node;

// Function to create a new node
Node* createNode(char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, char* name, char* phone) {
    if (root == NULL) {
        return createNode(name, phone);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, phone);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, phone);
    } else {
        printf("Name already exists in the phone list.\n");
    }
    return root;
}

// Function to search for a name in the BST
Node* search(Node* root, char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    }
    return search(root->right, name);
}

// Function to find the minimum node in the BST
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* delete(Node* root, char* name) {
    if (root == NULL) {
        printf("Name not found in the phone list.\n");
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        root->left = delete(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = delete(root->right, name);
    } else {
        // Node to be deleted found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);
        root->right = delete(root->right, temp->name);
    }
    return root;
}

// Function for Inorder Traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%s - %s\n", root->name, root->phone);
    inorder(root->right);
}

// Function for Preorder Traversal
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%s - %s\n", root->name, root->phone);
    preorder(root->left);
    preorder(root->right);
}

// Function for Postorder Traversal
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%s - %s\n", root->name, root->phone);
}

int main() {
    Node* root = NULL;
    int choice;
    char name[50], phone[15];

    while (1) {
        printf("\n--- Phone List Menu ---\n");
        printf("1. Insert a new name\n");
        printf("2. Search for a name\n");
        printf("3. Delete a name\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                root = insert(root, name, phone);
                break;

            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                Node* found = search(root, name);
                if (found) {
                    printf("Found: %s - %s\n", found->name, found->phone);
                } else {
                    printf("Name not found in the phone list.\n");
                }
                break;

            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                root = delete(root, name);
                break;

            case 4:
                printf("Inorder Traversal:\n");
                inorder(root);
                break;

            case 5:
                printf("Preorder Traversal:\n");
                preorder(root);
                break;

            case 6:
                printf("Postorder Traversal:\n");
                postorder(root);
                break;

            case 7:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}