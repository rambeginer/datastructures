#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
Node *top=NULL;
void push(int val)
{
	Node *newnode;
	newnode=new Node;
	newnode->data=val;
	newnode->next=top;
	top=newnode;
}
void pop()
{
	if(top==NULL)
	cout<<"stack underflow"<<endl;
	else
	{
		cout<<"the popped element is"<<top->data<<endl;
		top=top->next;
	}
}
void display()
{
	Node *ptr;
	if(top==NULL)
	cout<<"stack is empty";
	else
	{
		ptr=top;
		cout<<"stack elements are:";
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
	}
	cout<<endl;
}
int main()
{
	int ch,val;
	cout<<"1)push in stack"<<endl;
	cout<<"2)pop from stack"<<endl;
	cout<<"3)display stack"<<endl;
	cout<<"4)Exit"<<endl;
	do{
		cout<<"enter choice:"<<endl;
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"enter value to pushed"<<endl;
				cin>>val;
				push(val);
				break;
			}
			case 2:{
				pop();
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:{
				cout<<"exit"<<endl;
				break;
			}
			default:{
				cout<<"invalid option";
				break;
			}
		}
	}while(ch!=4);
	return 0;
}
