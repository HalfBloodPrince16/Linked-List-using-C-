#include"bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
vector<int>v;
vector<int>u;
priority_queue<int>pq;
std::map<int,int> m;
const int N=1e6+10;
/*--------------------------hbp16@hbp16-Inspiron-3543:-$------------------------------*/

struct node 
{
	int data;
	node *next;
	node *prev;
};
struct node *head=NULL;

void Insert()
{
	int data,pos;
	cout<<"Enter Data:"; cin>>data;
	cout<<"Enter Pos:"; cin>>pos;

	node *temp = new node;
	temp->data = data;

	if(pos==1)
	{
		temp->next = head;
		head = temp;
		temp->prev = NULL;
	}
	else
	{
		int k=1;
		node *p=head;

		while(p!=NULL && k<pos-1)
		{
			k++;
			p = p->next;
		}

		temp->next = p->next;
		temp->prev = p;
		p->next = temp;
		p = p->next;
		p->prev = temp;
	}
}

void Del()
{
	int pos,k;
	cout<<"Enter Pos:"; cin>>pos;
	
	if(pos==1)
	{
		node *p = head;
		node *t = head->next;
		head = head->next;
		t->prev = NULL;
		p->next = NULL;
		free(p);
	}
	else
	{

		int k=1;
		node *p=head;

		while(p!=NULL && k<pos-1)
		{
			k++;
			p = p->next;
		}

		if(p->next->next==NULL)
		{	
			node *t = p->next;
			t->next=NULL;
			t->prev=NULL;
			free(t);
			p->next=NULL;
			return;
		}	

		node *t = p->next;
		p->next = t->next;
		node *tt = t->next;
		tt->prev = t->prev;
		t->prev = NULL;
		t->next = NULL;
		free(t);
	}
	return;
}

void Display()
{
	node *p = head;

	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p = p->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int ch;

	do
	{
		cout<<"1:Insert\n2:Delete\n3:Display\n";
		cin>>ch;

		switch(ch)
		{
			case 1: Insert();
				break;
			case 2: Del();
				break;
			case 3: Display();
				break;

		}
	}
	while(ch!=4);
	return 0;
}