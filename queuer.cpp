#include<iostream>
using namespace std;
int queue[100],n=100,front=-1,rear=-1;
void insert()
{
	int val;
	if(rear == n-1)
	cout<<"queue overflow"<<endl;
	else{
		if(front == -1)
		front = 0;
		cout<<"insert the element in queue :"<<endl;
		cin>>val;
		rear++;
		queue[rear] = val;
	}
}
void Delete()
{
	if(front == -1 || front>rear)
	{
		cout<<"Queue underflow";
	}
	else
	{
		cout<<"element deleted from queue is :"<<queue[front]<<endl;
		front++;
	}
}
void Display()
{
	if(front== -1){
		cout<<"queue is empty"<<endl;
	}
	else{
		cout<<"queue elements are: ";
		for(int i=front; i<=rear; i++)
		cout<<queue[i]<<" ";
		cout<<endl;
	}
	}
	
int main()
{
	int ch;
	cout<<"1) Insert element to queue"<<endl;
	cout<<"2) Delete element from queue"<<endl;
	cout<<"3) Display all the elements of queue"<<endl;
	cout<<"4) exit"<<endl;
	do{
		cout<<"enter your choice:"<<endl;
		cin>>ch;
		switch(ch){
			case 1:insert();
			break;
			case 2:Delete();
			break;
			case 3:Display();
			break;
			case 4:cout<<" Exit"<<endl;
			break;
			default:cout<<"invalid choice"<<endl;
		}
	}while(ch!=4);
	return 0;
}
