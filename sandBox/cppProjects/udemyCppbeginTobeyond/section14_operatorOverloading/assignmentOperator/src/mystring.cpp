#include <cstring>
#include <iostream>
#include "mystring.h"

// No args constructor

MyString::MyString () 
    : str {nullptr} {
    str = new char [1];
    *str = '\0';
}

MyString::MyString (const char *s) 
    : str {nullptr} {
    if (s == nullptr) {
        str = new char [1];
        *str = '\0';
    }
    else {
        str = new char[std::strlen(s)+1];
        std::strcpy(str, s);
    }
}
// copy constructor
MyString::MyString (const MyString &source) 
    : str {nullptr} {
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str, source.str);
    std::cout << "Copy constructor used" << std::endl;
}

// move constructor
MyString::MyString (MyString &&source)
    : str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

MyString::~MyString () {
    if (str == nullptr) {
        std::cout << "Destructor called for MyString: nullptr" << std::endl;
    }
    else {
        std::cout << "Destructor called for MyString: " << str << std::endl;
    }
    delete [] str;
}


// Copy Assignment

MyString &MyString::operator=(const MyString &rhs) {
    std::cout << "Copy Assignment: " << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete [] str;   // in this case, str == this->str == (*this).str
    str = new char [std::strlen(rhs.str) + 1]; // now allocating new memory for the string being copied
    std::strcpy(str, rhs.str); // go ahead and copy the string
    return *this;
}

// Move Assignement
MyString &MyString::operator=(MyString &&rhs) {
    std::cout << "Move Assignment: " << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete [] str; // 
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

void MyString::display () const {
    std::cout << str << " : " << get_length() << std::endl;
}

int MyString::get_length () const {
    return std::strlen(str);
}

const char *MyString::get_str() const {
    return str;
}