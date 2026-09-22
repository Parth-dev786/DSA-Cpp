# Arrays in C++

> **Topic:** Introduction to Arrays
> **Level:** Beginner
> **Purpose:** Understand what arrays are, why they exist, how they are stored in memory, and how array access works internally.

---

## 1. What is an Array?

An **array** is a collection of elements of the **same data type**, stored in **contiguous memory locations**.

```cpp
int arr[5];
```

This creates space for **5 integers**.

Conceptually:

```text
arr
 ↓
┌─────┬─────┬─────┬─────┬─────┐
│ 10  │ 20  │ 30  │ 40  │ 50  │
└─────┴─────┴─────┴─────┴─────┘
  0     1     2     3     4
       Index
```

Each element:

* has the same data type
* occupies the same amount of memory
* has an index
* is stored next to the previous element in memory

---

# 2. Why Do We Need Arrays?

Suppose we want to store marks of 5 students.

Without an array:

```cpp
int marks1 = 80;
int marks2 = 75;
int marks3 = 91;
int marks4 = 68;
int marks5 = 87;
```

This becomes difficult to manage when the number of values increases.

With an array:

```cpp
int marks[5] = {80, 75, 91, 68, 87};
```

Now all values are grouped under one name:

```text
marks
 ↓
[80][75][91][68][87]
```

So the main problem arrays solve is:

> **How can we store many values of the same type together and access them efficiently?**

---

# 3. Basic Properties of an Array

An array generally has these important properties:

| Property            | Meaning                                             |
| ------------------- | --------------------------------------------------- |
| Same data type      | All elements have the same type                     |
| Fixed size          | Raw array size is fixed after creation              |
| Index-based         | Elements are accessed using indexes                 |
| Contiguous memory   | Elements are stored next to each other              |
| Zero-based indexing | First element has index `0`                         |
| Fast access         | An element can be accessed directly using its index |

---

# 4. Declaring an Array

Syntax:

```cpp
dataType arrayName[size];
```

Example:

```cpp
int numbers[5];
```

Meaning:

* `int` → type of every element
* `numbers` → array name
* `5` → number of elements

The indexes are:

```text
0   1   2   3   4
↓   ↓   ↓   ↓   ↓
[ ][ ][ ][ ][ ]
```

The **size is 5**, but the **last index is 4**.

---

# 5. Initialization

## Method 1: Initialize all elements

```cpp
int arr[5] = {10, 20, 30, 40, 50};
```

## Method 2: Let C++ calculate the size

```cpp
int arr[] = {10, 20, 30, 40, 50};
```

C++ determines that the array contains 5 elements.

## Method 3: Partial initialization

```cpp
int arr[5] = {10, 20};
```

The remaining elements are initialized to `0`:

```text
[10][20][0][0][0]
```

---

# 6. Accessing Array Elements

Array elements are accessed using their **index**.

```cpp
int arr[5] = {10, 20, 30, 40, 50};

cout << arr[0];
```

Output:

```text
10
```

Example:

```cpp
cout << arr[3];
```

Output:

```text
40
```

Remember:

```text
arr[0] → first element
arr[1] → second element
arr[2] → third element
arr[3] → fourth element
arr[4] → fifth element
```

---

# 7. Why Does Indexing Start From 0?

This is an important concept.

Suppose the starting memory address of an array is:

```text
1000
```

and each integer takes:

```text
4 bytes
```

Then:

```text
arr[0] → 1000
arr[1] → 1004
arr[2] → 1008
arr[3] → 1012
```

The first element is at the **base address itself**.

Therefore:

```text
Address of arr[i]
= Base Address + i × Size of Element
```

For the first element:

```text
Address of arr[0]
= Base + 0 × size
= Base
```

This is one important reason zero-based indexing fits naturally with array address calculation.

---

# 8. Contiguous Memory

**Contiguous** means memory locations are next to each other.

Suppose:

```cpp
int arr[4] = {10, 20, 30, 40};
```

and one `int` occupies 4 bytes.

If the first element starts at address `1000`:

```text
Element       Address

arr[0]        1000
arr[1]        1004
arr[2]        1008
arr[3]        1012
```

There is no gap between the elements.

```text
1000       1004       1008       1012
 ↓          ↓          ↓          ↓
┌──────┐ ┌──────┐ ┌──────┐ ┌──────┐
│  10  │ │  20  │ │  30  │ │  40  │
└──────┘ └──────┘ └──────┘ └──────┘
```

This contiguous storage is one of the most important characteristics of arrays.

---

# 9. How Does `arr[i]` Work Internally?

When you write:

```cpp
arr[3]
```

the computer doesn't need to search through the array.

It can calculate the address directly:

```text
Address = Base Address + Index × Size of Element
```

Suppose:

```text
Base Address = 1000
Index = 3
int size = 4 bytes
```

Then:

```text
Address
= 1000 + 3 × 4
= 1012
```

So:

```cpp
arr[3]
```

refers directly to the value stored at address `1012`.

### Important idea

> Array indexing is based on **address calculation**, not searching.

---

# 10. Why Is Array Access O(1)?

Accessing:

```cpp
arr[0]
```

or:

```cpp
arr[1000]
```

does not require checking all previous elements.

The address can be calculated directly:

```text
Base + index × element_size
```

Therefore, accessing an element by index takes **constant time**:

```text
O(1)
```

This is called **random/direct access**.

---

# 11. Memory Layout

Consider:

```cpp
int arr[5] = {10, 20, 30, 40, 50};
```

If an `int` occupies 4 bytes and the base address is `2000`:

| Element | Index | Address |
| ------- | ----: | ------: |
| 10      |     0 |    2000 |
| 20      |     1 |    2004 |
| 30      |     2 |    2008 |
| 40      |     3 |    2012 |
| 50      |     4 |    2016 |

Formula:

```text
Address(arr[i]) = Base Address + i × sizeof(element)
```

For example:

```text
Address(arr[4])
= 2000 + 4 × 4
= 2016
```

---

# 12. Data Type and Memory Size

Different data types generally require different amounts of memory.

For example:

```cpp
int arr[5];
```

If:

```text
sizeof(int) = 4 bytes
```

then:

```text
Total memory = 5 × 4
             = 20 bytes
```

The exact size of fundamental types can depend on the C++ implementation, so `sizeof` is the reliable way to check it.

```cpp
cout << sizeof(int);
```

---

# 13. `sizeof()` with Arrays

Consider:

```cpp
int arr[5] = {10, 20, 30, 40, 50};
```

Then:

```cpp
sizeof(arr)
```

gives the **total number of bytes occupied by the array**.

If an `int` is 4 bytes:

```text
sizeof(arr) = 20 bytes
```

It does **not** mean the array contains 20 elements.

### Number of elements

For a raw array in the same scope:

```cpp
int n = sizeof(arr) / sizeof(arr[0]);
```

For example:

```text
sizeof(arr)      = 20
sizeof(arr[0])   = 4

20 / 4 = 5 elements
```

---

# 14. Size vs Index

This is a very common beginner mistake.

For:

```cpp
int arr[5];
```

### Size

```text
5
```

### Valid indexes

```text
0, 1, 2, 3, 4
```

### Last index

```text
4
```

Therefore:

```text
Last index = Size - 1
```

---

# 15. Taking Input in an Array

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    return 0;
}
```

If input is:

```text
10 20 30 40 50
```

the array becomes:

```text
[10][20][30][40][50]
```

The loop simply accesses each index one by one.

---

# 16. Printing an Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

Output:

```text
10 20 30 40 50
```

Here, the loop is simply being used to visit each array element.

> **Traversal is the process of visiting array elements one by one.**

---

# 17. Out-of-Bounds Access

For:

```cpp
int arr[5];
```

valid indexes are:

```text
0 to 4
```

This is invalid:

```cpp
cout << arr[5];
```

Why?

Because index `5` is outside the array.

```text
Valid:
[0][1][2][3][4]

Invalid:
             [5] ❌
```

Accessing outside the bounds of a raw array leads to **undefined behavior**.

It may:

* produce an unexpected value
* appear to work accidentally
* corrupt data
* cause a crash

Never assume an out-of-bounds access is safe.

---

# 18. Important: Array Values Are Not Automatically Zero

Consider:

```cpp
int arr[5];
```

If this is a local array inside a function, its elements are **not automatically initialized to zero**.

They contain indeterminate values.

If you want zero initialization:

```cpp
int arr[5] = {};
```

or:

```cpp
int arr[5] = {0};
```

Then:

```text
[0][0][0][0][0]
```

---

# 19. Raw Array Has Fixed Size

Consider:

```cpp
int arr[5];
```

This array has space for exactly 5 elements.

You cannot simply increase it later:

```cpp
arr[5] = 100;   // ❌ Out of bounds
```

The fifth index is `4`.

Raw arrays are therefore useful when the required size is known and fixed.

> Dynamic-size collections are handled by other data structures such as `std::vector`, which you will learn separately.

---

# 20. Arrays and Functions

Suppose:

```cpp
void print(int arr[]) {
    cout << arr[0];
}
```

When a raw array is passed to a function, it is commonly treated as a **pointer to its first element**.

Conceptually:

```text
Array
 ↓
[10][20][30][40]
 ↑
Pointer to first element
```

Therefore, inside the function, the array's complete size is not automatically available through the parameter.

This is why functions often receive the size separately:

```cpp
void print(int arr[], int size)
```

Example:

```cpp
void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
```

For now, remember the main idea:

> **When a raw array is passed to a function, its size is not automatically carried with it.**

---

# 21. Where Are Arrays Useful?

Arrays are useful whenever we need a collection of related values of the same type.

Examples:

### Student marks

```cpp
int marks[5];
```

### Temperatures

```cpp
float temperature[7];
```

### Game scores

```cpp
int scores[10];
```

### Pixel data

Images can be represented using arrays of pixel values.

### Tables and matrices

Arrays are also used as the foundation for multi-dimensional data structures.

### DSA

Arrays are one of the fundamental building blocks for many data structures and algorithms.

---

# 22. Advantages of Arrays

### 1. Fast index-based access

```cpp
arr[i]
```

can be accessed in:

```text
O(1)
```

### 2. Simple structure

Arrays are easy to understand and use.

### 3. Memory locality

Elements are stored next to each other, which can be beneficial for efficient memory access.

### 4. Low overhead

Raw arrays are a simple and direct representation of a fixed-size sequence of elements.

---

# 23. Limitations of Raw Arrays

### 1. Fixed size

The size cannot be directly changed after creation.

### 2. Same data type

A normal array stores elements of one type.

```cpp
int arr[5];
```

stores integers, not a mixture of unrelated types.

### 3. No automatic bounds checking

C++ raw arrays do not automatically stop you from writing:

```cpp
arr[100];
```

### 4. Manual size management

When passing a raw array to a function, you often need to provide its size separately.

---

# 24. Common Beginner Mistakes

### Mistake 1: Confusing size and last index

```cpp
int arr[5];
```

Wrong:

```text
last index = 5 ❌
```

Correct:

```text
last index = 4 ✅
```

---

### Mistake 2: Starting from index 1

Wrong:

```cpp
arr[1]   // first element ❌
```

Correct:

```cpp
arr[0]   // first element ✅
```

---

### Mistake 3: Accessing outside the array

```cpp
int arr[5];

arr[5] = 10;  // ❌
```

Valid indexes are `0–4`.

---

### Mistake 4: Thinking `sizeof(arr)` gives the number of elements

```cpp
sizeof(arr)
```

returns the total size in **bytes**, not the number of elements.

---

### Mistake 5: Assuming local arrays contain zero

```cpp
int arr[5];
```

Do not assume:

```text
[0][0][0][0][0]
```

Use:

```cpp
int arr[5] = {};
```

if zero initialization is required.

---

# 25. The Most Important Mental Model

Whenever you see:

```cpp
int arr[5];
```

think:

```text
One name
   ↓
┌──────┬──────┬──────┬──────┬──────┐
│      │      │      │      │      │
└──────┴──────┴──────┴──────┴──────┘
   0      1      2      3      4
```

Each box:

* stores one `int`
* has a unique index
* occupies memory
* is located next to the other elements

And:

```cpp
arr[i]
```

means:

> **Go to the array's starting address and move `i` elements forward.**

---

# 26. Self-Teaching Questions

Try answering these **without looking at the notes**.

### Basic Understanding

1. What is an array?
2. Why do we need arrays?
3. Why must elements of a normal array have the same data type?
4. What does the size of an array represent?
5. What is the first index of an array?
6. What is the last index of `int arr[10]`?

### Memory Understanding

7. What does contiguous memory mean?
8. Why can the address of `arr[i]` be calculated directly?
9. What is the formula for the address of an array element?
10. If the base address is `1000`, an element occupies 4 bytes, and `i = 3`, what is the address of `arr[3]`?
11. Why is array access by index `O(1)`?
12. Why is zero-based indexing natural for address calculation?

### C++ Understanding

13. What does `sizeof(arr)` return for a raw array?
14. How can you calculate the number of elements using `sizeof`?
15. What happens if you access an invalid index?
16. Why does a local uninitialized array not necessarily contain zeros?
17. Why is a raw array's size fixed?
18. What happens conceptually when a raw array is passed to a function?

---

# 27. Quick Revision Sheet

Remember these points:

```text
Array
│
├── Collection of same-type elements
│
├── Stored in contiguous memory
│
├── Index starts from 0
│
├── Last index = size - 1
│
├── arr[i] → access element at index i
│
├── Address(arr[i])
│      = Base + i × sizeof(element)
│
├── Index access → O(1)
│
├── sizeof(arr) → total bytes
│
├── Raw array → fixed size
│
└── Out-of-bounds access → undefined behavior
```

### One formula to remember

```text
Address(arr[i]) = Base Address + i × sizeof(element)
```

### One rule to remember

```text
If size = N
valid indexes = 0 to N - 1
```

### One concept to remember

> **An array is fast for indexed access because its elements are stored contiguously, allowing the address of any element to be calculated directly.**

---

# 28. Tiny Practice

Write a C++ program that:

1. Creates an integer array of size 5.
2. Takes 5 numbers as input.
3. Prints all elements.
4. Prints the first element.
5. Prints the last element.
6. Prints the total memory occupied using `sizeof`.

Example:

```text
Enter 5 numbers:
10 20 30 40 50

Array:
10 20 30 40 50

First element: 10
Last element: 50
Total memory: 20 bytes
```


## ✅ Final Self-Test

Before moving forward, you should be able to explain this without notes:

> **What happens in memory when I create `int arr[5]`, and how does C++ find `arr[3]`?**

If you can explain:

```text
Array
→ same type
→ contiguous memory
→ base address
→ index
→ element size
→ address calculation
→ direct access
→ O(1)
```

then your foundation of arrays is clear.

