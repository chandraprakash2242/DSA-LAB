#include<stdio.h>
#define MAX 100
typedef struct
{
  int row;
  int col;
  int val;
}sparse;
int readmat(int a[MAX][MAX],int m,int n)
{
 int i,j,c=0;
 printf("Enter elements :");
 for(i=0;i<m;i++)
 {
  
  for(j=0;j<n;j++)
 {
   scanf("%d",&a[i][j]);
   if(a[i][j]!=0)
   c++;
 }
 }
 return c;
}
void main()
{
  int m,n,nz;
int i,j;
  printf("Enter the size of row and col: ");
  scanf("%d%d",&m,&n);
  int a[MAX][MAX];
  nz=readmat(a,m,n);
  for(i=0; i<m; i++)
 {
        for (j=0; j<n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
  sparse sa[nz];
  sa[0].row=m;
  sa[0].col=n;
  sa[0].val=nz;
  int k=1;
  for(i=0;i<m;i++)
  {
   for(j=0;j<n;j++)
   if(a[i][j]!=0)
   {
      sa[k].row=i;
      sa[k].col=j;
      sa[k].val=a[i][j];
      k++;
   }
 }
      printf("\nSparse Matrix Representation");
       printf("\n\tROW COLOUMN VALUE ");
        for (i = 0; i <= nz; i++) 
    {
        printf("\n\t%d\t%d\t%d",sa[i].row,sa[i].col,sa[i].val);

    }
}
