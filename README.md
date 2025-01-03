﻿
---

# **C Compiler Vicharak**  
### **Project Documentation**

---

## **Overview**

### **Project Name:**  
C Compiler Vicharak  

### **Description:**  
C Compiler Vicharak is a C compiler designed to translate C code into assembly language. It implements all core components of a compiler, including lexical analysis, syntax parsing, abstract syntax tree (AST) representation, and code generation.  

---

## **Table of Contents**  

1. [Introduction](#introduction)  
2. [Project Structure](#project-structure)  
3. [Installation](#installation)  
4. [Usage](#usage)  
5. [Components](#components)  
    - [Lexer](#lexer)  
    - [Parser](#parser)  
    - [Syntax Tree](#syntax-tree)  
    - [Code Generation](#code-generation)  
6. [Testing](#testing)  
7. [Contributing](#contributing)  
8. [License](#license)  

---

## **Introduction**  

C Compiler Vicharak provides a streamlined method to compile C programs by converting high-level C code into low-level assembly language. The project is aimed at showcasing how a basic compiler is implemented while adhering to common compiler design principles.  

---

## **Project Structure**  

```
C-compiler-vicharak/
│
├── src/
│   ├── lexer.cpp         # Handles lexical analysis
│   ├── parser.cpp        # Processes tokens into a syntax tree
│   ├── syntaxTree.cpp    # Represents the abstract syntax tree
│   ├── gen.cpp           # Handles code generation
│   ├── index.cpp         # Entry point for the compiler
│
├── include/              # Header files for components
├── tests/                # Test files for validation
├── Makefile              # Automates the build process
└── README.md             # Project documentation
```  

---

## **Installation**  

### **Dependencies**  
- GCC or any C++ compiler  
- Make (for build automation)  

### **Steps:**  
1. Clone the repository:  
   ```bash
   git clone https://github.com/your-username/C-compiler-vicharak.git
   cd C-compiler-vicharak
   ```  
2. Build the project:  
   ```bash
   make
   ```  

---

## **Usage**  

1. Compile and run the project:  
   ```bash
   ./compiler input.c -o output.asm
   ```  
2. Input: `input.c` (C source code)  
3. Output: `output.asm` (Assembly code)  

---

## **Components**  

### **Lexer**  

**File:** `src/lexer.cpp`  
**Description:** Converts the input C code into a stream of tokens for the parser to process.  

**Key Classes and Functions:**  
- `class Lexer`: Handles the tokenization process.  
- `lexer_advance()`: Moves the lexer to the next character.  
- `lexer_getToken()`: Extracts the next token from the source code.  

---

### **Parser**  

**File:** `src/parser.cpp`  
**Description:** Parses the token stream into an Abstract Syntax Tree (AST).  

**Key Classes and Functions:**  
- `class Parser`: Orchestrates the parsing process.  
- `parser_parse()`: Parses tokens to generate an AST.  
- `parser_match()`: Matches tokens based on grammar rules.  

---

### **Syntax Tree**  

**File:** `src/syntaxTree.cpp`  
**Description:** Represents the hierarchical structure of the parsed code for analysis and transformation.  

**Key Classes and Functions:**  
- `class SyntaxTree`: Represents a node in the AST.  
- `addChild()`: Adds child nodes to the current syntax tree node.  

---

### **Code Generation**  

**File:** `src/gen.cpp`  
**Description:** Translates the AST into assembly instructions.  

**Key Functions:**  
- `plus_compile()`: Orchestrates the compilation from AST to Assembly.  
- `emitInstruction()`: Outputs Assembly code for operations.  

---

## **Testing**  

The `src/index.cpp` file serves as the entry point and handles:  

1. **Argument Checking:** Verifies command-line input arguments for the source file.  
2. **File Reading:** Reads the source code into memory.  
3. **Compilation:** Invokes `plus_compile()` to process the code.  

---


