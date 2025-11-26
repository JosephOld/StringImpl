#include <iostream>
#include <cstring>
#ifndef MY_STRING
#define MY_STRING

namespace my_std {

class String {
 private:
  char* arr;
  size_t size;
  public:
   // Конструкторы и деструкторы
   String();
   String(const char* str);
   String(const String& other);
   String(size_t count, char ch);     // size_t - это тип данных
   String(const char* str, size_t count);
   String(std::initializer_list<char> init);
   ~String();

    // Операторы присваивания
   String& operator=(const String& other);
   String& operator=(const char* str);
   String& operator=(char ch);
   String& operator=(std::initializer_list<char> init);

  // Методы
  size_t GetSize() const;

  bool IsEmpty() const;

  // Методы доступа
  char at(size_t index) const;
  char& operator[](size_t index);
  char front() const;
  char back() const;
  const char* c_str() const;

  // Операторы сравнения
  bool operator==(const String& other) const;
};

}

#endif