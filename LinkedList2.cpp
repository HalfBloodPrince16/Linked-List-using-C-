#include<bits/stdc++.h>
using namespace std;

//creating a node always in the begining and displaying it
struct Node
{
	int data;
	Node* link;
};
struct Node* head = NULL;

void Insert(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->link = head;
	head = temp;
}

void Display()
{
	Node* t = new Node();
	cout<<"\nList is : ";
	t = head;
	while(t != NULL)
	{
		cout<<t->data<<" ";
		t = t->link;
	}
	cout<<"\n";
}

int main()
{
	int i,x,data;
	cout<<"Enter the numbers to be inserted ";
	cin>>x;
	for(i = 0 ; i < x ; i++)
	{
		cout<<"\nEnter the Data";
		cin>>data;
		Insert(data);
		Display();
	}	
	return 0;
}
