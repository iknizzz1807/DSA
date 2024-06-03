#include <iostream>

using namespace std;

// Non recursive
int binarySearch(const int arr[], int n, int x) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int m = l + ((r - l) / 2);
        if (arr[m] == x) return m;
        else if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

// Recursive
int binarySearch(const int arr[], int l, int r, int x) {
    if (r >= l) {
        int m = l + (r - l) / 2;
        if (x == arr[m]) return m;
        else if (x > arr[m]) return binarySearch(arr, m + 1, r, x);
        else return binarySearch(arr, l, m - 1, x);
    }
    return -1;
}

int main() {
    // Input array
    int n;
    cin >> n;
    int x;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    cout << binarySearch(arr, n, x) << endl; // non recursive
    cout << binarySearch(arr, 0, n - 1, x); // recursive
    return 0;
}
