/*
// This program contains the following operations on Circular linked list :
// 1.Creation
// 2.Traversal
// 3.Insertion at beginning
// 4.Insertion in-between (works for end but it would no more be circular linked)
// 5.Insertion at the end
// 6.Delete first
// 7.Delete in-between (works for end but it would no more be circular linked)
// 8.Delete at the end
// 9.Searching
// 10.Sorting
// 11.Reversing
// 12.Back Traversal
// 13.Converting array to Circular linked list (Not recommended but does the job)(Merges with the main list (at the back) if available)
// 14.Merging
*/

#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node *link;
};

struct node *creation(struct node *head){

    struct node *temp, *new;
    int item;
    new = malloc(sizeof(struct node));

    if(new == NULL){
        printf("Memory not allocated.\n");
    }else{
        
        printf("Enter item : ");
        scanf("%d", &item);
        new -> data = item;
        new -> link = new; /*we can use new -> link = NULL instead of new -> link = new */

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
        printf("Node inserted.\n");
    }
    return head;
}

void traverse(struct node *head){

    /*struct node *temp;
    printf("The list : ");

    if(head == NULL){
        printf("No List Exist.\n");
    }
    else{

        temp = head;

        printf("%d\t", temp -> data);
        temp = temp -> link;

        while(temp != head){
            printf("%d\t",temp -> data);
            temp = temp -> link;
        }
        printf("\n");
    }*/

    // Or 
    // Just a difference of while(){} loop and do{}while; loop

    struct node *temp;
    printf("The list : ");

    if(head == NULL){
        printf("No List Exist.\n");
    }
    else{

        temp = head;

        do{
            printf("%d\t",temp -> data);
            temp = temp -> link;
        }while(temp != head);
        
        printf("\n");
    }
}

struct node *in_beg(struct node *head){

    struct node *temp, *new;
    int item;
    new = malloc(sizeof(struct node));

    if(new == NULL){
        printf("Memory not allocated.\n");
    }else{

        printf("Enter item : ");
        scanf("%d", &item);
        new -> data = item;
        new -> link = head;

        temp = head;
        while(temp -> link != head){
            temp = temp -> link;
        }
        head = new;
        temp -> link = new;
        printf("Node inserted.\n");
    }
    return head;
}

struct node *in_bet(struct node *head){

    struct node *prev, *temp, *new;
    int item, pos;
    int count = 0;
    new = malloc(sizeof(struct node));

    printf("Enter the position : ");
    scanf("%d", &pos);

    if(new == NULL){

        printf("NO memory allocated.\n");
    }else{

        printf("Enter item : ");
        scanf("%d", &item);
        new -> data = item;
        new -> link = NULL;

        temp = head;
        while(count < pos - 1){
            prev = temp;
            temp = temp -> link;
            count++;
        }
        prev -> link = new;
        new -> link = temp;
        printf("Node inserted.\n");
    }
    return head;
}

struct node *in_end(struct node *head){

    struct node *temp, *new;
    int item;
    new = malloc(sizeof(struct node));

    if(new == NULL){
        printf("NO memory allocated.\n");
    }else{

        printf("Enter item : ");
        scanf("%d", &item);
        new -> data = item;
        new -> link = new; /*we can use new -> link = NULL instead of new -> link = new */

        temp = head;

        while(temp -> link != head){

            temp = temp -> link;
        }
        temp -> link = new;
        new -> link = head;
        printf("Node inserted.\n");
    }
    return head;
}

struct node *del_first(struct node *head){

    struct node *temp, *forward;

    if(head == NULL){

        printf("The list is empty.\n");
    }else{

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
        printf("Node deleted.\n");
    }
    return head;
}

struct node *del_bet(struct node *head){

    struct node *prev, *temp;
    int pos;
    int count = 0;

    printf("Enter the position : ");
    scanf("%d", &pos);

    if(head == NULL){

        printf("The list is empty.\n");
    }else{

        if(head == head -> link){

            head = NULL;
        }else{

            temp = head;
            while(count < pos - 1){
                prev = temp;
                temp = temp -> link;
                count++;
            }
            prev -> link = temp -> link;
            free(temp);
        }
        printf("Node deleted.\n");
    }
    return head;
}

struct node *del_end(struct node *head){

    struct node *temp, *prev;

    if(head == NULL){
        printf("The list is empty.\n");
    }else{

        if(head == head -> link){

            head = NULL;
        }else{

            temp = head;
            while(temp -> link != head){
                prev = temp;
                temp = temp -> link;
            }
            prev -> link = head;
            free(temp);
        }
        printf("Node deleted.\n");
    }
    return head;
}

void search(struct node *head){

    /*struct node *temp;
    int count = 1;
    int found = 0;
    int sitem;

    printf("Enter the item to be searched : ");
    scanf("%d", &sitem);

    if(head == NULL){
        printf("No List Exist.\n");
    }
    else{

        temp = head;

        if(temp -> data == sitem){
            printf("%d was found at the index 0.\n", sitem);
            found++;
        }
        temp = temp -> link;

        while(temp != head){

            if(temp -> data == sitem){

                printf("%d was found at the index %d.\n", sitem, count);
                found++;
            }
            temp = temp -> link;
            count++;
        }
        
        if(found == 0){
            printf("Item not found.\n");
        }
    }*/

    // Or
    // Just a difference of while(){} loop and do{}while; loop

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

        do{

            if(temp -> data == sitem){

                printf("%d was found at the index %d.\n", sitem, count);
                found++;
            }
            temp = temp -> link;
            count++;
        }while(temp != head);
        
        if(found == 0){
            printf("Item not found.\n");
        }
    }
}

struct node *sort(struct node *head){

    struct node *current, *next;
    int temp;

    if(head == NULL){
        printf("NO list exist.\n");
    }else{
        
        current = head;

        do{
            next = current -> link;

            while(next != head){

                if(current -> data > next -> data){

                    temp = current -> data;
                    current -> data = next -> data;
                    next -> data = temp;
                }

                next = next -> link;
            }
            current = current -> link;

        }while(current != head);
        printf("List sorted.\n");
    }
    return head;
}

struct node *reverse(struct node *head){

    struct node *prev = NULL, *next = NULL, *current = head;

    do{
        next = current -> link;
        current -> link = prev;

        prev = current;
        current = next;
    }while(current != head);

    head = prev;
    current -> link = head;

    printf("List reversed.\n");
    return head;
}

struct node *backtraverse(struct node *head){

    struct node *last, *current, *forward;
    printf("Back Traversed list : ");

    current = head;
    last = head;

    do{
        forward = current;
        while(forward -> link != last){

            forward = forward -> link;
        }
        printf("%d\t", forward -> data);
        last = forward;
    }while(current != last);
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

    struct node *temp, *new;
    int index = 0;
    
    while(index < size){

        new = malloc(sizeof(struct node));

        if(new == NULL){
           
            printf("NO memory allocated.\n");
        }else{

           new -> data = arr[index++];
           new -> link = NULL; /*we can use new -> link = NULL instead of new -> link = new */

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
        }

    }
    printf("Converted sucessfully.\n");
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
        
        printf("Enter item : ");
        scanf("%d", &item);
        new -> data = item;
        new -> link = new; /*we can use new -> link = NULL instead of new -> link = new */

        if(head0 == NULL){
            head0 = new;
        }else{

            temp = head0;
            while(temp -> link != head0){
                temp = temp -> link;
            }
            temp -> link = new;
        }
        new -> link = head0;
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

        struct node *temp, *temp0;
    
        temp = head;
        temp0 = head0;

        do{
            temp0 = temp0 -> link;
        }while(temp0 -> link != head0);
        temp0 -> link = head;

        do{
            temp = temp -> link;
        }while(temp -> link != head);
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

        printf("\n----- Menu -----\nEnter :\n1 -> Creation\n2 -> Traverse\n3 -> Insert at beginning\n4 -> Insert in-between\n5 -> Insert at the end\n6 -> Delete first\n7 -> Delete in-between\n8 -> Delete at the end\n9 -> Search\n10 -> Sort\n11 -> Reverse\n12 -> Back traverse\n13 -> Convert array to Circular linked list\n14 -> Create second list for merging to the main list\n15 -> Merge\n16 -> Exit\n");
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
            case 6: head = del_first(head);
            break;
            case 7: head = del_bet(head);
            break;
            case 8: head = del_end(head);
            break;
            case 9: search(head);
            break;
            case 10: head = sort(head);
            break;
            case 11: head = reverse(head);
            break;
            case 12: backtraverse(head);
            break;
            case 13: head = arrtoslnk(head); /*Merges with the main list (at the back) if available*/
            break;
            case 14: head0 = creation_sec(head0); /*Include this case if merging is included in the program*/
            break;
            case 15: head = merge(head,head0);
            break;
            case 16: printf("-- End of program --\n");
            exit(0);
            default : printf("Wrong choice.\n");
            break;
        }
    }
}