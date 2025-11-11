#include<iostream>
using namespace std;

struct Node{
	int data;
	string name;
	Node* next;
};

class SLL{
	
	public:
	
	Node*  head;
	SLL(){head = nullptr;}
	void insertFront(int val, string a){
		Node* newNode = new Node;
		newNode->data = val;
		newNode->name = a;
		newNode->next = head;
		head = newNode;
	}
	void insertBack(int val, string a){
		Node* newNode = new Node;
		newNode->data = val;
		newNode->name = a;
		newNode->next = nullptr;
		
		if(!head){
			head = newNode;
			return;
		}
		
		node* temp = head:
		while(temp->next) temp = temp->next;
		
		temp->next = newNode;
	
	}
	
	void display(){
		Node* temp = head;
			cout<<"Name:\tData:\n";
		while(temp){
			cout <<temp->name<<"\t" << temp->data<<endl;
			temp = 	temp->next;
		}
		cout<<endl;
	}

};

int main(){

	SLL a;
	int choice, v;
	string n;
	cout<<"Enter the values to be added."<<endl;
	do{
		cout<<"1. insert\n2.Display\n3.Exit\n";
		cin>> choice;
		if(choice == 1){
		cout<<"Enter the Value:"<<endl;
		cin >>v;
		cout<<"Enter name:"<<endl;
		cin>>n;
		a.insert(v, n);
		}
		else if(choice == 2){
			a.display();
		}
	
	}while(choice != 3);

}

