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

struct sll
{
	int data;
	sll *next;
};
sll * head=NULL;

void insert_begin()
{
	int d;
	cout<<"Enter Data :";
	cin>>d;
	sll *temp = new sll();
	temp->data = d;
	temp->next = head;
	head = temp;
}
void insert_last()
{
	int d;
	cout<<"Enter Data :";
	cin>>d;
	sll *temp = new sll();
	temp->data = d;
	temp->next = NULL;
	sll *p = head;
	if(head==NULL)
	{
		head = temp;
		return;
	}
	while(p->next!=NULL){p = p->next;}
	p->next = temp;
}

void insert_mid()
{
	int d,pos;
	cout<<"Enter Data :";
	cin>>d;
	cout<<"Enter Position :";
	cin>>pos;
	sll *temp = new sll();
	sll *p = head;
	int cnt=1;
	while(cnt<=pos-2)
	{
		cnt++;
		p = p->next;
	}
	sll *t;
	temp->data = d;
	temp->next = p->next;
	p->next = temp;
}

void deletenode()
{
	int pos;
	cout<<"Enter Position :";
	cin>>pos;
	sll *p = head;
	if(pos == 1)
	{
		head = p->next;
		free(p);
		return ;
	}
	int cnt=1;
	while(cnt <= pos-2)
	{
		p = p->next;
		cnt++;
	}
	sll *t = p->next->next;
	free(p->next);
	p->next = t;

}

void display()
{
	sll *p;
	p = head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
}

int main(int argc, char const *argv[])
{
	int ch;
	insert_last();
	insert_last();
	insert_last();
	insert_last();
	insert_mid();
	display();
	deletenode();
	display();
	return 0;
}