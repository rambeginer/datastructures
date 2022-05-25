#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
Node *front=NULL;
Node *rear=NULL;
Node *temp;
void insert()
{
	int val;
	cout<<"insert the element in queue:"<<endl;
	cin>>val;
	if(rear==NULL){
		rear=new Node;
		rear->data=val;
		rear->next=NULL;
		front=rear;
	}
	else{
		temp=new Node;
		temp->data=val;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
}
void delet()
{
	temp=front;
	if(front==NULL)
	{
		cout<<"queue is underflow"<<endl;
		return;
	}
	else
	if(temp->next!=NULL){
		temp->next;
		cout<<" elements deleted from queue is"<<front->data<<endl;
		//free(front);
		front=NULL;
		rear=NULL;
	}
}
void Display()
{
	temp=front;
	if((front==NULL)&&(rear=NULL)){
		cout<<"queue is empty"<<endl;
		return;
	}
	cout<<"queue elements:";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
	int ch;
	cout<<"1)insert element to queue"<<endl;
	cout<<"2)delete element from queue"<<endl;
	cout<<"3)display all the elements of queue"<<endl;
	cout<<"4)exit"<<endl;
	do
	{
		cout<<"enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
		
		case 1:
			insert();
			break;
		case 2:
			delet();
			break;
		case 3:
			display();
			break;
		case 4:
		    cout<<"exit"<<endl;
			break;
		default:cout<<"invlid choice"<<endl;
		
			}	
				
	}while(ch!=4);
	return 0;
}
