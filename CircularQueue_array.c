/*
This program contains the following operations on circular queue represented by an array :
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

void isfull(int max, struct queue *cqueue){

    if((cqueue -> front == cqueue -> rear + 1) || cqueue -> front == 0 && cqueue -> rear == max - 1){

        printf("The queue is full.\n");
    }else{

        printf("The queue is not full.\n");
    }
}

void isempty(struct queue *cqueue){

    if((cqueue -> front == -1) || (cqueue -> rear == cqueue -> front)){

        printf("The queue is empty.\n");
    }
    else{

        printf("The queue is not empty.\n");
    }
}

void traverse(int max, struct queue *cqueue){

    if((cqueue -> front == -1) || (cqueue -> rear == cqueue -> front)){

        printf("Empty queue.\n");
    }
    else{

        int i;
        printf("The queue is : ");
        for(i = cqueue -> front; i != cqueue -> rear; i = (i+1) % max){

            printf("%d   ", cqueue -> items[i]);
        }
        printf("%d\n", cqueue -> items[i]);
    }
}

struct queue *enqueue(int max, struct queue *cqueue){

    if((cqueue -> front == cqueue -> rear + 1) || (cqueue -> front == 0 && cqueue -> rear == max - 1)){

        printf("Overflow.\n");
    }else{

        int item;
        printf("Enter item : ");
        scanf("%d", &item);

        if(cqueue -> front == -1){

            cqueue -> front = 0;
        }

        cqueue -> rear = (cqueue -> rear + 1) % max;
        cqueue -> items[cqueue -> rear] = item;
        printf("Item enqueued.\n");
    }
    return cqueue;
}

struct queue *dequeue(int max, struct queue *cqueue){

    if(cqueue -> front == -1 || cqueue -> front == cqueue -> rear){

        printf("Underflow.\n");
    }
    else{

        printf("The item dequeued is %d.\n", cqueue -> items[cqueue -> front]);
        cqueue -> front = (cqueue -> front + 1) % max;
    }
    return cqueue;
}

void peek(struct queue *cqueue){

    if(cqueue -> front == -1 || cqueue -> front == cqueue -> rear){

        printf("Empty queue.\n");
    }
    else{

         printf("The item dequeued is %d.\n", cqueue -> items[cqueue -> front]);
    }
}

struct queue *emptyqueue(struct queue *cqueue){

    cqueue -> front = -1;
    cqueue -> rear = -1;
    printf("Queue emptied.\n");
    return cqueue;
}

void main(){

    int max;
    printf("Enter the size of the queue : ");
    scanf("%d", &max);

    int c;

    struct queue *cqueue;
    cqueue -> items[max];
    cqueue = malloc(sizeof(struct queue));

    cqueue -> rear = -1;
    cqueue -> front = -1;

    while(1){

        printf("\n--- Menu ---\nEnter :\n1 -> Isfull()\n2 -> Isempty()\n3 -> Traverse\n4 -> Enqueue\n5 -> Dequeue\n6 -> Peek()\n7 -> Empty queue\n8 -> Exit\n");
        scanf("%d", &c);

        switch(c){

            case 1: isfull(max,cqueue);
            break;
            case 2: isempty(cqueue);
            break;
            case 3: traverse(max,cqueue);
            break;
            case 4: cqueue = enqueue(max,cqueue);
            break;
            case 5: cqueue = dequeue(max,cqueue);
            break;
            case 6: peek(cqueue);
            break;
            case 7: emptyqueue(cqueue);
            break;
            case 8: printf("-- End of program --\n");
            exit(0);
            default: printf("Wrong choice.\n");
            break;
        }
    }
}