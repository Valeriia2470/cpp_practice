#include <iostream>
#include <cstddef>
void find_min_max(const int* arr, size_t n, int& min, int& max) {
    if (n == 0) {
        return;
    }
    min = *(arr);
    max = *(arr);

    for(size_t i = 1; i < n; i++) {
        if (*(arr+i) > max) {
            max = *(arr+i);
        }
        if (*(arr+i) < min) {
            min = *(arr+i);
        }
    }
}
int main() {
    int arr[] = {4, -2, 9, 0, 7, -5, 3};
    int mn = 0;
    int mx = 0;
    find_min_max(arr, sizeof(arr) / sizeof(arr[0]), mn, mx);
    std::cout << mn << " " << mx << "\n";
    return 0;
}