#include <stdio.h>
#define size 100

void inpoly(int poly[],int *deg)
{
    printf("Enter the degree:\n");
    scanf("%d",deg);
    for(int i=*deg;i>=0;i--)
    {
        printf("Enter the coeff:%d\n",i);
        scanf("%d",&poly[i]);
    }
}
int addpoly(int poly1[],int poly2[],int result[], int deg1,int deg2)
{
    int max=(deg1>deg2)?deg1:deg2;
    for(int i=0;i<=max;i++)
    {
        result[i]=0;
        if(i<=deg1)
          result[i]+=poly1[i];
         if(i<=deg2)
          result[i]+=poly2[i];
    
         
    }
    return max;
}
void disp(int poly[],int deg)
{
    
    for(int i=deg;i>=0;i--)
    {
       if(poly[i]!=0){
           printf("%dx^%d",poly[i],i);
           if(i!=0)
             printf(" + ");
       }
        
    }
    printf("\n");
}

void main() {
    int poly1[size],poly2[size],res[size];
    int deg1,deg2,degr;
    printf("Enter first poly:\n");
    inpoly(poly1,&deg1);
     printf("Enter second poly:\n");
    inpoly(poly2,&deg2);
    degr=addpoly(poly1,poly2,res,deg1,deg2);
    printf(" First poly:\n");
    disp(poly1,deg1);
    printf(" Second poly:\n");
    disp(poly2,deg2);
    printf("Result after add\n");
    disp(res,degr);
}
