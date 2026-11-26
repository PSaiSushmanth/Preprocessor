# MyPreprocessor

A custom C-based preprocessor that mimics the basic functionality of the C preprocessor. The program reads a C source file, processes it, and generates an extended source file (`.i`) by removing comments, expanding header files, and performing macro substitution.

## 📌 Project Overview

This mini project implements a simplified version of the C Preprocessor using the C programming language. It accepts a C source file as input and generates an extended source code file after preprocessing.

**Example:**

```bash
./MyPreprocessor inputfile.c
```

**Output:**

```text
inputfile.i
```

## ✨ Features

- Remove single-line (`//`) and multi-line (`/* */`) comments.
- Process `#include` directives by inserting the contents of the included file.
- Perform `#define` macro substitution throughout the source file.
- Generate an extended source code (`.i`) file.
- Modular programming implementation.
- Build automation using Makefile.

## 🛠️ Technologies Used

- C Programming
- GCC Compiler
- Makefile
- File Handling
- String Manipulation

## 📂 Project Structure

```
MyPreprocessor/
│── src/
│── include/
│── inputfile.c
│── outputfile.i
│── Makefile
│── README.md
```

## 🚀 How to Build

```bash
make
```

## ▶️ How to Run

```bash
./MyPreprocessor inputfile.c
```

## 📖 Working

1. Reads the input C source file.
2. Removes all comments.
3. Expands the contents of header files specified using `#include`.
4. Replaces all macros defined using `#define`.
5. Writes the processed source code into an `.i` file.

## 📸 Sample

Input:

```c
#include "header.h"
#define PI 3.14

// Comment
int r = 5;
float area = PI * r * r;
```

Output:

```c
/* Contents of header.h */

int r = 5;
float area = 3.14 * r * r;
```

## 🎯 Learning Outcomes

- Understanding how the C Preprocessor works.
- File handling in C.
- String processing techniques.
- Modular programming concepts.
- Makefile usage for project compilation.

## 👨‍💻 Author

**Sai sushmanth**

---

⭐ If you found this project useful, don't forget to star the repository.
