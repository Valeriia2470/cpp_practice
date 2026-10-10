#include <iostream>

int main() {
    int n {};
    std::cout << "Enter n :" << "\n";
    
    if(!(std::cin >> n) || n < 0) {
        std::cout << "Invalid input" <<"\n";
        return 1;
    }
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i*i;
    }
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " "; 
    }
    std::cout << "\n";
    delete[] arr;
    arr = nullptr;
    return 0;
}