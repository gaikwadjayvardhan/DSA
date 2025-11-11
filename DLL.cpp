#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

class DLL{
	Node* head;
	public:
		DLL(){
			head = nullptr;
		}

		void insertFront(int val){
			Node* newNode = new Node;
			newNode->data = val;
			newNode->prev = nullptr;
			newNode->next = head;
			if(head) head->prev = newNode;
			head = newNode;
		}
		void insertEnd(int val){
			Node* newNode = new Node;
			newNode->data = val;
			newNode->prev = nullptr;
			newNode->next = nullptr;

			if(!head){
				head = newNode;
				return;
			}
			Node* temp = head;
			while(temp->next) temp = temp->next;
			temp->next = newNode;
			newNode->prev = temp;

        }


        void remove(int val){
        	if(!head) return;

        	Node* temp = head;

        	while(temp && temp->data != val) temp =  temp->next;

        	if(!temp) return;
        	if(temp == head) head = temp->next;
        	if(temp->next) temp->next->prev = temp->prev;
        	if(temp->prev) temp->prev->next = temp->next;

        	delete temp;
        }

        void display(){
        	Node* temp = head;

        	while(temp){
        		cout<< temp->data<<" ";
        		temp = temp->next;
        	}
        	cout<< endl;
        }
        int getLen(Node* head){
        	int len = 0;
        	Node* temp = head;

        	while(temp != nullptr){
        		len++;
        		temp = temp->next;
        	}
        	return len; 
        }	
        void displayRev(){
        	if(!head) return;
        	Node* temp = head;
        	while(temp->next != nullptr){
        		temp = temp->next;
        	}

        	while(temp){
        		cout<<temp->data<<" ";
        		temp=temp->prev;
        	}
        	cout<<endl;
        }

};

int main(){
	DLL d;
	int x, choice;

	

	do{
		cout<<"Enter Choice:\n1. Insert at the End\n2. Insert at the Front\n3. Remove\n4. Display\n5. Exit\n";
		cin>>choice;
		if(choice == 1){
			cout<< "Enter the Value to be added: ";
			cin>>x; 
			d.insertEnd(x);
		}
		if(choice == 2){
			cout<< "Enter the Value to be added: ";
			cin>>x; 
			d.insertFront(x);
		}
		 if (choice == 3)
		{	
			cout<< "Enter the Value to be removed: ";
			cin>>x; 
			d.remove(x);
		}
		 if(choice == 4){
			d.displayRev();
		}


	}while(choice != 5);
}