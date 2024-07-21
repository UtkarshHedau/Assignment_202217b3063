#include <stdio.h>
#include <stdlib.h>

#define n 5

void insert(int queue[], int *rear, int *j);
void delete(int queue[], int *front, int *rear);
void display(int queue[], int front, int rear);

int main() {
    int queue[n], ch = 1, front = 0, rear = 0, j = 1;
    
    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");
    
    while(ch) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                insert(queue, &rear, &j);
                break;
            case 2:
                delete(queue, &front, &rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice: please see the options");
        }
    }
    
    return 0;
}

void insert(int queue[], int *rear, int *j) {
    if(*rear == n) {
        printf("\nQueue is Full");
    } else {
        printf("\nEnter no %d: ", (*j)++);
        scanf("%d", &queue[*rear]);
        (*rear)++;
    }
}

void delete(int queue[], int *front, int *rear) {
    if(*front == *rear) {
        printf("\nQueue is Empty");
    } else {
        printf("\nDeleted Element is %d", queue[*front]);
        (*front)++;
        if(*front == *rear) {
            // Resetting the queue when it becomes empty
            *front = 0;
            *rear = 0;
        }
    }
}

void display(int queue[], int front, int rear) {
    if(front == rear) {
        printf("\nQueue is Empty");
    } else {
        printf("\nQueue Elements are:\n");
        for(int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
