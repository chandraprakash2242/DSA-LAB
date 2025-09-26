#include<stdio.h>
void read(int a[],int n)
{
  int i;
  printf("Enter the elements to be sorted:");
  for(i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }
}
void insertionsort(int a[],int n)
{
 int p,i,key;
 for(p=1;p<n;p++)
  {
    key=a[p];
    i=p-1;
    while(i>=0&&a[i]>key)
     {
       a[i+1]=a[i];
       i--;
     }
     a[i+1]=key;
 }
}

void print(int a[],int n)
{
  int i;
  printf("The sorted array is :");
  for(i=0;i<n;i++)
   printf("%d ",a[i]);
   
}
void main()
{
  int n;
  printf("Enter the limit:");
  scanf("%d",&n);
  int a[n];
  read(a,n);
  insertionsort(a,n);
  print(a,n);
}
