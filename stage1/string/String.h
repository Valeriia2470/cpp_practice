#pragma once
#include <cstddef>

class String {
public:
    String();                      // empty string
    String(const char* s);         // иfrom C-string
    ~String();                     // free up memory

    size_t size() const;
    bool empty() const;
    const char* c_str() const;

private:
    char* data_;
    size_t size_;
};