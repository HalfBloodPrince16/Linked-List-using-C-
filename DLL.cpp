#include<bits/stdc++.h>
using namespace std;
//double linked list

struct Node
{
	int data;
	Node* prev;
	Node* next;
};
struct Node* head = NULL;

void insertathead()
{
	int data;
	cout<<"\nEnter a no to insert";
	cin>>data;
	
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	
	if(head == NULL)
	{
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
	return;	
}

void display()
{
	Node* t = head;
	while(t != NULL)
	{
		cout<<t->data;
		t = t->next;
	}
	cout<<"\nin reverse order";
	Node* tt = head;
	while(tt->next != NULL)
	{
		tt = tt->next;
	}
	while(tt != NULL)
	{
		cout<<tt->data;
		tt = tt->prev;
		
	}
}

int main()
{
	insertathead();
	insertathead();
	insertathead();
	insertathead();
	insertathead();
	display();
	return 0;
}
