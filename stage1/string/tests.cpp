#include "String.h"
#include <cassert>
#include <iostream>
#include <utility>
 
// 1. Конструкторы
static void test_constructors() {
    String a;
    assert(a.size() == 0);
    assert(a.empty());
    assert(a == String(""));
 
    String b("hello");
    assert(b.size() == 5);
    assert(!b.empty());
    assert(b == String("hello"));
 
    String c("");
    assert(c.size() == 0);
    assert(c.empty());
 
    String d(nullptr);
    assert(d.size() == 0);
    assert(d.empty());
    assert(d == a);
}
 
// 2. Копирование
static void test_copy_constructor() {
    String x("abc");
    String y = x;
    assert(y == x);
    assert(y.size() == 3);
    assert(x.c_str() != y.c_str());   
 
    y.clear();                        
    assert(y.empty());
    assert(x == String("abc"));      
 
    String z = x;
    z[0] = 'X';
    assert(z == String("Xbc"));
    assert(x == String("abc"));
}
 
// 3. Присваивание копированием
static void test_copy_assignment() {
    String x("hi");
    String z;
    z = x;
    assert(z == x);
    assert(z.c_str() != x.c_str());
 
    
    String shortStr("hi");
    String longStr("a much longer string");
    shortStr = longStr;
    assert(shortStr == longStr);
    longStr = String("ok");           
    assert(longStr == String("ok"));
 
    
    String s("self");
    String& ref = s;
    s = ref;
    assert(s == String("self"));
    assert(s.size() == 4);
 
    
    String t("not empty");
    String empty;
    t = empty;
    assert(t.empty());
}
 
// 4. Перемещение
static void test_move() {
    String x("hi");
    String w = std::move(x);
    assert(w == String("hi"));
    assert(w.size() == 2);
    assert(x.size() == 0);            
 
    String p("abc");
    String v("old value");
    v = std::move(p);
    assert(v == String("abc"));
    assert(v.size() == 3);
    assert(p.size() == 0);
}
 
// 5. Операторы и методы
static void test_index() {
    String s("abc");
    assert(s[0] == 'a');
    assert(s[2] == 'c');
    s[1] = 'X';                       
    assert(s == String("aXc"));
 
    const String k("const");
    assert(k[0] == 'c');              
    assert(k[4] == 't');
}
 
static void test_equality() {
    assert(String("abc") == String("abc"));
    assert(!(String("abc") == String("abd")));   
    assert(!(String("abc") == String("ab")));    
    assert(!(String("ab") == String("abc")));
    assert(String() == String(""));              
}
 
static void test_append() {
    String s("ab");
    s.append(String("cd"));
    assert(s.size() == 4);
    assert(s == String("abcd"));
 
    s.append(s);                      
    assert(s.size() == 8);
    assert(s == String("abcdabcd"));
 
    String e;
    e.append(String("x"));
    assert(e == String("x"));
    assert(e.size() == 1);
 
    String f("y");
    f.append(String());               
    assert(f == String("y"));
}
 
static void test_plus_equals() {
    String a("ab");
    String b("cd");
    a += b;
    assert(a == String("abcd"));
    assert(b == String("cd"));        
    a += String("!") += String("?");  
    assert(a == String("abcd!?"));
 
    a += a;
    assert(a == String("abcd!?abcd!?"));
}
 
static void test_plus() {
    String a("ab");
    String b("cd");
    String c = a + b;
    assert(c == String("abcd"));
    assert(a == String("ab"));        
    assert(b == String("cd"));
 
    String d = a + b + String("!");
    assert(d == String("abcd!"));
 
    assert((String() + String()).empty());
    assert(String() + String("x") == String("x"));
    assert(String("x") + String() == String("x"));
}
 
static void test_clear() {
    String s("abc");
    s.clear();
    assert(s.size() == 0);
    assert(s.empty());
    assert(s == String());
 
    s.clear();                        
    assert(s.empty());
 
    s.append(String("again"));        
    assert(s == String("again"));
}
 
int main() {
    test_constructors();
    test_copy_constructor();
    test_copy_assignment();
    test_move();
    test_index();
    test_equality();
    test_append();
    test_plus_equals();
    test_plus();
    test_clear();
 
    std::cout << "All tests passed\n";
    return 0;
}
 