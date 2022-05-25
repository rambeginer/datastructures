#include<iostream>
using namespace std;
class node
{
	public:
	int info;
	node *prev;
	node *next;
};
class list:public node
{
	node *first,*last;
	public:
	list()
	{
		first=NULL;
		last=NULL;
	}
	void create();
	void insert();
	void delet();
	void display();
	void search();
	void sort();
	void reverse();
};
void list::create()
{
	node *temp;
	temp=new node;
	int n;
	cout<<"\n enter an element:";
	cin>>n;
	temp->info=n;
	temp->prev=NULL;
	temp->next=NULL;
	if(first==NULL)
	{
		first=temp;
		last=temp;
	}
	else
	{
		last->next=temp;
		temp->prev=last;
		last=temp;
	}
}
void list::insert()
{
	node *prevnode,*curnode;
	prev=NULL;
	curnode=first;
	int count=1,pos,ch,n;
	node *temp;
	temp=new node;
	cout<<"\n enter an element:";
	cin>>n;
	temp->prev=NULL;
	temp->next=NULL;
	cout<<"\n Insert as\n 1:firstnode \n 2:lastnode \n 3 in between first&last nodes";
	cout<<"\n enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			temp->next=first;
			first->prev=temp;
			first=temp;
			break;
		case 2:
			last->next=temp;
			temp->prev=last;
			last=temp;
			break;
		case 3:
			cout<<"\n enter the position to insert:";
			cin>>pos;
			while(count!=pos)
			{
				prevnode=curnode;
				curnode=curnode->next;
				count++;
			}
			if(count==pos)
			{
				prevnode->next=temp;
				temp->next=curnode;
				curnode->prev=temp;
			}
			else
			cout<<"\n Not able to insert";
			break;
	}
}
void list::delet()
{
	node *prevnode,*curnode=first;
	prevnode=NULL;
	int count=1,pos,ch;
	cout<<"\n delet \n 1:firstnode \n 2:lastnode\n 3:in between first&last nodes";
	cout<<"\n enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
		if(first!=NULL)
		{
			cout<<"\n delted element is "<<first->info;
			first=first->next;
			first->prev=NULL;
		}
		else
		cout<<"\n not able to delete";
		break;
		
		case 2:
		while(cur!=last)
		{
			prevnode=curnode;
			curnode=curnode->next;
			curnode->prev=NULL;
		}
       if(cur==last)
	   {
	   	cout<<"\n delted element is:"<<curnode->info;
	   	prevnode->next=NULL;
	   	prevnode->prev=NULL;
	   	last=prevnode;
		   }
		 else
		 cout<<"\n not able to delete";
		 break;
		case 3:
		cout<<"\n enter the position of deletion:";
		cin>>pos;
		while(count!=pos)
		{
			prevnode=curnode;
			curnode=curnode->next;
			count++;
		}
		if(count==pos)
		{
			cout<<"\n deleted element is:"<<curnode->info;
			prevnode->next=curnode->next;
		}
		else
		cout<<"\n not able to delete";
		break;
	}
}
void list::displayforward()
{
	node *temp;
	temp=first;
	if(temp==NULL)
	{
		cout<<"\n list is empty";
	}
	while(temp!=NULL)
	{
		cout<<temp->info;
		cout<<"<---->";
		temp=temp->next;
	}
	cout<<"NULL";
}
void list::displayforward()
{
	node *temp;
	temp=last;
	if(temp==NULL)
	{
		cout<<"\n list is empty";
	}
	while(temp!=NULL)
	{
		cout<<temp->info;
		cout<<"<--->";
		temp=temp->prev;
	}
	cout<<"NULL";
}
void my_swap(node *node1,node *node2)
{
	int temp=node1->info;
	node1->info=node2->info;
	node2->info=temp;
}
void list::sort()
{
	int swapped;
	do
	{
		swapped=1;
		if(first->info>first->next->info)
		{
			my_swap(first,first->next);
			swapped=1;
		}
		first=first->next;
		if(last==first)swapped=0;
	}while(swapped);
}
void list::search()
{
	int value,pos=0;
	bool flag=false;
	if(first==NULL)
	{
		cout<<"list is empty";
		return;
	}
	cout<<"enter the value to be searched:";
	cin>>value;
	node *temp;
	temp=first;
	while(temp!=NULL)
	{
		pos++;
		if(temp->info==value)
		{
			flag=true;
			cout<<"element"<<value<<"is found at"<<pos<<"position";
			retrun;
		}
		temp=temp->next;
	}
	if(flag==false)
	{
		cout<<"element"<<value<<"not fount in the list";
	}
}
void list::reverse()
{
	node *temp;
	temp=new node;
	temp->next=NULL;
	node *prev;
	prev=new node;
	prev->next=NULL;
	while(first!=NULL)
	{
		temp=first->next;
		first->next=prev;
		prev=first;
		first=temp;
	}
	first=prev;
}
int main()
{
	list obj;
	int ch;
	while(1)
	{
		cout<<"\n **** Menu ****";
		cout<<"\n 1:create \n 2:insert \n 3:delete \n 4:display \n 5:sort \n 6:search \n 7:reverse \n 8:exit";
		cout<<"\n eneter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1:
				   obj.create();
				   break;
		    case 2:
		    	
		    		obj.insert();
		    		break;
				
			case 3:
				
					obj.delet();
					break;
				
			case 4:
			    
			    	obj.display();
			    	break;
			case 5:
				    obj.bubble_sort();
				    break;
			case 6:
				    obj.search();
				    break;
			case 7:
				    obj.reverse();
				    break;
						
			case 8:
				
					cout<<"exit";
					break;
				
			default:
			
				cout<<"invalid option"<<"\n";
				
		}
   }
	return 0;				
}

