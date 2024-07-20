#include<stdio.h>
int main()
{
int x[8] = {5,89,13,47,80,23,100,91};
int i,j,k,temp;
for(i=0;i<=7;i++)
{
printf("%d\n", x[i]);
}

j=8-1;
k;
while(j>0)
{
k=0;
while(k<j)
{
if(x[k]>x[k+1])
{
temp=x[k];
x[k]=x[k+1];
x[k+1]=temp;
}
k++;
}
j--;
}

printf("After Bubble Sort Algorithm\n");

for(i=0;i<=7;i++)
{
printf("%d\n", x[i]);
}


return 0;
}