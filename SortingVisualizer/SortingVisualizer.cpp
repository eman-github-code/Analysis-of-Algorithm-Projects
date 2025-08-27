#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// ---------- Utility ----------
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ---------- Merge Sort ----------
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    printArray(arr); // visualize step
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// ---------- Quick Sort ----------
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    printArray(arr); // step
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------- Heap Sort ----------
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        printArray(arr); // visualize step
    }
}

// ---------- Main Program ----------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Merge Sort\n";
    cout << "2. Quick Sort\n";
    cout << "3. Heap Sort\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    vector<int> arrCopy = arr;
    clock_t start, end;

    if (choice == 1) {
        cout << "\n--- Merge Sort Visualization ---\n";
        start = clock();
        mergeSort(arrCopy, 0, n - 1);
        end = clock();
    } else if (choice == 2) {
        cout << "\n--- Quick Sort Visualization ---\n";
        start = clock();
        quickSort(arrCopy, 0, n - 1);
        end = clock();
    } else if (choice == 3) {
        cout << "\n--- Heap Sort Visualization ---\n";
        start = clock();
        heapSort(arrCopy);
        end = clock();
    } else {
        cout << "Invalid choice!\n";
        return 0;
    }

    cout << "\nSorted Array: ";
    printArray(arrCopy);

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Execution Time: " << time_taken << " seconds\n";

    return 0;
}

