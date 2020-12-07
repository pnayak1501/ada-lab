#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>

int horspool(char text[],char pattern[])
{
int i,j,m,n,shift[300];
n=strlen(text);
m=strlen(pattern);
for(i=0;i<=n-1;i++)
{
 shift[text[i]]=m;
}
for(j=0;j<=m-2;j++)
{
 shift[pattern[j]]=m-1-j;
}
for(i=m-1;i<=n-1;i=i+shift[text[i]])
{
 j=0;
 while(pattern[m-1-j]==text[i-j]&&j<=m-1)
 {
 ++j;
 }
 if(j==m)
 {
 return 1;
 exit(0);
 }
}
return 0;
}

int main()
{
char text[300],pattern[20];
int ans;

printf("\nenter the text:\n");
gets(text);
printf("\nenter the pattern:\n");
gets(pattern);
ans=horspool(text,pattern);
if(ans==1)
{
 printf("\npattern found\n");
}
else
{
 printf("\npattern is not found\n");
}
return 0;
}


