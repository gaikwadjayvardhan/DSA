#include<iostream>
using namespace std;


struct Node{
	int data;
	Node* next;
	Node(int val){
		data = val;
		next = nullptr;
	}
};

class Queue{
	Node* front;
	Node* rear;
public:
	Queue(){
		front = rear = nullptr;
	}

	void Enqueue(int val){
		Node* newNode = new Node(val);
		newNode->next = nullptr;
		if(!newNode) return;
		if(!rear){
			front = rear = newNode;
			return;
		}
		rear->next = newNode;
		rear = newNode;

	}

	int Dequeue(){
		if(isEmpty()) return -1;
		int x = front->data;
		Node* temp = front;
		front = front->next;

		if(!front) rear = nullptr;

		delete temp;
		return x;
		}
	bool isEmpty(){
		if(!front) return true;
		return false;	
	}
	void display(){
		Node* temp = front;
		while(temp){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<< endl;
	}

};




int main(){
	Queue  q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.display();
	q.Enqueue(40);
	q.Enqueue(50);
	q.display();
	cout<<q.Dequeue()<<endl;
	cout<<q.Dequeue()<<endl;
	cout<<q.Dequeue()<<endl;
	cout<<q.Dequeue()<<endl;
	q.display();

	return 0;
}