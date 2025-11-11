#include <isotream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

class Stack{
	Node* top;
	public:
	Stack(){top = nullptr;}
	
	void push(int val){
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = top;
		top = newNode;
	}
	
	int pop(){
		if(!top){
			cout<<"Stack Underflow\n";
			return -1;
		}
		int x = top->data;
		Node* temp = top;
		top = top->next;
		delete temp;
		return x;
	}
	void display(){
		Node* temp = top;
		while(temp){
			cout<< temp->data<<" ";
			temp = temp->next;
			
		}
		cout<< endl;
	}
};



int main(){
	

}

