#include <iostream>
#include <utility>
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
    String m("hi");
    String z("longer text");
    z = m;
    std::cout << z.size() << " [" << z.c_str() << "]\n";  
    z = z;
    std::cout << z.size() << " [" << z.c_str() << "]\n";  
    String l("hi");
    String w = std::move(l);   
    std::cout << w.size() << " [" << w.c_str() << "]\n";   

    String v;
    String p("abc");
    v = std::move(p);          
    std::cout << v.size() << " [" << v.c_str() << "]\n";
    String n("abc");
    std::cout << (n == String("abc")) << (n == String("abd")) << (n == String("ab")) << "\n";   // 100
    n.clear();
    std::cout << n.size() << n.empty() << "[" << n.c_str() << "]\n"; 
    String s("ab");
    s.append(String("cd"));
    std::cout << s.size() << " " << s.c_str() << "\n";   // 4 abcd
    s.append(s);
    std::cout << s.size() << " " << s.c_str() << "\n";   // 8 abcdabcd
    String e;
    e.append(String("x"));
    std::cout << e.size() << " " << e.c_str() << "\n";   // 1 x   
    return 0;
}