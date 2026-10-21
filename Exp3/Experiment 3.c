// Experiment No: 03
// Title: Perform Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, and Merge Sort using C
// Aim: To implement and understand different sorting algorithms in C: Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, and Merge Sort.

 #include <stdio.h>

void bubble(int s, int are[]) {
    for (int i = 0; i < s; i++){ // i = No. of Passes
        for (int j = 0; j < (s - 1); j++){  // j = comparison of array elements 
            if (are[j] > are[j + 1]) {
                int temp = are[j];
                are[j] = are[j + 1];
                are[j + 1] = temp;
            }
        }
    }
}

void selection(int s, int ar[]){
    for (int i = 0; i < s - 1; i++) {
        int min = i;
        for (int j = i + 1; j < s; j++) {
            if (ar[j] < ar[min]) {
                min = j;
            }
        }
        int temp = ar[i];
        ar[i] = ar[min];
        ar[min] = temp;
    }
}

void insertion(int s, int ar[]){
    for(int i; i < s; i++){
        int k = i;
        while(ar[k] < ar[k - 1]){
            int temp = ar[k];
            ar[k] = ar[k - 1];
            ar[k - 1] = temp;
            k--;
        }
    }
}

int main() {
    int size, ar[size];
    printf("Enter Array Size: ");
    scanf("%d", &size);

    printf("Enter Array Elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &ar[i]);
    }
    // Bubble Sort
    bubble(size, ar);
    printf("Sorted array by bubble sorted: [");
    for (int i = 0; i < size; i++) {
        printf("%d ", ar[i]);
    }
    printf("]\n");
    // Selection Sort
    selection(size, ar);
    printf("Sorted array by selection sorted: [");
    for (int i = 0; i < size; i++) {
        printf("%d ", ar[i]);
    }
    printf("]\n");
    // Insertion Sort
    insertion(size, ar);
    printf("Sorted array by insertion sorted: [");
    for (int i = 0; i < size; i++) {
        printf("%d ", ar[i]);
    }
    printf("]\n");

    return 0;
}