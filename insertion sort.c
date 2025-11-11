#include<stdio.h>
 
int main() { 
    // Declaring the variables 
    int n, now, i, j; 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 
    // Declaring and accepting the array 
    int data[n]; 
    printf("Enter %d elements: ", n); 
    for(i = 0; i < n; i++) { 
        scanf("%d", &data[i]); 
    } 
 
    // Applying insertion sort 
    for(i = 1; i < n; i++) { 
        now = data[i]; 
        for(j = i - 1; j >= 0 && data[j] > now; j--) { 
            data[j + 1] = data[j]; 
        } 
        data[j + 1] = now; 
    } 
 
    // Displaying the sorted array 
    printf("Sorted array is: "); 
    for(i = 0; i < n; i++) { 
        printf("%d ", data[i]); 
    } 
    printf("\n"); 
 
    return 0; 
} 
