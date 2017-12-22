#include<bits/stdc++.h>
using namespace std;

//creating a node at Nth Position and displaying it
struct Node
{
	int data;
	Node* link;
};
struct Node* head = NULL;

void Insert(int data,int n)
{
	Node* temp = new Node();                           //data pehle ghusaao phir position set kro ki kaha pe node break ya join hoga
	temp->data = data;
	temp->link = NULL;
	
	if(n == 1)
	{
		temp->link = head;
		head = temp;
		return;
	}          
	Node* t = head;
	for(int i = 0 ; i < n-2 ; i++)
	{
		t = t->link;
	}               
	temp->link = t->link;
	t->link = temp;                
}

void Display()
{
	Node* t = head;
	cout<<"\nList is : ";
	
	while(t != NULL)
	{
		cout<<t->data<<" ";
		t = t->link;
	}
	cout<<"\n";
}

int main()
{
	int i,x,data,posn;
	cout<<"Enter the numbers to be inserted ";
	cin>>x;
	for(i = 0 ; i < x ; i++)
	{
		cout<<"\nEnter the Data And the Position";
		cin>>data>>posn;
		
		Insert(data,posn);
		Display();
	}	
	return 0;
}
