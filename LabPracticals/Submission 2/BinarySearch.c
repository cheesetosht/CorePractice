#include <stdio.h>

int main()
{
    int first, last, mid, n, search, A[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);

    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    printf("Enter value to find: ");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    mid = (first+last)/2;

    while (first <= last){
        if (A[mid] < search){
            first = mid + 1;
        }
        else if(A[mid] == search){
            printf("%d found at location %d\n", search, mid+1);
            break;
        }
        else{
            last = mid - 1;
        }
        mid = (first + last)/2;
    }
    if (first > last){
        printf("Not found!\n", search);
    }
    return 0;
}