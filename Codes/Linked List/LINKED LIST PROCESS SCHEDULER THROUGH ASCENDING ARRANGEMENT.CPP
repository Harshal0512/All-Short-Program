#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	int priority;
	Node *next;
};
struct Node *head=NULL;

void createNode(int dat, int p){
	struct Node *newnode=new Node;
	newnode->data=dat;
	newnode->priority=p;

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
	int count=0, p;
	if(temp==NULL)
		cout<<"List is Empty";
	else{
		while(temp!=NULL){
			count++;
			cout<<"Element "<<count<<": "<<temp->data<<"\n\tP= ";
			p=temp->priority;
			if(p==1)
				cout<<"High"<<endl<<endl;
			else if(p==2)
				cout<<"Medium"<<endl<<endl;
			else if(p==3)
				cout<<"Low"<<endl<<endl;
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
	int p;
	for(int i=1; i<=n; i++){
		plabel:
		cout<<"Enter data element "<<i<<" ";
		cin>>el;
		cout<<"Enter Priority for the task:\n1. High\n2. Medium\n3. Low\n?";
		cin>>p;
		if(p!=1 && p!=2 && p!=3){
			cout<<"Please enter valid Priority Number"<<endl;
			getch();
			goto plabel;
		}
		createNode(el, p);
	}
}

void mid(int loc, int val, int p){
	struct Node *newNode=new Node;
	newNode->data=val;
	newNode->priority=p;
	struct Node *left=head;
	struct Node *right=left->next;
	int count=0;
	loc--;
	while(left!=NULL){
		count++;
		if(count==loc)
			break;
		left=right;
		right=right->next;
	}
	newNode->next=right;
	left->next=newNode;
}

void end(int enddata, int p){
	struct Node *newNode=new Node;
	newNode->data=enddata;
	newNode->priority=p;
	struct Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	newNode->next=NULL;
	temp->next=newNode;
}

void deletee(){
	traverse();
	cout<<"Which Element do you want to delete: ";
	int loc;
	cin>>loc;
	int n=1;
	struct Node *left=head;
	//struct Node *right=left->next; right not required
	struct Node *temp=new Node;//Important for using delete
	loc--;
	while(loc!=n){
		left=left->next;
		n++;
	}
	//right=left->next; not required
	temp=left->next;
	left->next=left->next->next;
	delete(temp);
	cout<<"Element Deleted Successfully!!"<<endl;
}

void update(){
	traverse();
	cout<<"Which Element do you want to update: ";
	int loc;
	cin>>loc;
	cout<<"Enter the value to be updated: ";
	int dat;
	cin>>dat;
	int p;
	plabel2:
	cout<<"Enter Priority for the task:\n1. High\n2. Medium\n3. Low\n?";
	cin>>p;
	if(p!=1 && p!=2 && p!=3){
		cout<<"Please enter valid Priority Number"<<endl;
		getch();
		goto plabel2;
	}
	int n=1;
	struct Node *left=head;
	while(loc!=n){
		left=left->next;
		n++;
	}
	left->data=dat;
	left->priority=p;
}

void arrange(){
	int c;
	struct Node *left=new Node;
	struct Node *right=new Node;
	struct Node *temp=new Node;
	clrscr();
	while(1){
		c=1;
		left=head;
		right=left->next;
		while(left->next!=NULL){
			if(left->priority > right->priority){
				//transferring data
				temp->data=left->data;
				left->data=right->data;
				right->data=temp->data;
				//transferring priority
				temp->priority=left->priority;
				left->priority=right->priority;
				right->priority=temp->priority;

				c=0;
				break;
			}
			else{
				left=right;
				right=right->next;
			}
		}
		if(c==1)
			break;
	}
}
void menu(){
	label:
	clrscr();
	//1. for display
	//2.
	//3. for delete from list
	//4. for exit
	//5. for insert at head
	//6. for insert in middle
	//7. for insert in the end
	cout<<"Welcome to the Linked List Creator"<<endl;
	cout<<"1. Display all elements"<<endl;
	cout<<"2. Insert into existing list"<<endl;
	cout<<"3. Update an Element"<<endl;
	cout<<"4. Delete from list"<<endl;
	cout<<"5. Arrange the Elements"<<endl;
	cout<<"6. Exit"<<endl;
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
				choice=7;
				break;
			case 2:
				choice=8;
				break;
			case 3:
				choice=9;
				break;
			case 4:
				choice=6;
				break;
			default:
				cout<<"Please enter valid choice";
				getch();
				goto insidelabel;
		}
	}
	switch(choice){
		case 1:
			traverse();
			break;
		case 3:
			update();
			traverse();
			break;
		case 4:
			deletee();
			traverse();
			break;
		case 5:
			arrange();
			cout<<endl<<"Arranged Successfully according to Priority"<<endl<<endl;
			traverse();
			break;
		case 6:
			exit(0);
			break;
		case 7:
			cout<<"Enter the data you want to insert at head: ";
			int dat;
			cin>>dat;
			int p;
			plabel3:
			cout<<"Enter Priority for the task:\n1. High\n2. Medium\n3. Low\n?";
			cin>>p;
			if(p!=1 && p!=2 && p!=3){
				cout<<"Please enter valid Priority Number"<<endl;
				getch();
				goto plabel3;
			}
			createNode(dat, p);
			traverse();
			break;
		case 8:
			traverse();
			int loc;
			int val;
			cout<<"Enter the location at which you want to insert: ";
			cin>>loc;
			cout<<"Enter the data you want to insert: ";
			cin>>val;
			plabel4:
			cout<<"Enter Priority for the task:\n1. High\n2. Medium\n3. Low\n?";
			cin>>p;
			if(p!=1 && p!=2 && p!=3){
				cout<<"Please enter valid Priority Number"<<endl;
				getch();
				goto plabel4;
			}
			mid(loc, val, p);
			traverse();
			break;
		case 9:
			cout<<"Enter the data you want to insert at the end of the list: ";
			int enddat;
			cin>>enddat;
			plabel5:
			cout<<"Enter Priority for the task:\n1. High\n2. Medium\n3. Low\n?";
			cin>>p;
			if(p!=1 && p!=2 && p!=3){
				cout<<"Please enter valid Priority Number"<<endl;
				getch();
				goto plabel5;
			}
			end(enddat, p);
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