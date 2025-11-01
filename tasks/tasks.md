# **Класс "String"**

**Общие требования:**

- Внимательно c заданием перед началом работы
- Соблюдайте стиль кода и требования к именованию классов, методов и переменных
- `Запрещено` использовать `std::string` внутри реализации (только `char*` и C-строки)
- Папка `build` не должна находиться в репозитории
- Материал по строкам:
  - [cppreference](https://en.cppreference.com/w/cpp/string/basic_string.html).
  - [Metanit](https://metanit.com/cpp/tutorial/12.1.php).

**Структура проекта:**

```text
project/
├── Makefile              # Основной Makefile
├── include/              # Заголовочные файлы (.h)
│   └── my_string.h
├── src/                  # Исходный код (.cc)
│   └── my_string.cc
├── test/                 # Тесты
├── materials/            # Учебные материалы
└── build/                # Автоматически генерируемая папка
    ├── obj/
    │   └── my_string.o   # Объектный файл
    ├── test/
    │   └── test_runner   # Исполняемый файл тестов
    └── coverage/
        └── index.html    # Отчёт о покрытии кода
```

**Описание структуры:**

- **`include/`** - содержит все заголовочные файлы (`.h`). Эти файлы включают объявления классов, функций и пространств имен. В данном задании реализовать my_string.h
- **`src/`** - содержит файлы исходного кода (`.cc`). Здесь находится реализация методов, объявленных в заголовочных файлах. В данном задании реализовать my_string.cc
- **`test/`** - содержит файлы с unit-тестами для проверки корректности реализации.
- **`build/`** - автоматически создаваемая папка для всех сгенерированных файлов.
  - **`build/obj/`** - скомпилированные объектные файлы (`.o`)
  - **`build/test/`** - исполняемые файлы тестов
  - **`build/coverage/`** - HTML-отчёты о покрытии кода тестами

## Задача

Реализовать свой аналог класса `std::string` с базовым функционалом в собственном пространстве имен.

## Технические требования

**Пространство имен и класс:**

- Использовать `namespace my_std` для изоляции своего кода
- Создать класс `String`

**Конструкторы и деструктор:**

- `String()` - конструктор по умолчанию (создает пустую строку)
- `String(const char* str)` - конструктор от C-строки
- `String(const String& other)` - конструктор копирования
- `String(size_t count, char ch)` - конструктор из `count` копий символа `ch`
- `String(const char* str, size_t count)` - конструктор из первых `count` символов C-строки
- `String(std::initializer_list<char> init)` - конструктор из списка инициализации
- `~String()` - деструктор

**Операторы присваивания:**

- `String& operator=(const String& other)` - оператор присваивания
- `String& operator=(const char* str)` - оператор присваивания от C-строки
- `String& operator=(char ch)` - оператор присваивания символам
- `String& operator=(std::initializer_list<char> init)` - оператор присваивания от `initializer_list`

**Методы получения размера:**

- `size_t size() const` - возвращает длину строки
- `bool empty() const` - проверяет пуста ли строка

**Методы доступа:**

- `char at(size_t index) const` - доступ к символу по индексу с проверкой границ
- `char& operator[](size_t index)` - оператор доступа по индексу
- `char front() const` - первый символ
- `char back() const` - последний символ
- `const char* c_str() const` - возвращает C-строку

**Модификаторы:**

- `void clear()` - очищает содержимое
- `void push_back(char c)` - добавляет символ в конец
- `void pop_back()` - удаляет последний символ
- `String& append(const String& str)` - добавляет строку в конец
- `String& append(const char* str)` - добавляет C-строку в конец
- `String& append(size_t count, char c)` - добавляет `count` копий символа
- `String& operator+=(const String& str)` - оператор +=
- `String& operator+=(const char* str)` - оператор += для C-строки
- `String& operator+=(char c)` - оператор += для символа
- `String& insert(size_t index, const String& str)` - вставляет строку в позицию
- `String& insert(size_t index, const char* str)` - вставляет C-строку в позицию
- `String& insert(size_t index, size_t count, char c)` - вставляет `count` копий символа
- `String& erase(size_t index, size_t count)` - удаляет символы
- `String& replace(size_t pos, size_t count, const String& str)` - заменяет часть строки
- `String& replace(size_t pos, size_t count, const char* str)` - заменяет часть на C-строку
- `void resize(size_t new_size)` - изменяет размер строки
- `void resize(size_t new_size, char c)` - изменяет размер с заполнением символом
- `void swap(String& other)` - обменивает содержимое с другой строкой

**Операторы сравнения:**

- `bool operator==(const String& other) const`
- `bool operator!=(const String& other) const`
- `bool operator<(const String& other) const`
- `bool operator>(const String& other) const`
- `bool operator<=(const String& other) const`
- `bool operator>=(const String& other) const`

**Поиск:**

- `size_t find(const String& substr) const` - поиск подстроки
- `size_t find(const char* substr) const` - поиск C-строки
- `size_t find(char c) const` - поиск символа

**Ввод/вывод:**

- `friend std::ostream& operator<<(std::ostream& os, const String& str)`
- `friend std::istream& operator>>(std::istream& is, String& str)`

## **Цели для Makefile:**

**Основные цели:**

- `make my_string.o` - компиляция объектного файла `my_string.o`
- `make test` - компиляция и запуск unit-тестов
- `make coverage` - генерация HTML-отчёта о покрытии кода тестами
- `make check-clang-format` - проверка стиля кода с помощью clang-format
- `make check-leaks` - проверка утечек памяти (с использованием valgrind или leaks)
- `make all` - компиляция `my_string.o` и запуск тестов
- `make clean` - полная очистка всех сгенерированных файлов в папке `build/`

**Требования к тестированию:**

- Использовать Google Test framework
- Покрытие кода тестами должно быть ≥ 80%
- Тесты должны проверять все конструкторы, операторы и методы
- Обязательны тесты на граничные случаи
