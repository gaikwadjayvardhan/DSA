#include <iostream>
using namespace std;

struct Employee {
    int id;
    string name;
    Employee* next;
};

class HashTable {
private:
    Employee** table;
    int size;

    int hashFunction(int id) {
        return id % size;
    }

public:
    HashTable(int s) {
        size = s;
        table = new Employee*[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    void insertEmployee(int id, string name) {
        int index = hashFunction(id);
        Employee* newEmp = new Employee;
        newEmp->id = id;
        newEmp->name = name;
        newEmp->next = nullptr;

        if (table[index] == nullptr) {
            table[index] = newEmp;
        } else {
            Employee* temp = table[index];
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newEmp;
        }
        cout << "Employee added successfully.\n";
    }

    void searchEmployee(int id) {
        int index = hashFunction(id);
        Employee* temp = table[index];
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Employee Found!\n";
                cout << "ID: " << temp->id << " | Name: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Employee not found.\n";
    }

    void deleteEmployee(int id) {
        int index = hashFunction(id);
        Employee* temp = table[index];
        Employee* prev = nullptr;

        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Employee not found.\n";
            return;
        }

        if (prev == nullptr)
            table[index] = temp->next;
        else
            prev->next = temp->next;

        delete temp;
        cout << "Employee deleted successfully.\n";
    }

    void displayTable() {
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "]: ";
            Employee* temp = table[i];
            while (temp != nullptr) {
                cout << " -> (ID: " << temp->id << ", Name: " << temp->name << ")";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Employee* temp = table[i];
            while (temp != nullptr) {
                Employee* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] table;
    }
};

int main() {
    int n;
    cout << "Enter hash table size: ";
    cin >> n;
    HashTable ht(n);

    int choice;
    do {
        cout << "\n=== Employee Database ===\n";
        cout << "1. Insert Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Delete Employee\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin >> name;
            ht.insertEmployee(id, name);
        } 
        else if (choice == 2) {
            int id;
            cout << "Enter Employee ID to search: ";
            cin >> id;
            ht.searchEmployee(id);
        } 
        else if (choice == 3) {
            int id;
            cout << "Enter Employee ID to delete: ";
            cin >> id;
            ht.deleteEmployee(id);
        } 
        else if (choice == 4) {
            ht.displayTable();
        } 
        else if (choice == 5) {
            cout << "Exiting...\n";
        } 
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}

