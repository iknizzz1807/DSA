#include <bits/stdc++.h>

using namespace std;

int binarySearch(const int arr[], int n, int x) {
    int l = 0;
    int r = n - 1;
    while(l <= r) {
        int m = l + ((r - l) / 2);
        if(arr[m] == x) return m;
        else if(arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int n; cin >> n; int x;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    cout << binarySearch(arr, n, x);
    return 0;
}