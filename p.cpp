#include<iostream>
using namespace std;

struct Node{
	int data;
	string name;
	Node* next;
	Node(int val, string s){
		data = val;
		name = s;
		next = nullptr;
	}
};

class SLL{
	Node* head;
public:
	SLL(){head = nullptr;}

	void addFront(int val, string s){
		Node* newNode = new Node(val, s);
		newNode->next = head;
		head = newNode;
	}

	void append(int val, string s){
		Node* newNode = new Node(val, s);

		if(!newNode) return;
		if(!head){
			head = newNode;
			return;
		}
		Node* temp = head;
		while(temp->next) temp = temp->next;
		temp->next = newNode;

	}

	void insert(int val, string s, int pos){
		Node* newNode = new Node(val, s);

		if(pos == 0 || head == nullptr){
			newNode->next  = head;
			head = newNode;
			return;
		}

		Node* p = head;
		for(int i = 0; i < pos-1; i++){
			if(p->next == nullptr) break;
			p = p->next;
		}
		newNode->next = p->next;
		p->next = newNode;


	}

	int search(int val, string s){
		Node* temp = head;
		int f = 0;
		while(temp){
			if(temp->data == val && temp->name == s){
				cout<<"Found at: "<< f << endl;
				// return f;
			}
			temp = temp->next;
			f++;
		}
		
		return -1;
	}

	int count(int val, string s){
		Node* c = head;
		int cnt = 0;
		while(c != nullptr){
			if(c->data == val && c->name == s) cnt++;
			c = c->next;
		}
		
		return cnt;
	}



	void display(){
		Node* temp = head;
		while(temp){
			cout<< temp->name<<" "<< temp->data<<endl;
			temp = temp->next;
		}
		cout<<endl;

	}

};

int main(){
	SLL s;
	s.append(10, "damn");
	s.append(20, "damn");
	s.append(6c0, "damn");
	s.append(60, "damn");
	s.append(60, "damn");
	s.append(60, "damn");
	s.display();

	s.insert(200, "hello", 3);
	s.display();
	s.search(200, "hello");
	cout<< s.count(60, "damn");
	return 0;
}