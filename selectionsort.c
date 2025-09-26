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
void selectionsort(int a[],int n)
{
 int p,small,ind,temp;
 for(p=0;p<n-1;p++)
  {
    small=a[p];
    ind=p;
    for(int c=p+1;c<n;c++)
     {
       if(a[c]<small)
     { 
        small=a[c];
        ind=c;
      }
     }
  temp=a[ind];
  a[ind]=a[p];
  a[p]=temp;
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
  selectionsort(a,n);
  print(a,n);
}
  
