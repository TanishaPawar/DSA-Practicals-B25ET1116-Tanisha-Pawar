// Experiment No: 02
// Title: Perform recursive binary search using C. 
// Aim: To write a C program to perform binary search using recursion on a sorted array of integers.

#include <stdio.h>

int binarySearch(int a[], int start, int end, int num)
{
    if (start > end){
        return -1;
    }

    int mid = (start + end) / 2;

    if (num == a[mid]) {
        return mid;
    }

    else if (num < a[mid]) {
        return binarySearch(a, start, mid - 1, num);
    }

    else{
        return binarySearch(a, mid + 1, end, num);
    }
}

int main()
{
    int i, n, start, end, num;
    int found;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter any %d numbers in ascending order:\n", n);

    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter any number from inputted array: ");
    scanf("%d", &num);

    start = 0;
    end = n - 1;

    found = binarySearch(a, start, end, num);

    if (found != -1){
        printf("Element found at index position: %d", found);
    }
    else{
        printf("Element not found in array");
    }

    return 0;
}
