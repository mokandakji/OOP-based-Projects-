# Metro Simulation - Doubly Linked List Based Train System

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
