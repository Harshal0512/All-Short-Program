#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

struct Node{
	int data;
	Node *next;
};

struct Node *head=NULL;

void push(int data){
	struct Node *newNode=new Node;
	newNode->data=data;
	if(head==NULL){
		newNode->next=NULL;
	}
	else{
		newNode->next=head;
	}
	head=newNode;
}

void pop(){
	int data;
	if(head==NULL)
		cout<<"Underflow Condition";
	else{
		data = head->data;
		head=head->next;
		cout<<"Element: "<<data<<" popped Successfully...";
	}
}
void display(){
	struct Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL";
}
void main(){
	clrscr();
	cout<<"Enter the number of elements you want to push: ";
	int n;
	cin>>n;
	int data;
	for(int i=1; i<=n; i++){
		clrscr();
		cout<<endl<<"Element "<<i<<": ";
		cin>>data;
		push(data);
	}
	label:
	clrscr();
	cout<<"1. Push an Element\n";
	cout<<"2. Display all Elements\n";
	cout<<"3. Pop an Element\n";
	cout<<"4. Exit\n";
	cout<<"?";
	int choice;
	cin>>choice;
	switch(choice){
		case 1:
			clrscr();
			cout<<"Enter the Element you wanna Push to the Stack: ";
			cin>>data;
			push(data);
			cout<<"\nData Pushed Successfully, Press Any Key to continue...";
			getch();
			goto label;
			break;
		case 2:
			clrscr();
			display();
			getch();
			goto label;
			break;
		case 3:
			clrscr();
			pop();
			getch();
			goto label;
			break;
		case 4:
			exit(0);
	}
	getch();
}