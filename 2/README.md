# Two's Complement Bitwise Operations with Operator Overloading in C++

## Project Overview

This project focuses on implementing two's complement bitwise operations in C++ using operator overloading. We define a custom C++ structure `binary_number` to handle large numbers in bit form, and simulate various operations on two's complement numbers. The operations include bitwise negation, two's complement conversion, addition, subtraction, and equality checks. These operations are done using overloaded operators and custom-defined functions, providing a robust understanding of two's complement numbers and how to manipulate them programmatically.

## Key Features

- **Two's Complement Representation**: Represent large numbers as an array of boolean values (0s and 1s), interpreted as two's complement numbers.
- **Operator Overloading**: Overload standard operators (`+`, `-`, `==`, `!=`, `<<`, `>>`) to perform bitwise operations and arithmetic on binary numbers.
- **Bitwise Negation and Two's Complement**: Implement bitwise negation (`!`) and two's complement (`-`) operations.
- **Addition and Subtraction**: Perform addition and subtraction of binary numbers using overloaded operators.
- **Equality and Inequality Checks**: Check whether two binary numbers are equal or unequal using overloaded equality (`==`) and inequality (`!=`) operators.
- **Zero and Negative Checks**: Implement functions `is_zero()` and `is_negative()` to check if a number is zero or negative.

## OOP Concepts Demonstrated

- **Encapsulation**: The binary number is encapsulated within a custom structure, with access to its bits controlled by overloaded operators.
- **Operator Overloading**: Overload common C++ operators to work with the custom binary number structure, allowing intuitive operations on the two's complement numbers.
- **Abstraction**: The complex underlying operations (like addition, subtraction, and negation) are hidden from the user and accessed via simple operator symbols.
- **Dynamic Memory Management**: The binary number is stored in a dynamically allocated array to support varying sizes.

## Usage

1. **Define binary_number Structure**: A `binary_number` structure represents a two's complement number with `n` bits.
2. **Operator Overloading**: Overloaded operators `+`, `-`, `==`, `!=`, `<<`, `>>` are defined to perform various operations.
3. **Menu-Driven Program**: A menu-based program allows the user to input binary numbers, perform arithmetic, and check results.

## Sample Menu:

Menu:
1- Input binary numbers
2- Output binary numbers
3- Bitwise negation
4- Two's complement
5- Addition
6- Subtraction
7- Equality check
8- Inequality check
9- Check if zero
10- Check if negative
11- Quit

## OOP Concepts Demonstrated

- **Operator Overloading**: Overloaded various operators (`<<`, `>>`, `!`, `-`, `+`, `==`, `!=`) to perform custom operations on binary number structures.
- **Encapsulation**: The binary number and its operations are encapsulated within a C++ structure, ensuring that the representation is hidden from the outside world.
- **Modular Design**: Functions such as `is_zero()`, `is_negative()`, and `full_adder()` demonstrate a modular approach, breaking the problem into manageable sub-tasks.
- **Dynamic Memory Allocation**: Use of structures and arrays to handle variable-length binary numbers.
- **Two's Complement Arithmetic**: Implemented two's complement arithmetic for addition, subtraction, and negation of binary numbers.

