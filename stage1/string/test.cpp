#include <iostream>
#include "String.h"

int main() {
    String a {};
    std::cout << a.size() << " " << a.empty() <<  " " << a.c_str()<< "\n";
    return 0;
}