#include<stdio.h>
#include<conio.h>

void build_heap(int a[],int n)
{
int p;
for(p=(n-1)/2;p>=0;p--)
{
 heapify(a,n,p);
}
}

void heapify(int a[],int n,int p)
{
int item,c;
item=a[p];
c=2*p+1;
while(c<=n-1)
{
 if(c+1<=n-1)
 {
 if(a[c]<a[c+1])
 {
 c=c+1;
 }
 }
 if(item<a[c])
 {
 a[p]=a[c];
 p=c;
 c=2*p+1;
 }
 else
 {
 break;
 }
}
a[p]=item;
}

void heap_sort(int a[],int n)
{
int i,temp;
for(i=n-1;i>0;i--)
{
 temp=a[0];
 a[0]=a[i];
 a[i]=temp;
 build_heap(a,i);
}
}

int main()
{
int a[10],i,n;
printf("\nenter the no. of elements:\t");
scanf("%d",&n);
printf("\nenter the elements:\n");
for(i=0;i<=n-1;i++)
{
 scanf("%d",&a[i]);
}
build_heap(a,n);
heap_sort(a,n);
printf("\nthe sorted array is:\n");
for(i=0;i<=n-1;i++)
{
 printf("%d\t",a[i]);
}
return 0;
}

