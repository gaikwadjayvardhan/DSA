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

class Stack{
	Node* top;
public:
	Stack(){top = nullptr;}

	void push(int val){
		Node* newNode = new Node(val);
		newNode->next = top;
		top = newNode;
	}

	int pop(){
		if(isEmpty()) return -1;
		int x = top->data;
		Node* temp = top;
		top = top->next;
		delete temp	;
		return x;
		
	}
	int peek(){
		if(isEmpty()) return -1;
		return top->data;
	}

	bool isEmpty(){
		if(!top) return true;
		return false;
	}
	bool isFull(){
		Node* newNode = new Node(0);
		if(!newNode) return true;
		return false;
	}
	void display(){
		Node* temp = top;
		while(temp){
			cout<< temp->data;
			temp = temp->next;
		}
		cout<<endl;
	}
};


int main(){
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	cout<<s.peek()<<endl;
	s.display();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.display();
	return 0;
}