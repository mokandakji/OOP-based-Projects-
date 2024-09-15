# Metro Simulation - Doubly Linked List Based Train System

<img src="images/metro_diagram.png" alt="Metro Line Diagram" width="400"/>

## Overview

This project simulates a city's metro system using Object-Oriented Programming (OOP) principles in C++. The simulation is designed to demonstrate how metro trains move between stations on different lines. The system allows for flexible input of metro stations, simulates the travel of metro trains back and forth along a line, and outputs the train positions at any given time.

The metro stations are stored as nodes in a doubly linked list, allowing the train to move in both directions between stations. Each stop at a station and the travel time between stations is simulated, with each journey taking between 1 to 5 minutes.

## Features

- **Metro Line Generation**: Each metro line is generated as a doubly linked list of stations, with the option to flexibly input the number of stations.
- **Station Structure**: The system includes a C++ structure called `Station` that holds the station name, travel time to the next station, and pointers to the previous and next stations.
- **Train Simulation**: The train travels between stations, stopping for 1 minute at each station, and travels to the next station in a randomized time of 1 to 5 minutes.
- **Train Structure**: A `Train` structure holds the train’s name, the number of minutes left to travel to the next station, the direction of travel, and a pointer to the next station.
- **Simulation Control**: Users can simulate the passage of time in 1-minute increments and observe the movement of trains between stations.

## Simulation Rules

- Trains start at the first station of a metro line.
- The user can simulate the train movement, with each station stop taking 1 minute.
- Travel times between stations are randomly generated between 1 and 5 minutes.
- When a train reaches the end of a line, it reverses direction and travels back to the starting station.
- The current position and time remaining until the next station are displayed at each simulation step.

## Project Structure

- `Station`: C++ structure for metro stations, including station name, time to the next station, and pointers to previous/next stations.
- `Train`: C++ structure for trains, holding the train name, travel time, current station, and direction.
- `generate_metro_line()`: Function to generate a doubly linked list of stations for a metro line.
- `output_line()`: Function to output the stations on a metro line.
- `output_all_trains()`: Function to output the status of all trains on a line.
- `simulate_train_movement()`: Function to simulate 1 minute of train movement and update the train’s position.

## Usage

- The program will ask you to input the number of stations for two metro lines.
- After entering the station counts, you will be presented with a menu to:
  - **Display stations of a line**: Output the stations of a chosen metro line.
  - **Display train positions**: Show the current position of each train.
  - **Simulate 1 minute**: Advance the simulation by 1 minute, updating the positions of the trains.

## OOP Concepts Demonstrated

- **Encapsulation**: Data related to stations and trains is organized into C++ structures.
- **Doubly Linked List**: The stations on each line are stored as a doubly linked list, allowing movement in both directions.
- **Polymorphism and Function Overloading**: Multiple output functions are used to display the metro line and train positions.
- **Dynamic Memory Management**: Metro stations are dynamically allocated on the heap and managed through pointers.

## Example Program Run

```text
input number of stations of line 1: 4
input number of stations of line 2: 3
e end
l line output
t train output
1 simulate 1 minute
>> l
which line? 1
line 1 station 1: time to next: 4 min
line 1 station 2: time to next: 2 min
line 1 station 3: time to next: 5 min
line 1 station 4: end station
>> t
time simulation: 0 min
train 1: stop at line 1 station 1
train 2: stop at line 2 station 1
>> 1
time simulation: 1 min
train 1: 4 minute(s) to line 1 station 2
train 2: 2 minute(s) to line 2 station 2

