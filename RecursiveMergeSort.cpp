#include<iostream>
using namespace std;
void recurmergeSort(int[], int, int);

int main(){
    int a[] = {10,1,3,2,90,30,0,9,2000};
    int n = sizeof(a)/sizeof(a[0]);
    recurmergeSort(a, 0,7);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

}
//merging function
void merge(int A[], int low, int mid, int high){
    int i,j,k;
    int B[high+1];
    i = low; j=mid+1; k=low;
    while(i<= mid && j<= high){
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
        for(; i<=mid; i++)
            B[k++] = A[i];
        for(; j<=high; j++)
            B[k++] = A[j];
        for(i=low; i<=high; i++)
            A[i] = B[i];
    return;
}
//recursive merge sorting
void recurmergeSort(int A[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        recurmergeSort(A, low, mid);
        recurmergeSort(A, mid+1, high);
        merge(A, low, mid, high);


    }
};