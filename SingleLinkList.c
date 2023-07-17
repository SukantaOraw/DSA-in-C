/*
// This program contains the following operations on single linked list :
// 1.Creation
// 2.Traversal
// 3.Insertion at begining
// 4.Insertion in-between (works also for end)
// 5.Insertion at end (same as creation)
// 6.Reverse list
// 7.Searching
// 8.Converting array to Single linked list (Merges with the main list (at the front) if available)
// 9.Delete first
// 10.Delete in-between (works also for end)
// 11.Delete last
// 12.Back Traverse (only traverse backwards)
// 13.Sorting
// 14.Merging

// Polynomial representation not available
*/

#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *link;
};

struct node *creation(struct node *head){

    struct node *temp, *new;
    int item;
    new = malloc(sizeof(struct node));

    if(new == NULL){
        printf("No memory element.\n");
    }
    else{
        printf("Enter item: ");
        scanf("%d",&item);
        new -> data = item;
        new -> link = NULL;

        if(head == NULL){
            head = new;
        }
        else{
            temp = head;
            
            while(temp -> link != NULL){
                temp = temp -> link;
            }
            temp -> link = new;
        }
        printf("Node inserted.\n");
    }
    return head;
}

void traverse( struct node *head){

    struct node *temp;
    printf("The list : ");

    if(head == NULL){
        printf("No List Exist.\n");
    }
    else{
        temp = head;

        while(temp != NULL){
            printf("%d\t",temp -> data);
            temp = temp -> link;
        }
        printf("\n");
    }
}

struct node *in_beg(struct node *head){

    struct node *new;
    int item;
    new = malloc(sizeof(struct node));

    printf("Enter item to be inserted : ");
    scanf("%d", &item);

    if(new == NULL){

        printf("Memory not available.\n");
    }
    else{
        new -> data = item;
        new -> link = head;
        head = new;
        printf("Node inserted.\n");
    }
    return head;
}

struct node *in_bet(struct node *head){

    struct node *new, *temp, *ptemp;
    int pos, item;
    int count = 0;
    new = malloc(sizeof(struct node));

    temp = head;

    printf("Enter the position to insert node : ");
    scanf("%d", &pos);

    printf("Enter the item : ");
    scanf("%d", &item);

    if(new == NULL){

        printf("Memory not available.\n");
    }
    else{
        while(count < pos - 1){

            ptemp = temp;
            temp = temp -> link;
            count += 1;
        }

        new -> data = item;
        new -> link = temp;
        ptemp -> link = new;
        printf("Node inserted.\n");
    }
    return head;
}

struct node *in_end(struct node *head){

    struct node *temp, *new;
    int item;
    new = malloc(sizeof(struct node));

    printf("Enter item to be inserted : ");
    scanf("%d", &item);

    if(new == NULL){

        printf("Memory not available.\n");
    }else{

        temp = head;
        new -> data = item;
        new -> link = NULL;

        while(temp -> link != NULL){
            temp = temp -> link;
        }
        temp -> link = new;
        printf("Node inserted.\n");
    }
    return head;
}

struct node *reverse(struct node *head){

    struct node *prev = NULL, *next = NULL, *current = head;

    while(current != NULL){

        next = current -> link;
        current -> link = prev;

        prev = current;
        current = next;
    }
    head = prev;

    printf("List reversed.\n");
    return head;
}

void search(struct node *head){

    struct node *temp;
    int count = 0;
    int found = 0;
    int sitem;

    printf("Enter the item to be searched : ");
    scanf("%d", &sitem);

    if(head == NULL){
        printf("No List Exist.\n");
    }
    else{
        temp = head;

        while(temp != NULL){
            if(temp -> data == sitem){

                printf("%d was found at the index %d.\n", sitem, count);
                found++;
            }
            temp = temp->link;
            count++;
        }

        if(found == 0){
            printf("Item not found.\n");
        }
    }
}

struct node *arrtoslnk(struct node *head){

    // Array part 
    int size;
    
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the Elements : ");

    for(int i = 0; i < size; i++){

        scanf("%d", &arr[i]);
    }
    // End of array part

    struct node *new;

    while(size != 0){

        new = malloc(sizeof(struct node));
        if(new == NULL){
           
            printf("NO memory allocated.\n");
        }else{

            new -> data = arr[--size];
            new -> link = head;
            head = new;
        }
    }
    printf("Converted successfully.\n");
    return head;
}

struct node *del_first(struct node *head){

    struct node *temp;

    if(head == NULL){
        printf("The list is empty.\n");
    }else{

        temp = head;
        head = head -> link;
        free(temp);
        printf("Node deleted.\n");
    }
    return head;
}

struct node *del_bet(struct node *head){

    int pos;
    int count = 0;
    struct node *temp, *prev;

    printf("Enter the position to delete : ");
    scanf("%d", &pos);

    if(head == NULL){
        printf("The list is empty.\n");
    }else{

        temp = head;

        while(count < pos - 1){

            prev = temp;
            temp = temp -> link;
            count++;
        }

        prev -> link = temp -> link;
        free(temp);
        printf("Node deleted.\n");
    }
    return head;
}

struct node *del_last(struct node *head){

    struct node *temp, *prev;

    if(head == NULL){
        printf("The list is empty.\n");
    }else{

        temp = head;
        while(temp -> link != NULL){
            prev = temp;
            temp = temp -> link;
        }
        prev -> link = NULL;
        free(temp);
        printf("Node deleted.\n");
    }
    return head;
}

void backtraverse(struct node *head){

    struct node *last, *forward, *current;
    printf("Back Traversed list : ");

    last = NULL;
    current = head;

    while(current != last){

        forward = current;

        while(forward -> link != last){

            forward = forward -> link;
        }

        printf("%d\t", forward -> data);
        last = forward;
    }
    printf("\n");
}

struct node *sort(struct node *head){

    struct node *current, *next;
    int temp;

    if(head == NULL){
        printf("NO list exist.\n");
    }else{
        
        current = head;

        while(current != NULL){

            next = current -> link;

            while(next != NULL){

                if(current -> data > next -> data){

                    temp = current -> data;
                    current -> data = next -> data;
                    next -> data = temp;
                }

                next = next -> link;
            }
            current = current -> link;
        }
        printf("List sorted.\n");
    }
    return head;
}

/*Same creation function [note :- head is replaced by head0]*/
struct node *creation_sec(struct node *head0){

    struct node *temp, *new;
    int item;
    new = malloc(sizeof(struct node));

    if(new == NULL){
        printf("No memory element.\n");
    }
    else{
        printf("Enter item: ");
        scanf("%d",&item);
        new -> data = item;
        new -> link = NULL;

        if(head0 == NULL){
            head0 = new;
        }
        else{
            temp = head0;
            
            while(temp -> link != NULL){
                temp = temp -> link;
            }
            temp -> link = new;
        }
        printf("Node inserted.\n");
    }
    return head0;
}

struct node *merge(struct node *head,struct node *head0){

    /* --- Not actually needed --- */
    if(head == NULL && head0 == NULL){
        printf("Both list are empty.\n");
    }
    else if(head == NULL && head0 != NULL){
        printf("First list is empty.\n");
    }
    else if(head != NULL && head0 == NULL){
        printf("Second list is empty.\n");
    }
    /* --- Not actually needed --- */

    if(head != NULL && head0 != NULL){

        struct node *temp;
    
        temp = head;

        while(temp -> link != NULL){
            temp = temp -> link;
        }
        temp -> link = head0;
        printf("Second list merged to First list.\n");
    }
    
    return head;
}

void main(){

    struct node *head, *head0; /*Include this *head0 if merging is included in the program*/
    head = NULL;
    head0 = NULL; /*Include this head0 if merging is included in the program*/

    int c;

    while(1){

        printf("\n----- Menu -----\nEnter :\n1 -> Creation\n2 -> Traversal\n3 -> Insertion at begining\n4 -> Insertion in-between\n5 -> Insertion at the end\n6 -> Reverse List\n7 -> Searching\n8 -> Convert array to Single linked list\n9 -> Delete first\n10 -> Delete in-between\n11 -> Delete last\n12 -> Back Traverse\n13 -> Sort\n14 -> Create second list for merging to the main list\n15 -> Merge\n16 -> Exit\n");
        scanf("%d", &c);

        switch(c){

            case 1: head = creation(head);
            break;
            case 2: traverse(head);
            break;
            case 3: head = in_beg(head);
            break;
            case 4: head = in_bet(head);
            break;
            case 5: head = in_end(head);
            break;
            case 6: head = reverse(head);
            break;
            case 7: search(head);
            break;
            case 8: head = arrtoslnk(head); /*Merges with the main list (at the front) if available*/
            break;
            case 9: head = del_first(head);
            break;
            case 10: head = del_bet(head);
            break;
            case 11: head = del_last(head);
            break;
            case 12: backtraverse(head);
            break;
            case 13: head = sort(head);
            break;
            case 14: head0 = creation_sec(head0); /*Include this case if merging is included in the program*/
            break;
            case 15: head = merge(head,head0);
            break;
            case 16: printf("-- End of program --\n");
            exit(0);
            default: printf("Wrong Choice\n");
            break;
        }
    }
}