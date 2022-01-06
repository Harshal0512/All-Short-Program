#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

int array[100], a;
void process();
void input();
void show();
void insert();
void update();
void deletee();
void search();

void main(){
	input();
}
void input(){
	clrscr();
	int i;
	cout<<"Enter number of elements in the array: ";
	cin>>a;
	/*for(i=0; i<a; i++){
		array[i]=0;
	}*/
	cout<<"\n";
	for(i=0; i<a; i++){
		cout<<"Enter element "<<i+1<<" ";
		cin>>array[i];
	}
	clrscr();
	process();
}

void process(){
	label:
	clrscr();
	int n;
	cout<<"Select any operation you wanna perform: \n1. Show\n2. Insert\n3. Update\n4. Delete\n5. Search any Element\n6. Exit\n?";
	cin>>n;
	switch(n){
		case 1:
			show();
			goto label;
			break;
		case 2:
			insert();
			goto label;
			break;
		case 3:
			update();
			goto label;
			break;
		case 4:
			deletee();
			goto label;
			break;
		case 5:
			search();
			goto label;
			break;
		case 6:
			exit(0);
			break;
		default:
			cout<<endl<<"Please Enter a valid command";
			getch();
			goto label;
	}
}

void show(){
	clrscr();
	cout<<"Elements of the array are:\n";
	for(int i=0; i<a; i++){
		cout<<array[i]<<"\n";
	}
	getch();
}

void insert(){
	clrscr();
	cout<<"Elements of the array are:\n";
	for(int i=0; i<a; i++){
		cout<<"location "<<i+1<<": "<<array[i]<<"\n";
	}
	cout<<"Enter the location at which you want to insert ";
	int loc;
	cin>>loc;
	cout<<"Enter the value to be inserted ";
	int tempval;
	cin>>tempval;
	for(int n=a; n>=loc; n--)
		array[n]=array[n-1];
	array[loc-1]=tempval;
	a++;
	show();
}

void update(){
	clrscr();
	cout<<"Elements of the array are:\n";
	for(int i=0; i<a; i++){
		cout<<"location "<<i+1<<": "<<array[i]<<"\n";
	}
	cout<<"Enter the location of the element to be updated ";
	int loc;
	cin>>loc;
	cout<<"Enter the value to be updated ";
	int tempval;
	cin>>tempval;
	loc--;
	array[loc]=tempval;
	cout<<endl<<"Value Updated Successfully!...Press Enter to Continue"<<endl;
	getch();
	show();
}

void deletee(){
	clrscr();
	cout<<"Elements of the array are:\n";
	for(int i=0; i<a; i++){
		cout<<"location "<<i+1<<": "<<array[i]<<"\n";
	}
	cout<<"Enter the location of the element to be deleted ";
	int loc;
	cin>>loc;
	for(int n=loc; n<a; n++)
		array[n-1]=array[n];
	a--;
	cout<<"Value Deleted successfully!...Press Enter to continue..";
	getch();
	show();
}

void search(){
	clrscr();
	cout<<"Enter element you wanna search"<<endl<<"?";
	int tempval;
	cin>>tempval;
	int n=0, locs[1000];
	for(int k=0; k<a; k++){
		if(array[k]==tempval){
			locs[n]=k;
			n++;
		}
	}
	cout<<endl;

	clrscr();
	cout<<"Elements of the array are:\n";
	for(int i=0; i<a; i++){
		cout<<"location "<<i+1<<" "<<array[i]<<"\n";
	}
	if(n>0){
		cout<<"\n"<<n<<" elements found in the array at location ";
		for(int j=0; j<n; j++){
			cout<<locs[j]+1<<" ";
		}
	}else{
		cout<<"\nElement not found";
	}
	getch();
}