#include "my_string.h"
#include <stdexcept>

namespace my_std {

String::String() {
  arr = new char[1];
  arr[0] = '\0';   // Означает конец строки
  size = 0;
}

String::String(const char* str) {
  size = std::strlen(str);
  arr = new char[size + 1];  // +1, т.к еще под '\0'
  for (size_t i = 0; i < size; ++i) {
    arr[i] = str[i];
  }
  arr[size] = '\0';
}

String::String(const String& other) {
  size = other.size;
  arr = new char[size + 1];
  for (size_t i = 0; i < size; ++i) {
    arr[i] = other.arr[i];
  }
  arr[size] = '\0';
}

String::String(size_t count, char ch) {
  arr = new char[count + 1];
  for (int i = 0; i < count; ++i) {
    arr[i] = ch;
  }
  arr[count] = '\0';
}

String::String(const char* str, size_t count) {
  arr = new char[count + 1];
  for (int i = 0; i < count; ++i) {
    arr[i] = str[i];
  }
  arr[count] = '\0';
}

String::String(std::initializer_list<char> init) {
  size = init.size();
  arr = new char[size + 1];
  size_t i = 0;
  for (auto it = init.begin(); it != init.end(); ++it) {
    arr[i++] = *it;
  }
  arr[size] = '\0';
}


// Деструктор
String::~String() {
  delete[] arr;
}


// Инфорация о размере
bool String::IsEmpty() const {
  return arr[0] == '\0';
  //return std::strlen(arr) == 0;
}

size_t String::GetSize() const {
  return size;
}

// Методы доступа
char String::at(size_t index) const {
  if (size <= index) {
    throw std::out_of_range("String index out of range");
  }
  return arr[index];
}

char& String::operator[](size_t index) {
  return arr[index];
}

char String::front() const {
  return arr[0];
}

char String::back() const {
  return arr[size-1];
}

const char* String::c_str() const {
  return arr;
}

bool String::operator==(const String& other) const {
    bool check = true;
    if (size != other.GetSize()) {
      check = false;
      return check;
    }
    for (size_t i = 0; i < size; ++i) {
      if (arr[i] != other.c_str()[i]) {
        check = false;
        return check;
      }
    }
    return check;
  }

}
