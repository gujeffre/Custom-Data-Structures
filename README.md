# C++ Custom, Leak-Proof Containers Sandbox

A hands-on implementation of **RAII**, ownership semantics, and the **Rule of Five** in C++17, verified with **AddressSanitizer (ASan)**.

## Features
*   **`MyUniquePtr<T>`**: Move-only smart pointer that prevents resource duplication (`= delete` copy contracts).
*   **`MyVector<T>`**: Dynamic array featuring geometric expansion (2x growth) and explicit deep copy/move handling.
*   **ASan Integration**: Hardcoded compiler diagnostics (`-fsanitize=address`) for automatic runtime leak checks.

## Quick Start

```bash
mkdir build && cd build
cmake ..
cmake --build .
./custom_structures
```

## File Layout
*   `MyUniquePtr.h` — Custom smart pointer lifecycle wrapper.
*   `MyVector.h` — Dynamic array tracking engine.
*   `main.cpp` — Runtime validation pipeline using a verbose diagnostic `Robot` entity.
*   `CMakeLists.txt` — Automated cross-compiler flag injector (GCC/Clang/MSVC).
