#include<stdio.h>
#define size 2
int top=0;
int s[size];
int isempty()
{
  if(top==0)
    return (1);
  else
    return(0);
}
int isfull()
{
 if(top>=size)
   return(1);
 else
   return(0);
}
void push(int item)
{
  if(isfull())
     printf("Stack Full");
  else
    s[top++]=item;
}
int pop()
{
  if(isempty())
     printf("Stack is Empty");
  else
     return(s[--top]);
}
void main()
{
  int choice,ele;
   do
    {
      printf("\n 1.push\n 2.pop\n 3.isempty\n 4.isfull\n 5.Exit\n ");
      printf("Enter your choice");
      scanf("%d",&choice);
      switch(choice)
       {
         case 1:if(!isfull())
               {
                 printf("Enter the element :");
                 scanf("%d",&ele);
                 push(ele);
               }
               break;
        case 2:if(isempty())
                 printf("Stack is empty:");
               else
                 printf("\n item poped=%d",pop());

               break;
    
        case 3:if(isempty())
                 printf("yes");
               else
                 printf("no");

               break;

        case 4:if(isfull())
                 printf("Yes");
               else
                 printf("No");
               break;
        case 5:printf("Exiting");
               break;
        default:printf("Invalid Choice");
        }
    }
     while(choice!=5);
}
    
