#include<stdio.h>
void read(int a[],int n)
{
 int i;
  printf("Enter the nos to be sorted");
  
  for(i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }
}
void sort(int a[],int n)
{
 int p,c,temp;
  for(p=1;p<n;p++)
    for(c=0;c<n-p;c++)
     { 
      if(a[c]>a[c+1])
       {
         temp=a[c];
         a[c]=a[c+1];
         a[c+1]=temp;
       }
     }
}
void print(int a[],int n)
{
 int i;
 printf("\n Sorted array");
 for(i=0;i<n;i++)
  printf(" \n %d",a[i]);
}
void main()
{
  int n,a[100];
  printf("Enter the Limit");
  scanf("%d",&n);
  read(a,n);
  sort(a,n);
  print(a,n);
}
 
