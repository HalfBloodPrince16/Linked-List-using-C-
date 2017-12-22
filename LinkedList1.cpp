#include<bits/stdc++.h>
using namespace std;

//creating a node and displaying it
struct Node
{
	int data;
	Node* link;
};
struct Node* head = NULL;

int main()
{
	Node* temp = new Node();
	temp->data = 2;
	temp->link = NULL;
	head = temp;
	
	cout<<temp->data;
	
	return 0;
}
