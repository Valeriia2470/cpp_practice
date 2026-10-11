#pragma once
#include <cstddef>
#include <iosfwd>

class String {
public:
    String();                      // empty string
    String(const char* s);         // иfrom C-string
    ~String();   
    String(const String& other);
    String& operator=(const String& other);
    String(String&& other) noexcept;
    String& operator=(String&& other) noexcept;                 // free up memory

    size_t size() const;
    bool empty() const;
    const char* c_str() const;
    char& operator[] (size_t i);
    const char& operator[] (size_t i) const;
    bool operator == (const String& other) const;
    String& operator+=(const String& other);
    void append(const String& other);
    void clear();

private:
    char* data_;
    size_t size_;
};
std::ostream& operator<<(std::ostream& out, const String& s);
String operator+(const String& a, const String& b);