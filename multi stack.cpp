#include <iostream>
using namespace std;

#define MAX 10

int stack[MAX], topA = -1, topB = MAX;

void push_stackA(int val)
{

if(topA == topB-1)
cout<<"stack is overflow"<<"\n"; else
{

topA+=1;//topA=topA+1

stack[topA] = val;

}

}
void pop_stackA()
{
int val;

if(topA == -1)

{
printf("\n STACK UNDERFLOW");
}
else
{
cout<<"element to be poped from the stack is "<<stack[topA];
topA--;
}
}

void display_stackA()
{
int i;

if(topA == -1){
cout<<"stack is empty"<<"\n";
}
else
{
for(i = topA;i >= 0;i--)
cout<<stack[i]<<" ";
}
}

void push_stackB(int val)
{
if(topB-1 == topA)
cout<<"STACK OVERFLOW"<<"\n";
else
{
topB-=1;
stack[topB] = val;
}
}

void pop_stackB()
{
int val;
if(topB == MAX)
{
cout<<"\n STACK UNDERFLOW"<<"\n";
}
else
{
cout<<"The poped element is "<<stack[topB]<<"\n";
topB++;
}
}
void display_stackB()
{
int i;
if(topB == MAX)
cout <<"\n Empty STACK B"<<"\n";
else
{
for(i = topB; i < MAX;i++)

cout<<stack[i]<<"\n";
}
}
int main()
{
int option, val;
do
{
cout<<"\n -----Menu----- ";
printf("\n Enter 1 to PUSH a element into STACK A");
printf("\n Enter 2 to PUSH a element into STACK B");
printf("\n Enter 3 to POP a element from STACK A");
printf("\n Enter 4 to POP a element from STACK B");
printf("\n Enter 5 to display the STACK A");
printf("\n Enter 6 to display the STACK B");
printf("\n Press 7 to exit");
printf("\n Enter your choice: ");
scanf("%d",&option);
switch(option)
{
case 1:
cout<<"\n Enter the value to PUSH on STACK A:";
cin>>val;
push_stackB(val);
break;


case 2:
cout<<"\n Enter the value to PUSH on STACK B:";
cin>>val;
push_stackB(val);
break;
case 3:
cout<<"\n The value POPPED from STACK A" <<val;
pop_stackA();
break;
case 4:
cout<<"\n The value POPPED from STACK B" <<val;
pop_stackB();
break;
case 5:
cout<<"\n The STACK A elements are :\n";
display_stackA();
break;
case 6:
cout<<"\n The STACK B elements are :\n";
display_stackB();
break;
}
}while(option != 7);
return 0;
}

