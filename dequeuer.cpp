#include<iostream>
using namespace std;
int array[5];
int front=-1,rear=-1,size=5;
void insertfront(int key)
{
	if((front == 0 && rear==size-1) || (front==rear+1))
	{
		cout<<"queue overflow \n";
	}
	if (front == -1)
	{
		front =0;
		rear =0;
	}
	else if(front == 0)
	front=size-1;
	front=front-1;
	array[front]=key;
}void insertrear(int key)
{
	if((front == 0 && rear == size-1) || (front==rear+1))
	{
		cout<<"queue overflow \n";
	}
	if(front == -1){
		front=0;
		rear=0;
	}
	else if(rear == size-1)
	rear=0;
	else
	rear=rear+1;
	array[rear]=key;
}
void deletefront()
{
	if(front==-1){
		cout<<"dequeue is empty"<<"\n";
	}
	cout<<array[front]<<"is deleted!!!";
	if(front==rear)
	{
		front =-1;
		rear=-1;
	}
	else if(front == size-1)
	front = 0;
	else
	front=front+1;
}
void deleterear()
{
	if(front==-1){
		cout<<"dequeue is empty"<<"\n";
	}
	cout<<array[rear]<<"is deleted!!!";
	if(front == rear)
	{
		front =-1;
		rear=-1;
	}
	else if(rear ==0)
	rear=size-1;
	else
	rear=rear-1;	
}
int getFront()
{
	if(front==-1)
	{
	cout<<"dequeue is empty"<<"\n";
}
return array[front];
}
int getrear()
{
	if(front==-1){
		cout<<"dequeue is empty"<<"\n";
	}
	return array[rear];
}
void display()
{
	int f=front,r=rear;
	if(front==-1){
		cout<<"queue is empty"<<endl;
	
	return;
	}
	cout<<"queue elements are:\n";
	if(f<=r){
		while (f<=r){
			cout<<array[f]<<" ";
			f++;
		}
	}
	else{
	while(f<=size-1){
		cout<<array[f]<<" ";
		f++;
	}
	f=0;
	while(f<=r){
		cout<<array[f]<<" ";
		f++;
	}
}
}

int main()
{
	int ch,val;
	cout<<"1)insert an element at the rear"<<"\n";
	cout<<"2)insert an element at the front"<<"\n";
	cout<<"3)Delete an element at the rear"<<"\n";
	cout<<"4)Delete an element at the front"<<"\n";
	cout<<"5) get element at the front end"<<"\n";
	cout<<"6) get element at the rear end"<<"\n";
	cout<<"7)Display queue elements"<<"\n";
	cout<<"8)Quit"<<"\n";
	do
	{
		cout<<"Enter choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Input element for insertion at the beginning(rear): "<<endl;
                   cin>>val;
                   insertrear(val);
                   break;
            case 2:cout<<"Input element for insertion at the last(front): "<<endl;
                   cin>>val;
                   insertrear(val);
                   break;
			case 3:deleterear();
			       break;
			case 4:deletefront();
			       break;
			case 5:cout<<"\n"<<getFront();
			       cout<<"\n";
				   break;
			case 6:cout<<"\n"<<getRear();
			       cout<<"\n";
				   break;
			case 7:display();
			cout<<"\n";
			break;
			case 8:cout<<"\n Program end!!!";
			       break;
			default:cout<<"Incorrect!"<<"\n";	   	            
                   
		}
	}while(ch !=8);
	return 0;
}
