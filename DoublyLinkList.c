/* 
This program contains the following operations on Doubly Linked List :
1. Creation
2. Traverse
3. Back traverse
4. Insertion at begining
5. Insertion in-between
6. Insertion at the end
7. Delete first
8. Delete in-between
9. Delete last
10. Reversing
11. Searching
12. Sorting
13. Merging
14. Converting array to Doubly linked list (Merges with the main (at the back) list if available)
*/

#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node *rlink;
    struct node *llink;
};

struct node *creation(struct node *head){

    struct node *temp, *new;
    int item;
    new = malloc(sizeof(struct node));

    if(new == NULL){
        
        printf("NO memory allocated.\n");
    }else{

        printf("Enter item : ");
        scanf("%d", &item);
        new -> data = item;
        new -> rlink = NULL;
        new -> llink = NULL;

        if(head == NULL){
            
            head = new;
        }
        else{

            temp = head;

            while(temp -> rlink != NULL){

                temp = temp -> rlink;
            }
            temp -> rlink = new;
            new -> llink = temp;
        }
        printf("Node Inserted.\n");
    }
    return head;
}

void traverse(struct node *head){

    struct node *temp;
    printf("The list : ");

    if(head == NULL){

        printf("The list is empty.\n");
    }else{

        temp = head;

        while(temp != NULL){

            printf("%d   ", temp -> data);
            temp = temp -> rlink;
        }
    }
}

void backtraverse(struct node *head){

    struct node *temp;
    printf("The list : ");

    if(head == NULL){

        printf("The list is empty.\n");
    }else{

        temp = head;

        while(temp -> rlink!= NULL){

            temp = temp -> rlink;
        }

        /*New block of code*/
        while(temp != NULL){

            printf("%d   ", temp -> data);
            temp = temp -> llink;
        }
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
        new -> rlink = head;
        new -> llink = NULL; /*New line*/
        head -> llink = new; /*New line*/
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
            temp = temp -> rlink;
            count += 1;
        }

        new -> data = item;
        new -> rlink = temp;
        new -> llink = ptemp;/*New line*/
        ptemp -> rlink = new; 
        temp -> llink = new;/*New line*/
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
        new -> rlink = NULL;

        while(temp -> rlink != NULL){
            temp = temp -> rlink;
        }
        temp -> rlink = new;
        new -> llink = temp; /*Just add this line*/
        printf("Node inserted.\n");
    }
    return head;
}

struct node *del_first(struct node *head){

    struct node *temp;

    if(head == NULL){
        printf("The list is empty.\n");
    }else{

        temp = head;
        head = head -> rlink;
        head -> llink = NULL; /*Just add this line*/
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
            temp = temp -> rlink;
            count++;
        }

        prev -> rlink = temp -> rlink;
        temp -> rlink -> llink = prev; /*Just add this line*/
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
        while(temp -> rlink != NULL){
            prev = temp;
            temp = temp -> rlink;
        }
        prev -> rlink = NULL;
        free(temp);
        printf("Node deleted.\n");
    }
    return head;
}

struct node *reverse(struct node *head){

    struct node *prev = NULL, *next = NULL, *current = head;

    while(current != NULL){

        next = current -> rlink;
        current -> rlink = prev;
        current -> llink = next; /*Just add this line*/

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
            temp = temp -> rlink;
            count++;
        }

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

        while(current != NULL){

            next = current -> rlink;

            while(next != NULL){

                if(current -> data > next -> data){

                    temp = current -> data;
                    current -> data = next -> data;
                    next -> data = temp;
                }

                next = next -> rlink;
            }
            current = current -> rlink;
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
        
        printf("NO memory allocated.\n");
    }else{

        printf("Enter item : ");
        scanf("%d", &item);
        new -> data = item;
        new -> rlink = NULL;
        new -> llink = NULL;

        if(head0 == NULL){
            
            head0 = new;
        }
        else{

            temp = head0;

            while(temp -> rlink != NULL){

                temp = temp -> rlink;
            }
            temp -> rlink = new;
            new -> llink = temp;
        }
        printf("Node Inserted.\n");
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

        while(temp -> rlink != NULL){
            temp = temp -> rlink;
        }
        head0 -> llink = temp;
        temp -> rlink = head0;
        printf("Second list merged to First list.\n");
    }
    
    return head;
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

    struct node *new, *temp;
    int index = 0;

    while(index < size){

        new = malloc(sizeof(struct node));
        
        new -> data = arr[index++];
        new -> rlink = NULL;
        new -> llink = NULL;

        if(head == NULL){
            head = new;
        }
        else{
            temp = head;
            while(temp -> rlink != NULL){
                temp = temp -> rlink;
            }
            temp -> rlink = new;
            new -> llink = temp;
        }
    }
    printf("Converted successfully.\n");
    return head;
}

void main(){

    struct node *head, *head0;
    head = NULL;
    head0 = NULL;
    int c;

    while(1){

        printf("\n--- Menu ---\nEnter :\n1 -> Creation\n2 -> Traverse\n3 -> Back traverse\n4 -> Insertion at begining\n5 -> Insertion at in-between\n6 -> Insertion at last\n7 -> Delete first\n8 -> Delete in-between\n9 -> Delete last\n10 -> Reverse list\n11 -> Search\n12 -> Sort\n13 -> Create second list for merging to the main list\n14 -> Merge\n15 -> Convert array to Circular Linked List\n16 -> Exit\n");
        scanf("%d", &c);

        switch(c){

            case 1: head = creation(head);
            break;
            case 2: traverse(head);
            break;
            case 3: backtraverse(head);
            break;
            case 4: head = in_beg(head);
            break;
            case 5: head = in_bet(head);
            break;
            case 6: head = in_end(head);
            break;
            case 7: head = del_first(head);
            break;
            case 8: head = del_bet(head);
            break;
            case 9: head = del_last(head);
            break;
            case 10: head = reverse(head);
            break;
            case 11: search(head);
            break;
            case 12: head = sort(head);
            break;
            case 13: head0 = creation_sec(head0); /*Include this case if merging is included in the program*/
            break;
            case 14: head = merge(head,head0);
            break;
            case 15: head = arrtoslnk(head); /*Merges with the main list (at the back) if available*/
            break;
            case 16: printf("-- End of program --\n");
            exit(0);
            default: printf("Wrong Choice\n");
            break;
        }
    }
}