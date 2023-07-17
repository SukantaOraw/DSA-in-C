/*
This program contains the following operations on stack represented by linked list :
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

    if(head == NULL){

        printf("Empty stack.\n");
    }
    else{

        printf("The stack is :\n\n");
        temp = head;
        while(temp != NULL){

            printf("%d\n", temp -> data);
            temp = temp -> link;
        }
    }
}

struct node *enqueue(struct node *head){

    struct node *new;
    new = malloc(sizeof(struct node));
    
    if(new == NULL){

        printf("Memory not allocated.\n");
    }
    else{

        int item;
        printf("Enter item : ");
        scanf("%d", &item);


        new -> data = item;
        new -> link = head;
        head = new;

        printf("Item pushed.\n");
    }
    return head;
}

struct node *dequeue(struct node *head){

    struct node *temp;

    if(head == NULL){

        printf("Underflow.\n");
    }
    else{

        printf("The item popped is %d.\n", head -> data);
        temp = head;
        head = head -> link;
        free(temp);
    }
    return head;
}

void peek(struct node *head){

    struct node *temp;

    if(head == NULL){

        printf("Stack empty.\n");
    }
    else{

        printf("The top item is %d.\n", head -> data);
    }
}

struct node *empty(struct node *head){

    head = NULL;
    printf("Stack emptied.\n");
    return;
}

void main(){

    struct node *head;
    head = NULL;

    int ch;


    while(1){

        printf("\n--- Menu ---\nEnter :\n1 -> Traverse\n2 -> Enqueue\n3 -> Dequeue\n4 -> Peek()\n5 -> Empty Stack\n6 -> Exit\n");
        scanf("%d", &ch);

        switch(ch){

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
            default: printf("Wrong choice.\n");
            break;
        }
    }
}