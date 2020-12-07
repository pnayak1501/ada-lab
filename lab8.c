#include<stdio.h>
int i,j,n,w,flag,t;
int a[10][10],indeg[10],check[10],tp[10];

int indegree(int v)
{
        int i,in_deg = 0;
        for(i=1; i<=n; i++)
                if(a[i][v] == 1)
                        in_deg++;
        return in_deg;
}

int main()
{
printf("\nenter the no of nodes:\t");
scanf("%d",&n);
printf("\nenter the adjacency matrix:\n");
for(i=1;i<=n;i++)
{
 for(j=1;j<=n;j++)
 {
 scanf("%d",&a[i][j]);
 }
}

for(i=1;i<=n;i++)
{
	indeg[i]=indegree(i);
	check[i]=0;
}
t=0;
while(1)
{ flag=0;
	for(i=1;i<=n;i++)
	{
		if(check[i]==0&&indeg[i]==0)
		{
			w=i;		
			flag=1;
			break;
		}
	}
	if(flag==0)
	break;
	tp[t++]=w;
	check[w]=1;
	for(i=1;i<=n;i++)
	{
		if(a[w][i]==1)
		indeg[i]--;
	}	
}
if(t<n)
	printf("No topological sequence");
else
{
	printf("The topological sequence is:");
	for(i=0;i<t;i++)
	printf("%d",tp[i]);
}

return 0;
}
