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
};
struct node *head=NULL;

void display()
{
	node *p = head;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p = p->next;
	}
	cout<<endl;
}

void insert()
{
	int data,pos,k=1;
	cout<<"Enter Data :";
	cin>>data;
	cout<<"Enter Pos :";
	cin>>pos;

	node *temp = new node;
	temp->data = data;

	if(pos==1)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		node *p =head;

		while(p!=NULL && k<pos-1)
		{
			p = p->next;
			k++;
		}
		temp->next = p->next;
		p->next = temp;
	}
	
}

void del()
{
	int pos,k=1;
	cout<<"Enter Pos :";
	cin>>pos;

	if(pos==1)
	{
		node *p = head;
		head = head->next;
		free(p);
	}
	else
	{
		node *p = head;
		while(p != NULL && k<pos-1)
		{
			k++;
			p = p->next;
		}
		node *t = p->next;
		p->next = t->next;
		free(t);
	}
}

int main(int argc, char const *argv[])
{
	int ch;
	
	do
	{
		cout<<"1:Insert\n2:Delete\n3:Display";
		cin>>ch;
		switch(ch)
		{
			case 1:insert();break;
			case 2:del();break;
			case 3:display();break;
		}
	}
	while(ch!=4);
	

	return 0;
}