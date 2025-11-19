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

    SLL(){
        head = nullptr;
    }
    void addFront(int val, string s){
        Node* newNode = new Node(val, s);
        newNode->next = head;
        head = newNode;
    }

    void Shove(int val, string s){
        Node* newNode = new Node(val, s);
        
        if(!newNode) return;
        if(!head){
            head = newNode;
            return;
        }
        Node * ptr;
        for( ptr = head; ptr->next; ptr = ptr->next);

        ptr->next = newNode;
    }


    friend void display(SLL s);
    
};
void show(Node n){
    cout<<n.data<< " "<< n.name<<" "<<endl;

}
void display(SLL s){
    for(Node* ptr = s.head; ptr; ptr = ptr->next){
        show(*ptr);

    }
}




int main(){
    
    SLL s;
    s.addFront(10, "hello");
    s.addFront(10, "hello");
    s.Shove(20, "ding");
    s.Shove(20, "ding");
    s.Shove(20, "ding");
    s.Shove(20, "ding");
    s.addFront(10, "hello");
    display(s);
    return 0;

}