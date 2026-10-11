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

    return 0;
}