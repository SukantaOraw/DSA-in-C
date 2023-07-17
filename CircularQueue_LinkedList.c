/*
This program contains the following operations on circular queue represented by a linked list :
1. Traverse
2. Enqueue
3. Dequeue
4. Peek()
5. Empty queue (reset)
*/

#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node *link;
};

void traverse(struct node *head){

    struct node *temp;
    printf("The queue is :\n\n");

    if(head == NULL){
        printf("Empty Queue.\n");
    }
    else{

        temp = head;

        do{
            printf("%d\n",temp -> data);
            temp = temp -> link;
        }while(temp != head);
    }
}

struct node *enqueue(struct node *head){

    struct node *temp, *new;
    int item;
    new = malloc(sizeof(struct node));

    if(new == NULL){
        printf("Memory not allocated.\n");
    }else{
        
        printf("Enter item : ");
        scanf("%d", &item);
        new -> data = item;
        new -> link = NULL;

        if(head == NULL){
            head = new;
        }else{

            temp = head;
            while(temp -> link != head){
                temp = temp -> link;
            }
            temp -> link = new;
        }
        new -> link = head;
        printf("Item enqueued.\n");
    }
    return head;
}

struct node *dequeue(struct node *head){

    struct node *temp, *forward;

    if(head == NULL){

        printf("Underflow.\n");
    }else{
        
        printf("The item dequeued is %d.\n", head -> data);

        if(head == head -> link){

            head = NULL;
        }
        else{

            temp = head;
            forward = head;

            while(forward -> link != head){

                forward = forward -> link;
            }   

            head = head -> link;
            forward -> link = head;
            free(temp); 
        }
    }
    return head;
}

void peek(struct node *head){

    struct node *temp;

    if(head == NULL){

        printf("Empty queue.\n");
    }
    else{

        printf("The top item is %d.\n", head -> data);
    }
}

struct node *empty(struct node *head){

    head = NULL;
    printf("Queue emptied.\n");
    return head;
}

void main(){

    struct node *head;
    head = NULL;

    int c;

    while(1){

        printf("\n----- Menu -----\nEnter :\n1 -> Traverse\n2 -> Enqueue\n3 -> Dequeue\n4 -> Peek()\n5 -> Empty()\n6 -> Exit\n");
        scanf("%d", &c);

        switch(c){

            case 1: traverse(head);
            break;
            case 2: head = enqueue(head); 
            break;
            case 3: head = dequeue(head);
            break;
            case 4: peek(head);
            break;
            case 5: head = empty(head);
            break;
            case 6: printf("-- End of program --\n");
            exit(0);
            default : printf("Wrong choice.\n");
            break;
        }
    }
}