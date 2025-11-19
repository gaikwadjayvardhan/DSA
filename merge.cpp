
#include<iostream>
using namespace std;


void display(int ar[], int n) {
    for(int i = 0; i < n; i++) {
        cout << ar[i] << "\t";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int arr[], int n){
    
}


//quick sort
int Partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while(true){
        do{i++;} while(arr[i]< pivot);
        do{j--;} while(arr[j]> pivot);
        if(i>=j){
            return j;
        }
        swap(arr[i], arr[j]);
    }

}

void quickSort(int arr[], int low, int high){
    // int j;
    if(low<high){
        int j = Partition(arr, low, high);
        quickSort(arr, low, j);
        quickSort(arr, j+1, high);

    }
}


int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    display(arr, n);
    return 0;
}
