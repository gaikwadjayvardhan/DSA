#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string text;
    Node* prev;
    Node* next;

    Node(string t) {
        text = t;
        prev = nullptr;
        next = nullptr;
    }
};

class TextEditor {
public:
    Node* head;
    Node* tail;

    TextEditor() {
        head = nullptr;
        tail = nullptr;
    }

    void insertText() {
        string t;
        cout << "Enter text to insert: ";
        cin.ignore();
        getline(cin, t);

        Node* nn = new Node(t);

        if (!head) {
            head = tail = nn;
            return;
        }

        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }

    void deleteText() {
        if (!head) {
            cout << "Buffer is empty.\n";
            return;
        }

        string t;
        cout << "Enter text to delete: ";
        cin.ignore();
        getline(cin, t);

        Node* curr = head;
        while (curr && curr->text != t) {
            curr = curr->next;
        }

        if (!curr) {
            cout << "Text not found.\n";
            return;
        }

        if (curr == head && curr == tail) { // only one node
            head = tail = nullptr;
        } else if (curr == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (curr == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
        cout << "Text deleted.\n";
    }

    void display() {
        if (!head) {
            cout << "Buffer is empty.\n";
            return;
        }

        cout << "\n--- Text Buffer ---\n";
        Node* temp = head;
        while (temp) {
            cout << temp->text << endl;
            temp = temp->next;
        }
    }

    void searchText() {
        if (!head) {
            cout << "Buffer is empty.\n";
            return;
        }

        string t;
        cout << "Enter text to search: ";
        cin.ignore();
        getline(cin, t);

        Node* temp = head;
        int line = 1;
        bool found = false;

        while (temp) {
            if (temp->text.find(t) != string::npos) {
                cout << "Found at line " << line << ": " << temp->text << endl;
                found = true;
            }
            temp = temp->next;
            line++;
        }

        if (!found) {
            cout << "Text not found.\n";
        }
    }

    void printReverse() {
        if (!tail) {
            cout << "Buffer is empty.\n";
            return;
        }

        cout << "\n--- Text in Reverse ---\n";
        Node* temp = tail;
        while (temp) {
            cout << temp->text << endl;
            temp = temp->prev;
        }
    }

    // clear buffer
    void clearBuffer() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

int main() {
    TextEditor editor;
    int choice;

    do {
        cout << "\n---- Simple Text Editor Menu ----\n";
        cout << "1. Insert text\n";
        cout << "2. Delete text\n";
        cout << "3. Display text\n";
        cout << "4. Search text\n";
        cout << "5. Print text in reverse\n";
        cout << "6. Clear buffer\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                editor.insertText();
                break;
            case 2:
                editor.deleteText();
                break;
            case 3:
                editor.display();
                break;
            case 4:
                editor.searchText();
                break;
            case 5:
                editor.printReverse();
                break;
            case 6:
                editor.clearBuffer();
                cout << "Buffer cleared.\n";
                break;
            case 7:
                cout << "Exiting editor.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}

