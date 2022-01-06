#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	Node *next;
};
struct Node *head=NULL;

void createNode(int dat){
	struct Node *newnode=new Node;
	newnode->data=dat;

	if(head==NULL){
		newnode->next=NULL;
	}
	else{
		newnode->next=head;
	}
	head=newnode;
}

int traverse(){
	//this function prints the contents of the list
	//and returns the count of data elements in the list
	struct Node *temp=head;
	int count=0;
	if(temp==NULL)
		cout<<"List is Empty";
	else{
		while(temp!=NULL){
			count++;
			cout<<"Element "<<count<<": "<<temp->data<<endl;
			temp=temp->next;
		}
	}
	return count;
}

void init(){
	//this function initialises the list
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	int el;
	for(int i=1; i<=n; i++){
		cout<<"Enter data element "<<i<<" ";
		cin>>el;
		createNode(el);
	}
}

void mid(int loc, int val){
	struct Node *newNode=new Node;
	newNode->data=val;
	struct Node *left=head;
	struct Node *right=left->next;
	int count=0;

	while(left!=NULL){
		count++;
		if(count==loc)
			break;
		left=right;
		right=right->next;
	}
	left->next=newNode;
	newNode->next=right;
}

void end(int enddata){
	struct Node *newNode=new Node;
	newNode->data=enddata;
	struct Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	newNode->next=NULL;
	temp->next=newNode;
}

void deletee(int loc){
	struct Node *left=head;
	struct Node *right=left->next;
	int count=0;

	while(left!=NULL){
		count++;
		if(count==loc)
			break;
		left=right;
		right=right->next;
	}
	left->next=right->next;
	right->next=NULL;
	delete(right);
}

void removeDuplicates(){
    struct Node *left, *right, *temp;
    left=right=head;
	right=right->next;
    while(left!=NULL){
        temp=left;
        while(right!=NULL){
            if(left->data==right->data){
                struct Node *temp2=right;
                temp->next=temp2->next;
                right=temp->next;
                delete(temp2);
            }else{
                temp=right;
                right=right->next;
            }
        }
    left=left->next;
    right=left->next;
    }
    delete(left);
    delete(right);
}

void menu(){
	label:
	clrscr();
	cout<<"Welcome to the Linked List Creator"<<endl;
	cout<<"1. Display all elements"<<endl;
	cout<<"2. Insert into existing list"<<endl;
	cout<<"3. Delete from list"<<endl;
	cout<<"4. Remove Duplicates"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"?";
	int choice;
	cin>>choice;
	if(choice==2){
		insidelabel:
		clrscr();
		cout<<"Further select options for Inserting"<<endl;
		cout<<"1. Insert at head"<<endl;
		cout<<"2. Insert in middle"<<endl;
		cout<<"3. Insert in the end"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"?";
		cin>>choice;
		switch(choice){
			case 1:
				choice=6;
				break;
			case 2:
				choice=7;
				break;
			case 3:
				choice=8;
				break;
			case 4:
				choice=5;
				break;
			default:
				cout<<"Please enter valid choice";
				getch();
				goto insidelabel;
		}
	}
	clrscr();
	switch(choice){
		case 1:
			traverse();
			break;
		case 3:
			traverse();
			cout<<"Enter the location you want to delete ";
			int loc;
			cin>>loc;
			loc--;
			deletee(loc);
			cout<<endl<<"Updated List:"<<endl<<endl;
			traverse();
			break;
		case 4:
			traverse();
			removeDuplicates();
			cout<<endl<<"Updated List:"<<endl<<endl;
			traverse();
			break;
		case 5:
			exit(0);
			break;
		case 6:
			cout<<"Enter the data you want to insert at head: ";
			int dat;
			cin>>dat;
			createNode(dat);
			cout<<"Updated List:"<<endl<<endl;
			traverse();
			break;
		case 7:
			int size;
			size=traverse();
			int loc1;
			int val;
			cout<<"Enter the location at which you want to insert ";
			cin>>loc1;
			if(loc1>size){
				cout<<"Location Out of Bounds, Please try again";
				break;
			}
			loc1--;
			cout<<"Enter the data you want to insert ";
			cin>>val;
			mid(loc1, val);
			cout<<"Updated List:"<<endl<<endl;
			traverse();
			break;
		case 8:
			cout<<"Enter the data you want to insert at the end of the list ";
			int enddat;
			cin>>enddat;
			end(enddat);
			cout<<"Updated List:"<<endl<<endl;
			traverse();
			break;
		default:
			cout<<"Please enter a valid choice";
			break;
	}
	getch();
	goto label;
}

int main(){
	clrscr();
	init();
	menu();
	//cout<<"\nThe List has "<<traverse()<< " elements";
	getch();
	return 0;
}