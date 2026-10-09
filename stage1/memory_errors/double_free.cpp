#include <iostream>
int main() {
    int* p = new int(42);
    std::cout << *p <<"\n";
    delete p;
    delete p;
    return 0;
}