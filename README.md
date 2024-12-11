# 42 Push Swap  

**Push Swap** is a sorting algorithm project designed to sort a stack of numbers in ascending order using a limited set of operations. The program works with two stacks, `a` and `b`, and implements an optimized sorting strategy based on the **quicksort** algorithm for larger lists and a trivial sorting approach for lists with five or fewer elements.  


## Project Overview  

The goal of the **Push Swap** program is to sort the numbers in stack `a` into ascending order, using only the allowed operations while minimizing the total number of moves. The operations include swapping, pushing, rotating, and reverse rotating elements between two stacks.

### Key Features  

- **Optimized Sorting**:  
  - **Quicksort-based approach**: Efficient sorting for larger input sizes.  
  - **Trivial sorting system**: Handles cases with 5 or fewer elements using minimal operations.  

- **Efficient Algorithms**: Implements stack-specific optimizations to reduce the number of moves required for sorting.  

- **Error Handling**:  
  - Ensures no duplicate numbers are allowed.  
  - Validates input to guarantee proper stack initialization.  


## Allowed Operations  

The sorting process is performed using the following operations:  

### Swap Operations  
- **sa**: Swap the top two elements of stack `a`.  
- **sb**: Swap the top two elements of stack `b`.  
- **ss**: Perform `sa` and `sb` simultaneously.  

### Push Operations  
- **pa**: Move the top element from stack `b` to stack `a`.  
- **pb**: Move the top element from stack `a` to stack `b`.  

### Rotate Operations  
- **ra**: Rotate stack `a` (first element becomes the last).  
- **rb**: Rotate stack `b` (first element becomes the last).  
- **rr**: Perform `ra` and `rb` simultaneously.  

### Reverse Rotate Operations  
- **rra**: Reverse rotate stack `a` (last element becomes the first).  
- **rrb**: Reverse rotate stack `b` (last element becomes the first).  
- **rrr**: Perform `rra` and `rrb` simultaneously.  

## Algorithm Details  

### Quicksort-Based Approach  
For stacks larger than 5 elements, the program uses a partitioning strategy inspired by the quicksort algorithm:  
1. Divide the elements in stack `a` into partitions based on a pivot.  
2. Push elements to stack `b` selectively, creating smaller, manageable segments.  
3. Recursively sort each partition until all elements are correctly ordered.  
4. Push elements back to stack `a` in sorted order.  

### Trivial Sorting System  
For stacks of 5 or fewer elements, the program directly evaluates the positions of elements and applies minimal operations to sort them. This avoids the overhead of more complex algorithms for small inputs.  


## Compilation Instructions

To compile the code, use the following command:

```bash
make
```

### **Running the Program**:  
   Execute the program with the following syntax:  
   ```bash  
   ./push_swap <list of numbers>  
   ```

### Cleaning Up
Use the following commands for cleanup:

- `make clean`: Remove object files.
- `make fclean`: Remove object files and the compiled library.
- `make re`: Rebuild the library from scratch.
 

## Output  

The program outputs a sequence of operations to sort the stack. Each operation is displayed as a line, e.g.:  
```
pb  
pb  
sa  
pa  
pa  
```

You can validate the output of your program using a checker for **MacOS** / **Linux**. To test a sequence of numbers, such as `43 670 13 88 19`, use the following command:  

```bash  
ARG="43 670 13 88 19"; ./push_swap $ARG | ./checker_OS $ARG  
```  

Replace `checker_OS` with the appropriate version of the checker for your operating system. This command will verify whether the operations produced by `push_swap` correctly sort the given list.


## Error Handling  

If invalid input or errors occur, the program exits cleanly and displays:  
```
Error  
```

### Common Errors:  
- Duplicate numbers.  
- Non-numeric input.  
- Exceeding stack size limits.  

