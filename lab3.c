#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


int quickselect(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int pivotIndex = partition(arr, low, high);
    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickselect(arr, low, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, high, k);
    }
}


int find_median(int arr[], int start, int end) {
    int size = end - start + 1;
    int temp[size];
    
    
    for (int i = 0; i < size; i++) {
        temp[i] = arr[start + i];
    }
    
    
    return quickselect(temp, 0, size - 1, size / 2);
}


int find_sum_after_operations(int arr[], int n) {
    int op_count = n - 2; // Number of operations
    
    // Loop through the operations
    for (int op = 0; op < op_count; op++) {
        int medians[n];  // Array to store medians
        int m_count = 0;     // Count of medians

        // Find medians of all odd-length subarrays greater than size 2
        for (int size = 3; size <= n - op; size += 2) {  // Only odd sizes
            for (int i = 0; i <= (n - op) - size; i++) {
                int median = find_median(arr, i, i + size - 1);
                medians[m_count++] = median;
            }
        }

        // Find the minimum median
        int min_median = medians[0];
        for (int i = 1; i < m_count; i++) {
            if (medians[i] < min_median) {
                min_median = medians[i];
            }
        }

        // Remove the first occurrence of the minimum median
        for (int i = 0; i < n - op; i++) {
            if (arr[i] == min_median) {
                // Shift the array to remove the element
                for (int j = i; j < n - op - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                break;
            }
        }
    }

    // Return the sum of the last two elements
    return arr[0] + arr[1];
}

int main() {
    int T;
    scanf("%d", &T);  // Read the number of test cases

    while (T--) {
        int N;
        scanf("%d", &N);  // Read the size of the array

        int arr[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);  // Read the elements of the array
        }

        // Calculate the result for the current test case
        int result = find_sum_after_operations(arr, N);
        printf("%d\n", result);  // Print the result
    }

    return 0;
}
