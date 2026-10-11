#include "String.h"
#include <cstring>
String::String() {
    data_ = new char[1]; 
    data_[0] = '\0';
    size_ = 0;


}
String::~String() {
    delete[] data_;
}
size_t String::size() const {
    return size_;
}
bool String::empty() const {
    return size_ == 0;
}
const char* String::c_str() const {
    return data_;
}
String::String(const char* s) {
    if (s == nullptr) {
        data_ = new char[1]; 
        data_[0] = '\0';
        size_ = 0;
        return;
    }
    size_ = std::strlen(s);
    data_ = new char[size_ + 1];
    for(size_t i = 0; i < size_ + 1; i++) {
        data_[i] = *(s+i);
    }
    
}