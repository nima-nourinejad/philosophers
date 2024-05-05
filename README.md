# Philosophers - Multithreading and Mutexes

## Overview
This project explores the fundamentals of multithreading and mutex management through a simulation involving philosophers dining at a round table. Each philosopher is represented as a thread, and mutexes are used to ensure proper synchronization and resource sharing.

## Features
- **Threaded Philosophers**: Each philosopher is modeled as a separate thread, allowing concurrent execution of their actions.
- **Mutex Management**: Mutexes are employed to control access to shared resources such as forks, preventing race conditions and ensuring consistency.
- **Simulation**: The simulation tracks the state transitions of each philosopher, including eating, thinking, sleeping, and potential starvation.
- **Configurability**: Parameters such as the number of philosophers, time intervals for dining, sleeping, and thinking, are configurable for experimentation.

## Usage
1. Clone the repository.
2. Compile the project using the provided Makefile.
3. Execute the program, providing appropriate command-line arguments.
4. Monitor the console output for the simulation progress and state transitions of philosophers.

## Key Skills Demonstrated

### Multithreading
Demonstrated proficiency in creating and managing multiple threads to achieve concurrent execution.

### Mutex Management
Implemented mutexes to ensure synchronized access to shared resources, preventing race conditions.

### Command-line Argument Parsing
Utilized command-line arguments to configure the simulation parameters, enhancing flexibility and usability.

### Error Handling
Implemented robust error handling mechanisms to gracefully handle unexpected situations and prevent program crashes.

### Code Organization and Modularity
Structured the codebase in a modular and organized manner, enhancing readability, maintainability, and scalability.

This project showcases my proficiency in C programming, particularly in multithreading and synchronization using mutexes. By simulating the dining philosophers problem, I demonstrate an understanding of concurrent programming concepts and effective resource management. The code is well-structured, modular, and extensively commented for readability and maintainability.
