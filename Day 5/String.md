# README: Strings in C++

## Overview

In C++, strings are used to represent sequences of characters. C++ provides multiple ways to handle strings, primarily through C-style strings (null-terminated character arrays) and the `std::string` class from the C++ Standard Library. This README covers both methods, focusing on the `std::string` class for its ease of use and safety.

---

## Table of Contents

1. [C-Style Strings](#c-style-strings)
   - [Definition](#definition)
   - [Common Operations](#common-operations)
2. [C++ `std::string` Class](#c-stdstring-class)
   - [Definition](#definition-1)
   - [Creating and Initializing Strings](#creating-and-initializing-strings)
   - [Accessing Characters](#accessing-characters)
   - [Modifying Strings](#modifying-strings)
   - [String Operations](#string-operations)
   - [String Comparisons](#string-comparisons)
   - [String Functions](#string-functions)
   - [String Iterators](#string-iterators)
   - [Capacity and Size](#capacity-and-size)
3. [Conversion Between `std::string` and C-Style Strings](#conversion-between-stdstring-and-c-style-strings)
4. [Examples](#examples)
5. [References](#references)

---

## C-Style Strings

### Definition

C-style strings are arrays of characters ending with a null character (`'\0'`).

```cpp
char str[] = "Hello";
```

### Common Operations

1. **Initialization**:
   ```cpp
   char str1[] = "Hello";
   char str2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
   ```

2. **Accessing Elements**:
   ```cpp
   char first = str1[0]; // 'H'
   ```

3. **Standard Library Functions**:
   ```cpp
   #include <cstring>
   int len = strlen(str1);            // Length of string
   strcpy(dest, src);                 // Copy string
   strcat(str1, str2);                // Concatenate strings
   int cmp = strcmp(str1, str2);      // Compare strings
   ```

4. **Input/Output**:
   ```cpp
   char str[50];
   std::cin >> str;                   // Reads until whitespace
   std::cout << str;
   ```

---

## C++ `std::string` Class

### Definition

The `std::string` class is part of the C++ Standard Library, providing more functionality and safety compared to C-style strings.

```cpp
#include <string>

std::string str = "Hello, World!";
```

### Creating and Initializing Strings

```cpp
std::string s1;                        // Empty string
std::string s2("Hello");               // Initialized with string literal
std::string s3(s2);                    // Copy constructor
std::string s4 = "World";              // Initialization with assignment
std::string s5(10, 'a');               // "aaaaaaaaaa"
```

### Accessing Characters

```cpp
char ch = s2[1];                      // 'e'
char ch2 = s2.at(1);                  // 'e', bounds-checked
```

### Modifying Strings

```cpp
s2 += " World";                        // Concatenate
s2.push_back('!');                     // Append character
s2.insert(5, ", Beautiful");           // Insert substring
s2.erase(5, 10);                       // Erase substring
s2.replace(0, 5, "Hi");                // Replace substring
```

### String Operations

```cpp
size_t len = s2.length();              // Length of string
s2.clear();                            // Clear string
bool empty = s2.empty();               // Check if empty
```

### String Comparisons

```cpp
bool isEqual = (s2 == s3);             // Equality
bool isLess = (s2 < s3);               // Lexicographical comparison
```

### String Functions

```cpp
size_t pos = s2.find("World");         // Find substring
std::string substr = s2.substr(6, 5);  // Extract substring
```

### String Iterators

```cpp
for (auto it = s2.begin(); it != s2.end(); ++it) {
    std::cout << *it;
}

for (char c : s2) {
    std::cout << c;
}
```

### Capacity and Size

```cpp
size_t size = s2.size();               // Number of characters
size_t capacity = s2.capacity();       // Capacity before reallocation
s2.reserve(100);                       // Reserve space
s2.shrink_to_fit();                    // Reduce capacity to fit size
```

---

## Conversion Between `std::string` and C-Style Strings

### From `std::string` to C-Style String

```cpp
std::string s = "Hello";
const char* cstr = s.c_str();         // Pointer to C-style string
```

### From C-Style String to `std::string`

```cpp
const char* cstr = "Hello";
std::string s = cstr;
```

---

## Examples

### Example 1: Basic String Operations

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s1 = "Hello";
    std::string s2 = "World";
    std::string s3 = s1 + ", " + s2 + "!";

    std::cout << s3 << std::endl;      // Output: Hello, World!
}
```

### Example 2: Iterating Over a String

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello";
    for (char c : s) {
        std::cout << c << ' ';
    }
    // Output: H e l l o
}
```

### Example 3: Substrings and Replacements

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello, World!";
    std::string sub = s.substr(7, 5);  // "World"
    s.replace(7, 5, "Universe");       // "Hello, Universe!"
    std::cout << s << std::endl;
}
```

---

## References

1. [C++ Reference - `<string>`](https://en.cppreference.com/w/cpp/string/basic_string)
2. [C++ Standard Library - Strings](https://cplusplus.com/reference/string/)
3. [C++ Tutorial - Strings](https://www.learncpp.com/cpp-tutorial/912-stdstring-basic-string-operations/)

---

## @author: nmanish_0128
