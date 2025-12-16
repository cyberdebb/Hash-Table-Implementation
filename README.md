# Hash Table Implementation

This repository contains a **generic hash table (hash map) implementation in C++**, designed with a strong emphasis on **data structures, collision handling, and correctness**. The project is fully validated using **Google Test** and built with **CMake**, following a test-driven development approach.

---

## Overview

The project implements a **templated hash table** with fixed capacity, supporting insertion, removal, lookup, and position tracking.  
Collisions are handled using **separate chaining**, where each table index stores a linked list of elements.

The correctness of the implementation is ensured through an extensive suite of unit tests that validate behavior **with and without collisions**, including edge cases and exception handling.

---

## Features

- Generic hash table using C++ templates  
- Fixed-capacity table defined at compile time  
- Collision handling via separate chaining  
- Accurate position tracking inside the table and collision lists  
- Robust exception handling for invalid operations  
- Comprehensive unit tests using Google Test  

---

## Tested Operations

- Table initialization  
- Insertions without collisions  
- Insertions with collisions  
- Removal without collisions  
- Removal with collisions  
- Lookup and containment checks  
- Position reporting (table index and list position)  
- Exception handling for non-existent elements  

---

## Technologies Used

- **Language:** C++  
- **Build System:** CMake  
- **Testing Framework:** Google Test  
- **Paradigm:** Object-Oriented Programming  
- **Concepts:**  
  - Templates  
  - Hashing  
  - Collision resolution (separate chaining)  
  - Exception handling  
  - Unit testing  

---

## Project Structure

- `TabelaEspalhamentoAbstrata.h` – Abstract hash table interface  
- `MinhaTabelaEspalhamento.h` – Concrete hash table implementation  
- `Posicao.h` – Structure representing table and list positions  
- `excecoes.h` – Custom exception definitions  
- `main.cpp` – Google Test test suite and test runner  
- `CMakeLists.txt` – Build configuration  

---

## Build and Test Instructions (WSL Required)

This project is intended to be built and executed using **WSL (Windows Subsystem for Linux)**.

### Requirements

- Windows with WSL installed  
- Linux distribution (Ubuntu recommended)  
- C++ compiler (g++)  
- CMake  
- Google Test  

### Installing Dependencies (Ubuntu / WSL)

```bash
sudo apt update
sudo apt install build-essential cmake libgtest-dev
```

Google Test needs to be compiled after installation:

```bash
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib
```

---

### Building the Project

From the project root directory:

```bash
mkdir build
cd build
cmake ..
make
```
---

## Running the Tests

```bash
./HashTableTests
```
(The executable name may vary depending on your ```CMakeLists.txt``` configuration.)

---

## Educational Purpose

This project was developed to practice and demonstrate:
- Hash table implementation fundamentals
- Collision resolution strategies
- Template-based generic programming
- Precise data structure validation via unit tests
- CMake-based C++ project organization

