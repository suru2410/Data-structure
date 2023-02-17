#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node* createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
struct queue
{
    int front, rear, size;
    struct node* *arr;
};
struct queue* createQueue()
{
    struct queue* newQueue = (struct queue*) malloc(sizeof( struct queue ));

    newQueue->front = -1;
    newQueue->rear = 0;
    newQueue->size = 0;

    newQueue->arr = (struct node**) malloc(100 * sizeof( struct node* ));

    return newQueue;
}
void enqueue(struct queue* queue, struct node *temp){
    queue->arr[queue->rear++] = temp;
    queue->size++;
}
struct node *dequeue(struct queue* queue){
    queue->size--;
    return queue->arr[++queue->front];
}
void insertNode(int data) {
    struct node *newNode = createNode(data);
    if(root == NULL){
        root = newNode;
        return;
    }
    else {
        struct queue* queue = createQueue();

        enqueue(queue, root);

        while(true) {
            struct node *node = dequeue(queue);
            if(node->left != NULL && node->right != NULL) {
                enqueue(queue, node->left);
                enqueue(queue, node->right);
            }
            else {
                if(node->left == NULL) {
                    node->left = newNode;
                    enqueue(queue, node->left);
                }
                else {
                    node->right = newNode;
                    enqueue(queue, node->right);
                }
                break;
            }
        }
    }
}

//inorder() will perform inorder traversal on binary search tree
void inorderTraversal(struct node *node) {
    //Check whether tree is empty
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {

        if(node->left != NULL)
            inorderTraversal(node->left);
        printf("%d ", node->data);
        if(node->right != NULL)
            inorderTraversal(node->right);

        }
    }

int main(){

    //Add nodes to the binary tree
    insertNode(1);
    //1 will become root node of the tree
    printf("Binary tree after insertion: \n");
    //Binary after inserting nodes
    inorderTraversal(root);

    insertNode(2);
    insertNode(3);
    //2 will become left child and 3 will become right child of root node 1
    printf("\nBinary tree after insertion: \n");
    //Binary after inserting nodes
    inorderTraversal(root);

    insertNode(4);
    insertNode(5);
    //4 will become left child and 5 will become right child of node 2
    printf("\nBinary tree after insertion: \n");
    //Binary after inserting nodes
    inorderTraversal(root);

    insertNode(6);
    insertNode(7);
    //6 will become left child and 7 will become right child of node 3
    printf("\nBinary tree after insertion: \n");
    //Binary after inserting nodes
    inorderTraversal(root);

    return 0;
}
