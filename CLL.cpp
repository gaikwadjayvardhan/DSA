#include<iostream>
using namespace std;

struct Node{
    int data;
    string name;
    Node* next;
};

class CLL {

public:
    Node* head;

    CLL() { head = nullptr; }

    void insertFront(int val, string a) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->name = a;

        if (!head) {
            head = newNode;
            newNode->next = head;   // self loop
            return;
        }

        Node* temp = head;
        while (temp->next != head) temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertBack(int val, string a) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->name = a;

        if (!head) {
            head = newNode;
            newNode->next = head;   // self loop
            return;
        }

        Node* temp = head;
        while (temp->next != head) temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (!head) return;

        cout << "Name:\tData:\n";

        Node* temp = head;
        do {
            cout << temp->name << "\t" << temp->data << endl;
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
  void reverseDisplay() {
    if (!head) return;

    Node* temp = head;
    int count = 0;

    // Step 1: count nodes
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    // Step 2: create array to store values
    Node** arr = new Node*[count];

    temp = head;
    int i = 0;

    // Step 3: store nodes in array
    do {
        arr[i++] = temp;
        temp = temp->next;
    } while (temp != head);

    // Step 4: print in reverse
    cout << "Name:\tData:\n";
    for (int j = count - 1; j >= 0; j--) {
        cout << arr[j]->name << "\t" << arr[j]->data << endl;
    }

    cout << endl;

    delete[] arr;
}

};
