/*
This program contains the following operations on Stack represented by an array :
1. Isfull()
2. Isempty()
3. Traverse
4. Push()
5. Pop()
6. Peek()
7. Empty stack (reset)
*/

#include <stdio.h>
#include <stdlib.h>

struct stack{

    int top;
    int items[];
};

void isfull(int max, struct stack *rstack){
    
    if(rstack -> top == max - 1){

        printf("Stack is full.\n");
    }
    else{

        printf("Stack is not full.\n");
    }
}

void isempty(struct stack *rstack){

    if(rstack -> top == -1){

        printf("Stack is empty.\n");
    }
    else{

        printf("Stack is not empty.\n");
    }
}

void traverse(struct stack *rstack){

    if(rstack -> top == -1){
        printf("Empty stack.\n");
    }
    else{

        printf("The stack is :\n\n");

        for(int i = rstack -> top; i >= 0; i--){
        
            printf("%d\n", rstack -> items[i]);
        }
    }
}

struct stack *push(int max, struct stack *rstack){

    int item;

    printf("Enter item : ");
    scanf("%d", &item);

    if(rstack -> top == max - 1){

        printf("Overflow.\n");
    }else{

        rstack -> top++;
        rstack -> items[rstack -> top] = item;
        printf("Item pushed.\n");
    }
    return rstack;
}

struct stack *pop(struct stack *rstack){

    if(rstack -> top == -1){

        printf("Underflow.\n");
    }
    else{

        printf("The itme popped is %d.\n", rstack -> items[rstack -> top]);
        rstack -> top--;
    }
    return rstack;
}

void peek(struct stack *rstack){

    if( rstack -> top == -1){
        printf("Empty stack.\n");
    }
    else{
        printf("The value of top is %d.\n", rstack -> items[rstack -> top]);
    }
}

struct stack *empty(struct stack *rstack){

    rstack -> top = -1;
    printf("Stack emptied.\n");
    return rstack;
}
 
void main(){

    struct stack *rstack;
    int c, max;

    printf("Enter the size of the stack : ");
    scanf("%d", &max);
    
    rstack = malloc(sizeof(struct stack));
    
    rstack -> items[max];
    rstack -> top = -1;

    while(1){

        printf("\n--- Menu ---\nEnter :\n1 -> Check Isfull()\n2 -> Check Isempty()\n3 -> Traverse\n4 -> Push item\n5 -> Pop item\n6 -> Peek()\n7 -> Empty Stack\n8 -> Exit\n");
        scanf("%d", &c);

        switch(c){

            case 1: isfull(max,rstack);
            break;
            case 2: isempty(rstack);
            break;
            case 3: traverse(rstack);
            break;
            case 4: rstack = push(max,rstack);
            break;
            case 5: rstack = pop(rstack);
            break;
            case 6: peek(rstack);
            break;
            case 7: rstack = empty(rstack);
            break;
            case 8: printf("-- End of program --\n");
            exit(0);
            default: printf("Wrong choice.\n");
            break;
        }
    }
}