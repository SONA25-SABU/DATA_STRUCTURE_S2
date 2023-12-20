#include <stdio.h>

// Function prototypes
int linearSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons);
int sentinelSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons);
int binarySearch(int arr[], int low, int high, int key, int *elementComparisons, int *indexComparisons);
void bubbleSort(int arr[], int n, int *comparisons, int *dataTransfers);
void insertionSort(int arr[], int n, int *comparisons, int *dataTransfers);

int main() {
    int arr[] = {10, 5, 8, 20, 2, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20;

    // Linear Search
    int linearElementComparisons = 0, linearIndexComparisons = 0;
    int linearIndex = linearSearch(arr, n, key, &linearElementComparisons, &linearIndexComparisons);
    printf("Linear Search:\n");
    printf("Element found at index %d\n", linearIndex);
    printf("Element Comparisons: %d\nIndex Comparisons: %d\n\n", linearElementComparisons, linearIndexComparisons);

    // Sentinel Search
    int sentinelElementComparisons = 0, sentinelIndexComparisons = 0;
    int sentinelIndex = sentinelSearch(arr, n, key, &sentinelElementComparisons, &sentinelIndexComparisons);
    printf("Sentinel Search:\n");
    printf("Element found at index %d\n", sentinelIndex);
    printf("Element Comparisons: %d\nIndex Comparisons: %d\n\n", sentinelElementComparisons, sentinelIndexComparisons);

    // Bubble Sort
    int bubbleComparisons = 0, bubbleDataTransfers = 0;
    bubbleSort(arr, n, &bubbleComparisons, &bubbleDataTransfers);
    printf("Bubble Sort:\n");
    printf("Comparisons: %d\nData Transfers: %d\n\n", bubbleComparisons, bubbleDataTransfers);

    // Insertion Sort
    int insertionComparisons = 0, insertionDataTransfers = 0;
    insertionSort(arr, n, &insertionComparisons, &insertionDataTransfers);
    printf("Insertion Sort:\n");
    printf("Comparisons: %d\nData Transfers: %d\n\n", insertionComparisons, insertionDataTransfers);

    // Binary Search (assuming the array is sorted)
    int binaryElementComparisons = 0, binaryIndexComparisons = 0;
    int binaryIndex = binarySearch(arr, 0, n - 1, key, &binaryElementComparisons, &binaryIndexComparisons);
    printf("Binary Search:\n");
    printf("Element found at index %d\n", binaryIndex);
    printf("Element Comparisons: %d\nIndex Comparisons: %d\n", binaryElementComparisons, binaryIndexComparisons);

    return 0;
}

int linearSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons) {
	int i;
    for ( i = 0; i < n; i++) {
        (*elementComparisons)++;
        if (arr[i] == key) {
            (*indexComparisons)++;
            return i;
        }
        (*indexComparisons)++;
    }
    return -1;
}

int sentinelSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons) {
    // Adding a sentinel element at the end
    int lastElement = arr[n - 1];
    arr[n - 1] = key;

    int i = 0;
    while (arr[i] != key) {
        (*elementComparisons)++;
        i++;
    }

    // Restore the last element
    arr[n - 1] = lastElement;

    // If the element is found at the last position (n-1), return -1 (not found)
    if (i == n - 1)
        return -1;
    
    (*indexComparisons)++;
    return i;
}

int binarySearch(int arr[], int low, int high, int key, int *elementComparisons, int *indexComparisons) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        (*elementComparisons)++;
        if (arr[mid] == key) {
            (*indexComparisons)++;
            return mid;
        }

        (*indexComparisons)++;
        if (arr[mid] < key)
            return binarySearch(arr, mid + 1, high, key, elementComparisons, indexComparisons);

        return binarySearch(arr, low, mid - 1, key, elementComparisons, indexComparisons);
    }

    return -1;
}

void bubbleSort(int arr[], int n, int *comparisons, int *dataTransfers) {
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*dataTransfers)++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int *comparisons, int *dataTransfers) {
	int i;
    for ( i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        (*comparisons)++;
        while (j >= 0 && arr[j] > key) {
            // Shift the greater elements to the right
            arr[j + 1] = arr[j];
            (*dataTransfers)++;
            j--;
        }

        // Place the key at its correct position
        arr[j + 1] = key;
        (*dataTransfers)++;
    }
}
