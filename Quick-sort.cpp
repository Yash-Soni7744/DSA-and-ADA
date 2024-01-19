#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void quickSort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int A[] = {23, 32, 54, 33, 12, 1, 2, 57};
    int p = 0;
    int r = sizeof(A) / sizeof(int) - 1;
    quickSort(A, p, r);

    // Display the sorted array
    for (int i = 0; i <= r; i++) {
        cout << A[i] << " ";
    }

    return 0;
}
