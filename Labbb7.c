#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int book_id;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int book_id) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->book_id = book_id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* createTreeLevelOrder(int books[], int size) {
    if (size <= 0) {
        return NULL;
    }

    struct TreeNode* root = createNode(books[0]);
    struct TreeNode* queue[size];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < size) {
        struct TreeNode* current = queue[front++];

        int left_book = books[i++];
        if (left_book != -1) {
            current->left = createNode(left_book);
            queue[rear++] = current->left;
        }

        int right_book = books[i++];
        if (right_book != -1) {
            current->right = createNode(right_book);
            queue[rear++] = current->right;
        }
    }

    return root;
}

void inorderTraversal(struct TreeNode* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("Book ID: %d\n", node->book_id);
        inorderTraversal(node->right);
    }
}

void preorderTraversal(struct TreeNode* node) {
    if (node != NULL) {
        printf("Book ID: %d\n", node->book_id);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void postorderTraversal(struct TreeNode* node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("Book ID: %d\n", node->book_id);
    }
}

int main() {
    int library_books[] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int size = sizeof(library_books) / sizeof(library_books[0]);

    struct TreeNode* root_level_order = createTreeLevelOrder(library_books, size);

    printf("Inorder Traversal:\n");
    inorderTraversal(root_level_order);

    printf("\nPreorder Traversal:\n");
    preorderTraversal(root_level_order);

    printf("\nPostorder Traversal:\n");
    postorderTraversal(root_level_order);

    return 0;
}
