# Non-Comparison Sorting Algorithms in C++

This repository contains **C++ implementations of four non-comparison sorting algorithms**:

1. Counting Sort  
2. Radix Sort  
3. Pigeonhole Sort  
4. Bead Sort  

Each algorithm is implemented in its own class with functions to sort arrays and print the results. A `main.cpp` demonstrates applying all four sorts on the same dataset.

---

## Table of Contents

- [Overview](#overview)  
- [Algorithms](#algorithms)  
  - [Counting Sort](#counting-sort)  
  - [Radix Sort](#radix-sort)  
  - [Pigeonhole Sort](#pigeonhole-sort)  
  - [Bead Sort](#bead-sort)  
- [Time Complexity](#time-complexity)  
- [Limitations](#limitations)  
- [Usage](#usage)  

---

## Overview

Non-comparison sorting algorithms sort elements **without direct comparisons**. They use **key properties** of data, such as value ranges, digits, or physical analogies:

- **Counting Sort** → frequency counts  
- **Radix Sort** → digits of numbers  
- **Pigeonhole Sort** → value-based slots  
- **Bead Sort** → gravity-based bead analogy  

These algorithms are efficient for specific types of data, often outperforming comparison-based sorts for large datasets with restricted domains.

---

## Algorithms

### 1. Counting Sort

**Concept:**  
Counts occurrences of each element in a fixed range and places them in the correct position.

**Time Complexity:** O(n + k) where k = range of input  
**Space Complexity:** O(n + k)  

**Limitations:**  
- Only works for integers or data mappable to integers  
- Not efficient for large ranges (k >> n)  

---

### 2. Radix Sort

**Concept:**  
Sorts numbers **digit by digit**, starting from the least significant digit (LSD), using Counting Sort as a subroutine.

**Time Complexity:** O(d * (n + b))  
- n = number of elements  
- d = number of digits  
- b = base (usually 10)  

**Space Complexity:** O(n + b)  

**Limitations:**  
- Works only for integers (or convertible data)  
- Requires a stable subroutine sort  
- Not memory-efficient for numbers with many digits  

---

### 3. Pigeonhole Sort

**Concept:**  
Places elements into "pigeonholes" for each value in the range and directly sorts them.

**Time Complexity:** O(n + range)  
**Space Complexity:** O(range)  

**Limitations:**  
- Only suitable for integers  
- Efficient if range ≈ number of elements  
- Inefficient for sparse datasets (large range, small n)  

---

### 4. Bead Sort

**Concept:**  
Models numbers as beads on vertical rods. Beads "fall" under gravity to sort values.

**Time Complexity:** O(S) where S = sum of elements  
**Space Complexity:** O(n * maxElement)  

**Limitations:**  
- Works only for positive integers  
- Memory-intensive for large numbers  
- Conceptually interesting, rarely used in practice  

---

## Time Complexity Summary

| Algorithm        | Best      | Average   | Worst     | Space Complexity |
|-----------------|----------|----------|----------|----------------|
| Counting Sort    | O(n+k)   | O(n+k)   | O(n+k)   | O(n+k)         |
| Radix Sort       | O(d*(n+b)) | O(d*(n+b)) | O(d*(n+b)) | O(n+b) |
| Pigeonhole Sort  | O(n+range) | O(n+range) | O(n+range) | O(range) |
| Bead Sort        | O(S)     | O(S)     | O(S)     | O(n*maxElement) |

---
