#include<iostream>
using namespace std;

int part(int[], int, int);
void quickSort(int[], int, int);

int main(){
    int A[] = {50, 70, 60, 90, 40, 80, 10, 20, 30};
    int n= sizeof(A)/sizeof(A[0]);   
    quickSort(A, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}


int part(int A[], int l, int h) {
    int pivot = A[l];
    int i = l - 1;
    int j = h + 1;

    while (true) {
        
        do {i++;} while (A[i] < pivot);
        do {j--;} while (A[j] > pivot);

        if (i >= j)
            return j;

        swap(A[i], A[j]);
    }
}
void quickSort(int A[], int l, int h){
    if(l<h){
        int j = part(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
    
}
