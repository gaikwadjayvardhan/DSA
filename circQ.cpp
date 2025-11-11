#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear + 1 == front);
    }

    bool isEmpty() {
        return front == -1;
    }

    void addJob(int jobID) {
        if (isFull()) {
            cout << "Queue is full! Cannot add job.\n";
            return;
        }

        if (front == -1) {  // first element
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = jobID;
        cout << "Job " << jobID << " added.\n";
    }

    void removeJob() {
        if (isEmpty()) {
            cout << "Queue is empty! No job to remove.\n";
            return;
        }

        cout << "Job " << arr[front] << " removed.\n";

        if (front == rear) {  // only one element
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void displayJobs() {
        if (isEmpty()) {
            cout << "No jobs in queue.\n";
            return;
        }

        cout << "Jobs in Queue: ";

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the maximum number of jobs: ";
    cin >> n;

    CircularQueue q(n);

    int choice, jobID;

    do {
        cout << "\nJob Scheduling System\n";
        cout << "1. Add Job\n";
        cout << "2. Remove Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Job ID to add: ";
            cin >> jobID;
            q.addJob(jobID);
            break;

        case 2:
            q.removeJob();
            break;

        case 3:
            q.displayJobs();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
