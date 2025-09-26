#include<stdio.h>
void linearsearch(int a[],int n,int targ)
{
  int i,c=0;
  for(i=0;i<n;i++)
   {
     if(a[i]==targ)
      {
        c=1;
        break;
      }
     else
       c=0;
     
   }
     if(c==1)
    printf("Element found at Index %d",i+1);
   else
    printf("Element not found");

}

void main()
{
  int n,t,i,a[100];
  printf("Enter no of ele");
  scanf("%d",&n);
  printf("Enter the elements");
  for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
   }
  printf("Enter the target ele");
  scanf("%d",&t);
  linearsearch(a,n,t);
  
}
