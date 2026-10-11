#include "String.h"
#include <cstring>
#include <ostream>
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
String::String(const String& other) {
    data_ = new char[other.size_ +1];
    for(size_t i = 0; i < other.size_ + 1; i++ ) {
        data_[i] = other.data_[i];
    }
    size_ = other.size_;
}
String& String::operator = (const String& other) {
    if(this == &other) {
        return *this;
    }
    char* new_data = new char[other.size_ + 1];
    for(size_t i = 0; i < other.size_ + 1; i++ ) {
        new_data[i] = other.data_[i];
    }
    delete[] data_;
    data_ = new_data;
    size_ = other.size_;
    return *this;
}
String::String(String&& other) noexcept{
    data_ = other.data_;
    size_ = other.size_;
    other.data_ = nullptr;
    other.size_ = 0;
}
String& String::operator = (String&& other) noexcept {
    if(this == &other) {
        return *this;
    }
    delete[] data_;
    data_ = other.data_;
    size_ = other.size_;
    other.data_ = nullptr;
    other.size_ = 0;
    return *this;

}
char& String::operator[](size_t i) { // return data_[i]
    return data_[i];
}
const char& String::operator[](size_t i) const { // return data_[i]
    return data_[i];
}
bool String::operator==(const String& other) const {
    if(size_ != other.size_) {
        return false;
    }
    for(size_t i = 0; i < size_; i++) {
        if(data_[i] != other.data_[i] ) {
            return false;
        }
    }
    return true;

}
void String::clear() {
    delete[] data_;
    size_ = 0;
    data_ = new char[1];
    data_[0] = '\0';

}
void String::append(const String& other) {
    char* new_data = new char[size_ + other.size_ + 1];
    for(size_t i = 0; i < size_; i++) {
        new_data[i] = *(data_ + i);
    }
    for(size_t i = size_; i < (size_ + other.size_ + 1); i++) {
        new_data[i] = other.data_ [i - size_];
    }
    delete[] data_;
    data_ = new_data;
    size_ =  other.size_ + size_;
}
String& String::operator+=(const String& other) {
    String::append(other);
    return *this;
}
String operator+(const String& a, const String& b) {
    String result = a;
    result += b;
    return result; 
}
std::ostream& operator<<(std::ostream& out, const String& s) {
    out << s.c_str();
    return out;
}