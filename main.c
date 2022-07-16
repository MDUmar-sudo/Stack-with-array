#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack ss;

struct Stack{
    int size;
    int top;
    int *arr;
};



void push();
void pop();
void display();
void peek();


int main()
{
    ss *s = (ss *)malloc(sizeof(ss)) ;
    s->size=100;
    s->top=-1;
    s->arr = (int *)malloc(s->size*sizeof(int));
    int choice;
    printf("-----------------------------\n");
    printf("STACKING [LIFO] USING ARRAYS\n");
    printf("-----------------------------\n");

  do{
    printf("____________________________");
    printf("\nSTACK SORT OPERATIONS\n(1)PUSH\n(2)POP\n(3)DISPLAY\n(4)PEEK\n(5)EXIT\n");
    printf("____________________________");

    printf("\nENTER YOUR CHOICE :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1: push(s);
             break;

    case 2:pop(s);
            break;

    case 3: display(s);
             break;

    case 4: peek(s);
             break;

    case 5: printf("\nEXIT");

    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");

    }
  }while(choice!=0);

  getch();
  return 0;

}

//return stack status: Empty or Not

int isEmpty(ss *s){

    if(s->top==-1) return 1;

    return 0;
}

//return stack status: Full or Not

int isFull(ss *s){

    if(s->top==s->size-1) return 1;

    return 0;
}

//push() function append an element at the top most position in the stack

void push(ss *s)
{
    if(isFull(s))
    {
        printf("\nSTACK OVERFLOW!!!\n");
    }
    else
    {
        int x;
        printf("\nENTER AN ELEMENT TO PUSH IN STACK: ");
        scanf("%d",&x);
        s->arr[++s->top]=x;
    }
    printf("\nPUSHED ELEMENT IS THE STACK :%d\n",s->arr[s->top]);
    printf("\ntop=%d\n",s->top);

}

//pop() function deletes the top most element in the stack

void pop(ss *s)
{
    if(isEmpty(s))
    {
        printf("\nSTACK UNDERFLOW!!!\n");
    }
    else
    {
        int item;
        item = s->arr[s->top--];
        printf("\nPOPPED ELEMENT FROM THE STACK :%d\n",item);

    }
}

//display() function print all the elements in the stack

void display(ss *s)
{
    if(isEmpty(s))
   {
     printf("\nSTACK UNDERFLOW!!!\n");
   }


    else
    {
        printf("\nELEMENTS IN THE STACK:");
        for(int i=s->top;i>=0;i--)
        {
            printf("\n%d",s->arr[i]);

        }
        printf("\n");
    }

}

//peek() and top() function are same both returns top most element of the stack

void peek(ss *s)
{
    if(isEmpty(s))
    {
        printf("\nSTACK UNDERFLOW!!!\n");
    }

    else
    {
        printf("\nTOP ELEMENT OF THE STACK :%d\n",s->arr[s->top]);
    }
}
