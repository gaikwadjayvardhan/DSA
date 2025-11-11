#include<iostream>
using namespace std;

class Node{
   public:
   int coef;
   int pow;
   Node* next;

   Node(int c, int p){
       coef = c;
       pow = p;
       next = NULL;

   }
};

class Polynomial{
   public:
   Node *head;
   Polynomial(){
       head=NULL;
   }

   void insert(int c, int p){
       Node* nn = new Node(c, p);
       if(head==NULL){
           head=nn;
           return;
       }

       Node* temp = head;
       while(temp->next!=NULL){
           temp=temp->next;
       }
       temp ->next=nn;
   }
   void display(){
       Node* temp=head;
       while(temp->next!=NULL){
           cout<<temp->coef<<"x^"<<temp->pow<<" + ";
           temp=temp->next;

       }
       cout<<temp->coef<<"x^"<<temp->pow<<endl;
   }
};

Polynomial add_nodes(Node* p1, Node* p2){
   Node* t1 = p1;
   Node* t2 = p2;
   Polynomial ans;

   while (t1!=NULL && t2!=NULL){
       if(t1->pow > t2->pow){
           ans.insert(t1->coef, t1->pow);
           t1 = t1->next;
       }
       else if(t1->pow < t2->pow){
           ans.insert(t2->coef, t2->pow);
           t2 = t2->next;
       }
       else{
           ans.insert(t1->coef + t2->coef, t1->pow);
           t1 = t1->next;
           t2 = t2->next;
       }
   }

   while(t1!=NULL){
       ans.insert(t1->coef, t1->pow);
       t1 = t1->next;
   }
   while(t2!=NULL){
       ans.insert(t2->coef, t2->pow);
       t2 = t2->next;
   }

   return ans;
}


int main(){
   Polynomial p1,p2;
  int n, m;

   cout << "Enter number of terms in Polynomial 1: ";
   cin >> n;
   for(int i=0; i<n; i++){
       int c, pwr;
       cout << "Enter coefficient and power of term " << i+1 << ": ";
       cin >> c >> pwr;
       p1.insert(c, pwr);
   }

   cout << "Enter number of terms in Polynomial 2: ";
   cin >> m;
   for(int i=0; i<m; i++){
       int c, pwr;
       cout << "Enter coefficient and power of term " << i+1 << ": ";
       cin >> c >> pwr;
       p2.insert(c, pwr);
   }


   Polynomial sum = add_nodes(p1.head, p2.head);
   cout<< "After addition: ";
   sum.display();

   return 0;
}  
