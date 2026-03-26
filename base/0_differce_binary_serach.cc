#include <algorithm>
#include <iostream>

const int N = 100010;

int find_first(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (arr[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int find_last(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (arr[mid] <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    srand(time(0));
    int arr[N];
    int n = 1010;
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 500;
    }

    std::ranges::sort(arr, arr + n);

    int x = rand() % 500;

    int first = find_first(arr, n, x);
    int last = find_last(arr, n, x);

    int cpp_first = std::ranges::lower_bound(arr, arr + n, x) - arr;
    int cpp_last = std::ranges::upper_bound(arr, arr + n, x) - arr;

    std::cout << "Custom first: " << first << ", Custom last: " << last
              << std::endl;
    std::cout << "C++ first: " << cpp_first << ", C++ last: " << cpp_last
              << std::endl;

    return 0;
}