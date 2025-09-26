#include<stdio.h>
#include<string.h>

#define size 100
char stack[size];
int top=-1;

void push(char c)
{
  if(top==size-1)
    printf("Stack is full");
  else
   {
     top++;
     stack[top]=c;
    }
    
}
int pop()
{
  if(top==-1)
{
     printf("Stack is Empty");
     return '\0';
 }
  else
   {
    int temp=stack[top];
    top--;
    return temp;
   }
}

void reverse(char str[100])
{
int i,l=0;
while(str[l]!='\0')
{
 push(str[l]);
 l++;
}
for(i=0;i<l;i++)
{
 str[i]=pop();
 
}
  str[l]='\0';
 

}
void main()
{
  char str[size];
  printf("Enter a String :");
  scanf("%s",str);
  reverse(str);
  printf("Reversed String : %s",str);
}
