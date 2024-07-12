#include<stdio.h>
#include<stdlib.h>
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb])e++;
while(x[f]>x[lb])f--;

if(e<f)
{
//swap the values at e and f
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[f];
x[f]=x[lb];
x[lb]=g;
}
}
return f;
}

void quickSort(int *x,int lowerBound,int upperBound)
{
//FirstStage is to Push lowerBound and upperBound on Stack
int *lbStack,*ubStack,top,size,pp,lb,ub;
size=(upperBound-lowerBound)+1;
//right now we are assuming that malloc will not fail to allocate memory for stack
lbStack=(int *)malloc(sizeof(int)*size);
ubStack=(int *)malloc(sizeof(int)*size);
top=size;
top--;
lbStack[top]=lowerBound;
ubStack[top]=upperBound;

//SecondStage is run the loop untill we have data in Stack or you can say unless stack is empty run the loop

while(top!=size)
{
//ThirdStage is pop the data from stack
lb=lbStack[top];
ub=ubStack[top];
top++;
pp=findPartitionPoint(x,lb,ub);

if(pp+1<ub)
{
//push data on stack
top--;
lbStack[top]=pp+1;
ubStack[top]=ub;
}
if(lb<pp-1)
{
//push data on stack
top--;
lbStack[top]=lb;
ubStack[top]=pp-1;
}
}
free(lbStack);
free(ubStack);
}

int main()
{
int req,*x,y;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement \n");
return 0;
}

x=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
quickSort(x,0,req-1);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}

