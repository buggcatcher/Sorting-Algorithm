# Sorting-Algorithm
In this project, I'll be sorting data on a stack using a limited set of instructions. My goal is to use the fewest number of actions possible. To succeed, I'll need to manipulate various types of algorithms and carefully choose the most appropriate solution from many options to achieve optimized data sorting.

![viualizer](https://github.com/buggcatcher/Sorting-Algorithm/blob/main/visualizer.gif)


    #!/bin/bash
    valgrind --quiet --leak-check=full --show-leak-kinds=all ./push_swap "$@"
    echo "Last status: $?"
    echo "Moves: $(./push_swap "$@" | wc -l)"
    echo "Checker: $(./push_swap "$@" | ./checker_linux "$@")"


## 🎯 Project Goal
The **Push Swap** project consists of creating a program that sorts a stack of integers using a limited set of operations and two stacks (`a` and `b`), while minimizing the number of operations performed.

---

## 📋 Core Requirements

### Initial State
- **Stack a** contains a random number of unique integers (positive and/or negative)  
- **Stack b** is empty  

### Allowed Operations
- `sa` : Swap first two elements of stack **a**  
- `sb` : Swap first two elements of stack **b**  
- `ss` : `sa` and `sb` simultaneously  
- `pa` : Push first element from **b** to **a**  
- `pb` : Push first element from **a** to **b**  
- `ra` : Rotate stack **a** (first element becomes last)  
- `rb` : Rotate stack **b** (first element becomes last)  
- `rr` : `ra` and `rb` simultaneously  
- `rra`: Reverse rotate stack **a** (last element becomes first)  
- `rrb`: Reverse rotate stack **b** (last element becomes first)  
- `rrr`: `rra` and `rrb` simultaneously  

### Program Specifications
- Program name: **`push_swap`**  
- Must take a list of integers as arguments (**first argument = top of stack**)  
- Must display the **shortest sequence** of instructions to sort stack **a**  
- Instructions must be separated by `\n`  
- Must handle errors (non-integers, duplicates, overflow) by displaying **`Error`**  
- No global variables allowed  
- Must compile with a **Makefile** containing standard rules  

---

## 🎯 Performance Goals

To achieve **full validation**:
- Sort **100 random numbers** in less than **700 operations**  
- Sort **500 random numbers** in less than **5500 operations**  

Minimum validation requires meeting **one** of these benchmarks:
- 100 numbers in `< 1100 ops` **AND** 500 numbers in `< 8500 ops`  
- 100 numbers in `< 700 ops` **AND** 500 numbers in `< 11500 ops`  
- 100 numbers in `< 1300 ops` **AND** 500 numbers in `< 5500 ops`  

---

## 🔧 Testing

The program will be tested using a provided checker:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
