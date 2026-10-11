#include <iostream>
#include "String.h"

int main() {
    String a {};
    std::cout << a.size() << " " << a.empty() <<  " " << a.c_str()<< "\n";
    String b{"Hello"};
    String c {nullptr};
    String d{""};
    std::cout << b.size() << " " << b.empty() << " [" << b.c_str() << "]\n";   
    std::cout << c.size() << " " << c.empty() << " [" << c.c_str() << "]\n";   
    std::cout << d.size() << " " << d.empty() << " [" << d.c_str() << "]\n";
    String x {"hi"};
    String y = x;
    std::cout << y.size() << " " << y.empty() << " [" << y.c_str() << "]\n";
    std::cout << (void*)x.c_str() << " " << (void*)y.c_str() << "\n";
    return 0;
}