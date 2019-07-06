/*
author : vtiwar18

*/
#include"bits/stdc++.h"
using namespace std;

struct node
{
	int data;
	node *next;
};
struct node *head=NULL;

void insertbeg(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->next = head;
	head = temp;
}

void insertmid(int data, int pos)
{
	node *temp=new node();
	temp->data = data;
	node *p = head;

	for(int i=1;i<pos-1;i++)
	{
		p=p->next;
	}
	//cout<<p->data;

	node *t;
	t = p->next;
	p->next = temp;
	temp->next = t;

	return;
}

void insertend(int data)
{
	node *temp =  new node();
	temp->data = data;
	node *p = head;

	if(p==NULL)
	{
		insertbeg(data);
		return;
	}

	while(p->next!=NULL)
	{
		p = p->next;
	}

	p->next = temp;
	temp->next = NULL;
	return;
}

void insert()
{
	int data;
	cout<<"Enter Data:"; cin>>data;
	cout<<"1:Insert in begining\n2:Insert in between\n3:Insert at end";
	int ch;
	cin>>ch;

	switch(ch)
	{
		case 1: insertbeg(data);
				break;
		case 2: int pos;
				cout<<"Enter Position:"; cin>>pos;
				insertmid(data,pos);
				break;
		case 3: insertend(data);
				break;
	}
}

void del()
{
	int pos,k=1;
	cout<<"Enter Position of Node to be Deleted:"; cin>>pos;
	node *p=head;
	
	if(pos==1)
	{
		head = p->next;
		free(p);
		return;
	}
	while(p != NULL && k<pos-1)
	{
		k++;
		p = p->next;
	}
	node *t = p->next;
	p->next = t->next;
	free(t);

}

void display()
{
	node *p = head;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p = p->next;
	}
}

int main()
{
	int ch;
	do 
	{
		cout<<"\n1:Insert\n2:Delete\n3:Modify\n4:Display\n";
		cin>>ch;
		switch(ch)
		{
			case 1: insert();
					break;
			case 2: del();
					break;
			case 3: display();
					break;
		}
	}
	while(ch!=4);
	
	return 0;
}
