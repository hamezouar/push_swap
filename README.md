*This project has been created as part of the 42 curriculum by hamezoua.*

# Push Swap

## Description

The **Push Swap** project is a sorting algorithm challenge that focuses on algorithmic thinking and optimization.  
The goal is to sort a list of integers in ascending order using **two stacks (A and B)** and a **restricted set of operations**.  
The main objective is not only to sort the numbers correctly, but to do so using the **minimum number of operations possible**.

This project helps develop a deeper understanding of data structures, algorithm efficiency, and problem decomposition.

### Allowed Operations

- `sa` : Swap the first two elements of stack A  
- `sb` : Swap the first two elements of stack B  
- `ss` : Swap the first two elements of both stacks  
- `pa` : Push the top element of stack B onto stack A  
- `pb` : Push the top element of stack A onto stack B  
- `ra` : Rotate stack A upwards  
- `rb` : Rotate stack B upwards  
- `rr` : Rotate both stacks upwards  
- `rra` : Reverse rotate stack A  
- `rrb` : Reverse rotate stack B  
- `rrr` : Reverse rotate both stacks  

---

## Algorithm

### Main Strategy

This implementation uses a variation of the **Chunk / Butterfly algorithm**.

The idea is to:
- Divide the input numbers into **chunks**
- Push elements from stack A to stack B in an optimized order
- Reinsert elements back into stack A while maintaining sorted order

This approach significantly reduces the total number of operations, especially for large inputs (e.g. 100 or 500 numbers).

### Bonus — Checker

The bonus part includes a **checker program** that:
- Reads operations from standard input
- Applies them to the stacks
- Verifies whether stack A is sorted and stack B is empty

---

## Instructions

### Requirements

- GCC compiler
- Make
- Unix-based system (Linux / macOS)
- Compliance with 42 Norm

### Compilation

```bash
make
./push_swap 5 2 8 3 1 4
The program outputs a list of operations that will sort the given numbers.
Checker (Bonus)
./push_swap 5 2 8 3 1 4 | ./checker 5 2 8 3 1 4
OK → the list is correctly sorted
KO → the list is not sorted
Error → the list is not numbers or numbers is duplicate
```
## Resources

- 42 Push Swap subject PDF  
- Stack data structure documentation  
- Sorting algorithms fundamentals  
- Chunk / Butterfly sorting strategy articles  

PDF subject reference:  
https://cdn.intra.42.fr/pdf/pdf/189068/en.subject.pdf

## AI Usage

AI tools were used **only to explore and compare different sorting strategies** in order to choose the most efficient algorithm for this project.

The AI assistance was limited to:
- Analyzing which algorithms are suitable for the Push Swap constraints
- Comparing general approaches (e.g. chunk-based strategies)
- Understanding high-level algorithm concepts

All implementation details, logic, optimizations, and code were developed and written manually without direct code generation.


