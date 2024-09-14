# Postal Code and City Linked List in C++

## Project Overview

This project simulates the management and organization of postal codes (PLZ) and their associated cities in Germany. Using C++, it implements a dynamic data structure that reads a list of postal codes and cities from a CSV file (`plz.csv`) and stores them in a linked list. The project focuses on using pointers, linked lists, file handling, and operator overloading in C++ to effectively manage and display postal code data.

## Features

- **Linked List Implementation**: Stores cities and their additional information for each postal code as a singly linked list.
- **Operator Overloading**: Overloads the `<<` operator to print the cities associated with a specific postal code.
- **File Input**: Reads from a CSV file containing postal code information.
- **Efficient Search**: Allows for quick search and display of cities associated with a given postal code or range of postal codes.
- **Compartment Sorting**: Data is organized using a compartment sorting approach for fast, constant-time lookups of postal codes.
  

## OOP Concepts Demonstrated

1. **Linked List**: The cities for each postal code are stored in a singly linked list.
2. **Operator Overloading**: The `<<` operator is overloaded to output the city data in a readable format.
3. **Dynamic Memory Management**: Dynamic allocation and deallocation of memory using pointers for the linked list nodes.
4. **File Handling**: Efficient reading of postal code data from an external file.
5. **Encapsulation**: The data and operations related to the cities and postal codes are encapsulated within the appropriate structures and functions.

## Usage

1. **File Input**: Ensure that the `plz.csv` file is present in the project directory. This file contains the postal codes and associated cities.
2. **Compile**: Use the provided Makefile to compile the project:
    ```bash
    make
    ```
3. **Run**: After compilation, run the program:
    ```bash
    ./postalcode
    ```
4. **Menu**: The program will provide a menu for searching and displaying cities associated with postal codes:
    - `q`: Quit the program
    - `c`: Enter the beginning digits of a postal code to search
    - `f`: Enter a range of postal codes to search and display cities

## Example Output

Enter a command: c
Enter postal code start: 4 
Displaying all cities for postal codes between 40000 and 49999: 47057:
Duisburg | 45472: Muelheim an der Ruhr |
