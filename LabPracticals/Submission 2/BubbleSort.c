#include<stdio.h>

int main()
{
    int A[100], n, i, j, temp; 
    printf("Enter number of elements: ");
    scanf("%d", &n); 
    printf("Enter %d Numbers: ", n); 
    for(i = 0; i < n; i++) scanf("%d", &A[i]); 
    for(i = 0 ; i < n - 1; i++){
        for(j = 0 ; j < n-i-1; j++){
            if(A[j] > A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    } 
    printf("Sorted Array: "); 
    for(i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
    return 0;
}