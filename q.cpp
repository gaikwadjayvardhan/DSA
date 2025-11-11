#include<iostream>
using namespace std;

// class Queue{
// 	int arr[100];
// 	int front, rear;

// 	Queue(){
// 		front = 0;
// 		rear = -1;
// 	}

// 	void enqueue(int val){
// 		if(rear == 99){
// 			cout<< "Queue Overflow\n";
// 			return;
// 		}
// 		arr[++rear] = val;
// 	}
// 	int dequeue(){
// 		if(front>rear){
// 			cout<<"Queue Underflow\n";
// 			return -1;
// 		}
// 		return arr[front++];
// 	}

// 	void display(){
// 		for(int i = front; i<=rear; i++)
// 			cout<<arr[i]<<" ";
// 		cout<<endl;
		
// 	}
// };

struct Node{
	int data;
	Node* next;
};
class Queue{
	Node* front;
	Node* rear;
public:
	Queue(){
		front = nullptr;
		rear = nullptr;
	}

	void enqueue(int val){
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = nullptr;

		if(!rear){
			front = rear =newNode;
			return;
	}
		rear->next = newNode;
		rear = newNode;	

	}

	int dequeue(){
		if(!front){
			cout<<"queue underflow\n";
			return -1;
		}
		int x = front->data;
		Node* temp = front;
		front = front->next;

		if(!front) rear = nullptr;

		delete temp;
		return x;

	}
	void display(){
		Node* temp = front;
		while(temp){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
			
	}

};




int main(){
	Queue q;
	int v, choice;
	do{
		cout<<"Choose operation:\n1.enqueue\n2.dequeue\n3.Display\n4.Exit\n";
		cin>>choice;
		if(choice == 1){
			cout<<"Enter Value to enqueue in stack: ";
			cin>>v;
			q.enqueue(v);
		}
		else if(choice == 2){
			q.dequeue();
		}
		else if(choice == 3){
			q.display();
		}
	
	
	}while(choice != 4);
	

}





