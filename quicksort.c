#include<stdio.h>
void swap(int *a, int *b)
{
 int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
int partition(int a[],int left,int right)
{
 int key=a[left];
 int i=left+1,j=right;
 do
  {
    while(i<right&&a[i]<key)
       i++;
    while(j>left&&a[j]>key)
       j--;
    if(i<j)
       swap(&a[i],&a[j]);
  }
   while(i<j);
    {
      swap(&a[left],&a[j]);
      return(j);
    }
}
void quicksort(int a[],int left,int right)
{
  if(left<right)
   {
     int pos=partition(a,left,right);
      quicksort(a,left,pos-1);
      quicksort(a,pos+1,right);
  }
}
void read(int a[],int n)
{
 int i;
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
}
void print(int a[],int n)
{
 int i;
  for(i=0;i<n;i++)
     printf("%d ",a[i]);
}
void main()
{
  int left,right,n;
  printf("Enter the limit");
  scanf("%d",&n);
  left=0;
  right=n-1;
  int a[n];
  printf("Enter the elements :");
  read(a,n);
  quicksort(a,left,right);
  printf("Sorted Array :");
  print(a,n);
}
