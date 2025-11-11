#include<iostream>
using namespace std;

class Stack{
	int arr[100];
	int top;
	
	public:
	
	Stack(){top = -1;}
	
	void push(int val){
		if(top == 99){
			cout<<"Stack Overflow\n";
			return;
		}
		arr[++top] = val;
	
	}
	
	
	int pop(){
		if (top == -1){
			cout<< "Stack Underflow\n";
			return -1;
		}
		return arr[top--];
	}
	void display(){
		for(int i = top; i>=0; i--){
			cout<< arr[i]<< " ";
		cout<<endl;
		}
	
	}
};
	
int main(){
	Stack s;
	int v, choice;
	do{
		cout<<"Choose operation:\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
		cin>>choice;
		if(choice == 1){
			cout<<"Enter Value to push in stack: ";
			cin>>v;
			s.push(v);
		}
		else if(choice == 2){
			s.pop();
		}
		else if(choice == 3){
			s.display();
		}
	
	
	}while(choice != 4);
	

}

