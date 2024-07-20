#include<stdio.h>
int main()
{
int x[8] = {5,89,80,47,80,23,100,91};
int i,selectedIndex,j,temp;
for(i=0;i<7;i++)
{
printf("%d\n", x[i]);
}

while(selectedIndex<(8-1))
{
j=selectedIndex+1;
while(j<=(8-1))
{
if(x[selectedIndex]>x[j])
{
temp=x[selectedIndex];
x[selectedIndex]=x[j];
x[j]=temp;
}
j++;
}
selectedIndex++;
}

printf("After Selection Sort Algorithm\n");

for(i=0;i<=7;i++)
{
printf("%d\n", x[i]);
}
return 0;
}