#include<iostream>
using namespace std;
void itermergeSort(int[], int);

int main(){
    int a[] = {10,1,3,2,90,30,0,9,2000};
    int n = sizeof(a)/sizeof(a[0]);
    itermergeSort(a, n);
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

//iterative merge sort
void itermergeSort(int A[], int n){
    int p,i,low,mid,high;
    for(p=2; p<=n; p*=2){
        for(i=0;i+p-1<n; i+=p){
            low = i;
            high = i+p-1;
            mid = (low+high)/2;
            merge(A, low, mid, high);
            
        }
        if(p/2 < n)
            merge(A,0, p/2, n-1);
    }

return;
}