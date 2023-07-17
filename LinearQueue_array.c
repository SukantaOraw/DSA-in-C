/*
This program contains the following operations on linear queue represented by an array :
1. Isfull()
2. Isempty()
3. Traverse
4. Enqueue
5. Dequeue
6. Peek()
7. Empty queue (reset)
*/

#include <stdio.h>
#include <stdlib.h>

struct queue{

    int front;
    int rear;
    int items[];
};

void isfull(int max, struct queue *rqueue){

    if(rqueue -> rear == max - 1){

        printf("The queue is full.\n");
    }
    else{

        printf("The queue is not full.\n");
    }
}

void isempty(struct queue *rqueue){

    if(rqueue -> front == -1 && rqueue -> rear == -1){

        printf("The queue is empty.\n");
    }
    else{

        printf("The queue is not empty.\n");
    }
}

void traverse(struct queue *rqueue){

    if((rqueue -> front == -1 && rqueue -> rear == -1) || rqueue -> rear == rqueue -> front){

        printf("Empty queue.\n");
    }
    else{
        
        printf("The queue is :\n\n");
        for(int i = rqueue -> front + 1; i <= rqueue -> rear; i++){

            printf("%d\n", rqueue -> items[i]);
        }
    }
}

struct queue *enqueue(int max,struct queue *rqueue){

    int item;

    printf("Enter item : ");
    scanf("%d", &item);

    if(rqueue -> rear == max - 1){

        printf("Overflow.\n");
    }
    else{

        rqueue -> rear++;
        rqueue -> items[rqueue -> rear] = item;
        printf("Item enqueued.\n");
    }
    return rqueue;
}

struct queue *dequeue(struct queue *rqueue){

    if(rqueue -> rear == rqueue -> front){

        printf("Underflow.\n");
    }
    else{

        printf("The item dequeued is %d.\n", rqueue -> items[++rqueue -> front]);
    }
    return rqueue;
}

void peek(struct queue *rqueue){

    if((rqueue -> front == -1 && rqueue -> rear == -1) || rqueue -> rear == rqueue -> front){

        printf("Empty queue.\n");
    }
    else{
        printf("The rear value is %d.\n", rqueue -> items[rqueue -> rear]);
    }
}

struct queue *emptyqueue(struct queue *rqueue){

    rqueue -> front = -1;
    rqueue -> rear = -1;
    printf("Queue emptied.\n");
    return rqueue;
}

void main(){

    int max;
    printf("Enter the size of the queue : ");
    scanf("%d", &max);

    struct queue *rqueue;
    int c;

    rqueue -> items[max];
    rqueue = malloc(sizeof(struct queue));

    rqueue -> front = -1;
    rqueue -> rear = -1;

    while(1){

        printf("\n--- Menu ---\n1 -> Isfull()\n2 -> Isempty()\n3 -> Traverse\n4 -> Enqueue\n5 -> Dequeue\n6 -> Peek()\n7 -> Empty queue (reset)\n8 -> Exit\n");
        scanf("%d", &c);

        switch(c){

            case 1: isfull(max,rqueue);
            break;
            case 2: isempty(rqueue);
            break;
            case 3: traverse(rqueue);
            break;
            case 4: rqueue = enqueue(max,rqueue);
            break;
            case 5: rqueue = dequeue(rqueue);
            break;
            case 6: peek(rqueue);
            break;
            case 7: rqueue = emptyqueue(rqueue);
            break;
            case 8: printf("-- End of program --\n");
            exit(0);
            default: printf("Wrong choice.\n");
            break;
        }
    }
}