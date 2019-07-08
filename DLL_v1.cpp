#include"bits/stdc++.h"
using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};
struct node *head=NULL;

void insertbeg(int data)
{
	node *temp= new node();
	temp->data = data;
	temp->next = head;
	temp->prev = NULL;
	head = temp;
	return;
}

void insertmid(int data,int pos)
{

	if(pos==1)
	{
		insertbeg(data);
		return;
	}

	node *temp = new node();
	temp->data = data;

	node *p = head;
	for(int i=1;i<pos-1;i++)
	{
		p = p->next;
	}
	temp->next = p->next;
	p->next = temp;
	temp->prev = p;
	p = p->next;
	p->prev = temp;

	return;
}

void insertend(int data)
{
	if(head==NULL)
	{
		insertbeg(data);
		return;
	}
	node *temp = new node();
	temp->data = data;
	temp->next = NULL;

	node *p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}

	p->next = temp;
	temp->prev = p;

	return;
}

void insert()
{
	int ch,data,pos;
	cout<<"Enter Data:"; cin>>data;
	cout<<"1:Insert at Begining\n2:Insert at Intermediate\n3:Insert at End\n"; 
	cin>>ch;
	
	switch(ch)
	{
		case 1: insertbeg(data);break;
		case 2: cout<<"Enter Position:";  cin>>pos;
				if(pos==1)
				{
					insertbeg(data);
				}
				insertmid(data,pos); break;
		case 3: insertend(data); break;
	}
}

void display()
{
	node *p=head;

	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p = p->next;
	}
}

void del()
{
	int pos;
	cout<<"Enter Position:";cin>>pos;
	node *p = head;
	for(int i=1;i<pos-1;i++)
	{
		p = p->next;
	}

}

int main()
{
	int ch;

	do
	{
		cout<<"\n1:Insert\n2:Delete\n3:Display\n"; cin>>ch;
		switch(ch)
		{
			case 1: insert();
					break;
			case 2: del();
					break;
			case 3: display();
					break;
		}
		
	}while(ch!=4);
	return 0;
}