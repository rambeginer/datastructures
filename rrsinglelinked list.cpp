#include<iostream>
using namespace std;
class node
{
	public:
		int info;
		node * next;
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
		void bubble_sort();
		void reverse();
};
void list::create()
{
	node *temp;
	temp=new node;
	int n;
	cout<<"\n Enter an Element:";
	cin>>n;
	temp->info=n;
	temp->next=NULL;
	if(first==NULL)
	{
		first=last=temp;
	}
	else
	{
		last->next=temp;
		last=temp;
	}
}
void list::insert()	
{
	node *prev,*cur;
	prev=NULL;
	cur=first;
	int count=1,pos,ch,n;
	node *temp;
	temp=new node;
	cout<<"\n Enter an Element:";
	cin>>n;
	temp->info=n;
	temp->next=NULL;
	cout<<"\n insert as\n 1:firstnode\n 2:lastnode\n 3: in between first and last nodes";
	cout<<"\n enter your choice :";
	cin>>ch;
	switch(ch)
	{
		case 1:
		{
			temp->next=first;
			first=temp;
			break;
		
		}
		case 2:
			{
				last->next=temp;
				last=temp;
				break;
			}
		case 3:
		{
			cout<<"\n enter the position to insert:";
			cin>>pos;
			while(count!=pos)
			{
				prev=cur;
				cur=cur->next;
				count++;
			}
		    if(count==pos)
			{
				prev->next=temp;
				temp->next=cur;
			}
			else
				cout<<"\n Not able to insert";
				break;		
			}	
	}
}
void list::delet()
{
	node *prev,*cur=first;
	prev=NULL;
	int count=1,pos,ch;
	cout<<"\n delete \n 1:firstnode \n 2:lastnode \n 3:in between first and last nodes";
	cout<<"\n enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
		{	
			if(first!=last)
			{
				cout<<"\n deleted element is:"<<first->info;
				first=first->next;
			}
			else
			cout<<"\n not able to delete";
			break;	
    	}
    	case 2:
    	{
    		while(cur!=last)
    		{
    			prev=cur;
    			cur=cur->next;
			}
			if(cur==last)
			{
				cout<<"\deleted element is:"<<cur->info;
				prev->next=NULL;
				last=prev;
		   }
		   else
		       cout<<"\n not able to delete";
		       break;
		       
		}
			case 3:
		{
			cout<<"\n enter the position of delet:";
			cin>>pos;
			while(count!=pos)
			{
				prev=cur;
				cur=cur->next;
				count++;
			}
		    if(count==pos)
			{
			     cout<<"\n delted element is:"<<cur->info;
			     prev->next=cur->next;
			}
			else
				cout<<"\n Not able to delete";
				break;		
		}	
	}
}
void list :: display()
{
	node *temp;
	temp=first;
	if(temp==NULL)
	{
		cout<<"\n List is empty";
	}
	while(temp!=NULL)
	{
		cout<<temp->info;
		cout<<"-->";
		temp=temp->next;
	}
	cout<<"NULL";
}
void list::bubble_sort()
{
	node *tnode,*tlast;
	tnode=first;
	tlast=last;
	int count=0;
	while(tnode!=NULL)
	{
		count++;
		tnode=tnode->next;
	}
	tnode=first;
	for(int i=1;i<count;i++)
	{
		tnode=first;
		for(int j=0;j<=count-i-1;j++)
		{
			if(tnode->info>tnode->next->info)
			{
				int temp=tnode->info;
				tnode->info=tnode->next->info;
				tnode->next->info=temp;
			}
			if(tlast==tnode->next)
			{
				tlast=tnode;
			}
			else
			tnode=tnode->next;
		}
	}
	
	
}
void list::search()
{
	int value,pos=0;
	int flag=0;
	if(first==NULL)
	{
		cout<<"list is empty";
		return;
	}
	cout<<"enter the value o be searched:";
	cin>>value;
	node *temp;
	temp=first;
	while(temp!=NULL)
	{
		pos++;
		if(temp->info==value)
		{
			flag=1;
			cout<<"element"<<value<<"is found at"<<pos<<"position";
			return;
		}
		temp=temp->next;
	}
	if(flag==0)
	{
		cout<<"element"<<value<<"not found in the list";
	}
}
void list::reverse()
{
	node *current=first;
	node *prev=NULL,*next=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
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
