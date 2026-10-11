#pragma once
#include <cstddef>

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

private:
    char* data_;
    size_t size_;
};