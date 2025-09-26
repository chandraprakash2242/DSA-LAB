#include<stdio.h>
#include<ctype.h>
#define size 100
int top=-1;
char s[size];

void push(char c)
{
  if(top<size-1)
{

   
    s[++top]=c;
}     
  else
    printf(" Stack Full ");

}
char pop()
{
  if(top==-1)
    {
   printf("Stack is Empty");
     return '\0';
}
  else
     return s[top--];
}
int precedence(char c)
{
  switch(c)
{
  case'+': 
  case'-': return 1;
  case'*': 
  case'/': return 2;
  case'^': return 3;
  case'(': return 0;
}
}
void main()
{
  int i=0,j=0;
  char infix[100],postfix[100];
  char x,c;
  printf("Enter the infix exp :");
  scanf("%[^\n]",infix);
  while(infix[i]!='\0')
   {
     c=infix[i];
     if(c=='(')
      {
        push(c);
       }
     else
         if(isalnum(c))
       {
          postfix[j++]=c;
       }
     else
         if(c==')')
       {
         while((x=pop())!='(' && x!='\0')
          {
             postfix[j++]=x;
          }
      }
     else
       {
        while(top!=-1&&(precedence(s[top])>=precedence(c)))
             postfix[j++]=pop();
             push(c);
        }
       i++;
}
while(top!=-1)

    postfix[j++]=pop();
    postfix[j]='\0';
    printf("\n Postfix Expression :%s ",postfix);

}


        
              
