#include <iostream>
#include <utility>
void swap_ptr(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}
void swap_ref(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    int x = 3;
    int y = 7;
    swap_ptr(&x, &y);
    std::cout << x << " " << y << "\n";
    swap_ref(x, y);
    std::cout << x << " " << y << "\n";
    std::swap(x,y);
    std::cout << x << " " << y << "\n";
    return 0;
}