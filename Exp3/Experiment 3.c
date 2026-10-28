#include <stdio.h>

void bubble(int s, int are[]) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < (s - 1); j++) {
            if (are[j] > are[j + 1]) {
                int temp = are[j];
                are[j] = are[j + 1];
                are[j + 1] = temp;
            }
        }
    }
}

void selection(int s, int ar[]) {
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

void insertion(int s, int ar[]) {
    for (int i = 1; i < s; i++) {
        int k = i;
        while (k > 0 && ar[k] < ar[k - 1]) {
            int temp = ar[k];
            ar[k] = ar[k - 1];
            ar[k - 1] = temp;
            k--;
        }
    }
}

// Quick Sort
void quick(int ar[], int low, int high) {
    if (low < high) {
        int pivot = ar[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (ar[j] < pivot) {
                i++;
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }

        int temp = ar[i + 1];
        ar[i + 1] = ar[high];
        ar[high] = temp;

        int p = i + 1;

        quick(ar, low, p - 1);
        quick(ar, p + 1, high);
    }
}

// Merge Sort
void merge(int ar[], int low, int mid, int high) {
    int temp[1000];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (ar[i] < ar[j])
            temp[k++] = ar[i++];
        else
            temp[k++] = ar[j++];
    }

    while (i <= mid)
        temp[k++] = ar[i++];

    while (j <= high)
        temp[k++] = ar[j++];

    for (i = low; i <= high; i++)
        ar[i] = temp[i];
}

void mergeSort(int ar[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(ar, low, mid);
        mergeSort(ar, mid + 1, high);
        merge(ar, low, mid, high);
    }
}

int main() {
    int size;
    printf("Enter Array Size: ");
    scanf("%d", &size);

    if (size <= 0 || size > 1000) {
        printf("Enter a size between 1 and 1000.\n");
        return 0;
    }

    int ar[size];
    int temp[size];

    printf("Enter Array Elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &ar[i]);
    }

    // Bubble Sort
    bubble(size, ar);
    printf("Sorted array by bubble sort: [");
    for (int i = 0; i < size; i++)
        printf("%d ", ar[i]);
    printf("]\n");

    // Selection Sort
    selection(size, ar);
    printf("Sorted array by selection sort: [");
    for (int i = 0; i < size; i++)
        printf("%d ", ar[i]);
    printf("]\n");

    // Insertion Sort
    insertion(size, ar);
    printf("Sorted array by insertion sort: [");
    for (int i = 0; i < size; i++)
        printf("%d ", ar[i]);
    printf("]\n");

    // Quick Sort
    quick(ar, 0, size - 1);
    printf("Sorted array by quick sort: [");
    for (int i = 0; i < size; i++)
        printf("%d ", ar[i]);
    printf("]\n");

    // Merge Sort
    mergeSort(ar, 0, size - 1);
    printf("Sorted array by merge sort: [");
    for (int i = 0; i < size; i++)
        printf("%d ", ar[i]);
    printf("]\n");

    return 0;
}
