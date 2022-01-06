#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct Node{
	int coeff;
	Node *next;
};

//struct Node *head=NULL;
Node *createNode(int val, Node *head){
	struct Node *newNode=new Node;
	newNode->coeff=val;
	newNode->next=NULL;

	if(head==NULL){
		head=newNode;
	}
	else{
		struct Node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
	return head;
}

Node *input(int deg, Node *head){
	int val;
	struct Node *node = head;
	for(int i=deg; i>=1; i--){
		clrscr();
		if(i!=1){
			cout<<"Enter coefficient of x^"<<i<<": ";
			cin>>val;
			node = createNode(val, node);
			continue;
		}
		cout<<"Enter constant term: ";
		cin>>val;
		node = createNode(val, node);
	}
	return node;
}

void main(){
	struct Node *head=NULL;
	clrscr();
	cout<<"Enter the degree of polynomial you want to store: ";
	int deg;
	cin>>deg;
	head=input(deg, head);
	clrscr();
	cout<<"The Polynomial you entered was: ";
	struct Node *temp=head;
	for(int i=deg; i>=1; i--){
		if(temp->coeff<0)
			cout<<" "<<temp->coeff<<"x^"<<i<<" ";
		else if(temp->coeff>0 && i==deg)
			cout<<" "<<temp->coeff<<"x^"<<i<<" ";
		else 
			cout<<"+ "<<temp->coeff<<"x^"<<i<<" ";
		/* cout<<temp->coeff<<"x^"<<i<<" ";
		temp=temp->next; */
		temp=temp->next;
	}
	getch();
}