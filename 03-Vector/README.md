# Vectors in C++

## Introduction

A **vector** in C++ is a dynamic array provided by the Standard Template Library (STL). Unlike normal arrays, vectors can automatically grow or shrink in size when elements are inserted or removed.

Vectors are widely used in Data Structures and Algorithms because they provide flexible memory management, efficient random access, and useful built-in functions.

---

## Why Vectors?

| Arrays | Vectors |
|---|---|
| Fixed size | Dynamic size |
| Difficult to insert elements | Easy insertion |
| Difficult to remove elements | Easy removal |
| Manual size management | Automatic size management |
| Limited built-in functionality | Rich STL functions |

---

## Header File

```cpp
#include <vector>
```

To use vectors:

```cpp
#include <iostream>
#include <vector>
using namespace std;
```

---

## Declaration

```cpp
vector<int> v;
```

### Different Types of Vectors

```cpp
vector<int> v1;
vector<char> v2;
vector<string> v3;
vector<double> v4;
```

---

## Initialization

### 1. Empty Vector

```cpp
vector<int> v;
```

### 2. Vector with Initial Values

```cpp
vector<int> v = {10, 20, 30, 40, 50};
```

### 3. Vector with a Specific Size

```cpp
vector<int> v(5);
```

Creates five elements initialized to zero.

### 4. Vector with Size and Value

```cpp
vector<int> v(5, 10);
```

Creates five elements, each initialized to 10.

Output:

```text
10 10 10 10 10
```

---

## Accessing Elements

Elements can be accessed using indexes.

```cpp
vector<int> v = {10, 20, 30, 40, 50};

cout << v[0];  // 10
cout << v[2];  // 30
cout << v[4];  // 50
```

Indexing starts from 0.

### Using at()

```cpp
cout << v.at(2);
```

`at()` performs bounds checking.

---

## Important Vector Functions

| Function | Description | Complexity |
|---|---|---|
| `push_back(x)` | Adds an element at the end | O(1) amortized |
| `pop_back()` | Removes the last element | O(1) |
| `size()` | Returns number of elements | O(1) |
| `capacity()` | Returns allocated storage capacity | O(1) |
| `empty()` | Checks whether vector is empty | O(1) |
| `front()` | Returns first element | O(1) |
| `back()` | Returns last element | O(1) |
| `clear()` | Removes all elements | O(n) |
| `insert()` | Inserts an element at a position | O(n) |
| `erase()` | Removes element from a position | O(n) |
| `resize()` | Changes the vector size | Depends |
| `reserve()` | Allocates capacity | Depends |

---

## push_back()

Adds an element at the end of the vector.

```cpp
vector<int> v = {10, 20, 30};

v.push_back(40);
v.push_back(50);
```

Result:

```text
10 20 30 40 50
```

---

## pop_back()

Removes the last element.

```cpp
v.pop_back();
```

Before:

```text
10 20 30 40 50
```

After:

```text
10 20 30 40
```

---

## size()

Returns the number of elements.

```cpp
cout << v.size();
```

---

## empty()

Checks whether the vector contains elements.

```cpp
if(v.empty()) {
    cout << "Vector is empty";
}
else {
    cout << "Vector is not empty";
}
```

---

## front() and back()

```cpp
vector<int> v = {10, 20, 30, 40};

cout << v.front();  // 10
cout << v.back();   // 40
```

---

## Traversal

### Using a Normal For Loop

```cpp
for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
```

### Using a Range-Based For Loop

```cpp
for(int element : v) {
    cout << element << " ";
}
```

### Using Iterators

```cpp
for(auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```

---

## insert()

Inserts an element at a particular position.

```cpp
vector<int> v = {10, 20, 40, 50};

v.insert(v.begin() + 2, 30);
```

Result:

```text
10 20 30 40 50
```

`v.begin() + 2` represents the position of index 2.

---

## erase()

Removes an element from a particular position.

```cpp
vector<int> v = {10, 20, 30, 40, 50};

v.erase(v.begin() + 2);
```

Result:

```text
10 20 40 50
```

### Removing a Range

```cpp
v.erase(v.begin() + 1, v.begin() + 3);
```

The starting iterator is included, but the ending iterator is excluded.

---

## clear()

Removes all elements from the vector.

```cpp
v.clear();
```

After clearing:

```cpp
v.size();  // 0
```

---

## size() vs capacity()

### Size

The number of elements currently present.

### Capacity

The number of elements that can be stored in currently allocated memory before reallocation is required.

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

cout << v.size() << endl;
cout << v.capacity() << endl;
```

Capacity is implementation-dependent and may be greater than size.

---

## resize()

Changes the number of elements.

```cpp
vector<int> v = {10, 20, 30};

v.resize(5);
```

Result:

```text
10 20 30 0 0
```

Shrinking:

```cpp
v.resize(2);
```

Result:

```text
10 20
```

---

## reserve()

Allocates memory for elements without changing the vector size.

```cpp
vector<int> v;

v.reserve(100);
```

The vector may now have capacity for at least 100 elements.

```cpp
cout << v.size();      // 0
cout << v.capacity();  // At least 100
```

**Difference:**

- `resize()` changes the size.
- `reserve()` changes the capacity.

---

## Complete Program

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> v = {10, 20, 30, 40, 50};

    // Traversal
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    // Insertion
    v.push_back(60);

    // Deletion
    v.pop_back();

    // Insert at index 2
    v.insert(v.begin() + 2, 25);

    // Erase at index 1
    v.erase(v.begin() + 1);

    // Updated vector
    for(int element : v) {
        cout << element << " ";
    }

    cout << endl;

    cout << "Size: " << v.size() << endl;
    cout << "First Element: " << v.front() << endl;
    cout << "Last Element: " << v.back() << endl;

    return 0;
}
```

### Output

```text
10 20 30 40 50
10 30 25 40 50
Size: 5
First Element: 10
Last Element: 50
```

---

## 2D Vector

A vector can store other vectors, creating a two-dimensional structure.

```cpp
vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

### Accessing Elements

```cpp
cout << matrix[0][0];  // 1
cout << matrix[1][2];  // 6
cout << matrix[2][1];  // 8
```

### Traversal

```cpp
for(int i = 0; i < matrix.size(); i++) {

    for(int j = 0; j < matrix[i].size(); j++) {
        cout << matrix[i][j] << " ";
    }

    cout << endl;
}
```

### Applications

- Matrices
- Graph adjacency lists
- Dynamic programming
- Grid-based problems
- 2D array problems

---

## Time Complexity

| Operation | Complexity |
|---|---|
| Access by index | O(1) |
| `front()` / `back()` | O(1) |
| `size()` | O(1) |
| `push_back()` | O(1) amortized |
| `pop_back()` | O(1) |
| Insertion at beginning | O(n) |
| Insertion at middle | O(n) |
| Deletion at beginning | O(n) |
| Deletion at middle | O(n) |
| Searching | O(n) |
| Traversal | O(n) |

---

## Advantages

- Dynamic size
- Automatic memory management
- Fast random access
- Easy insertion and deletion at the end
- STL algorithms compatibility
- Useful for competitive programming and DSA

## Limitations

- Insertion and deletion in the middle can be expensive.
- Reallocation may occur when capacity is exceeded.
- Elements are stored contiguously, so inserting at the beginning requires shifting elements.

---

## Applications in DSA

Vectors are commonly used in:

- Array problems
- Binary search
- Sorting algorithms
- Two-pointer problems
- Sliding window
- Prefix sums
- Dynamic programming
- Graphs
- Matrix problems

---

## Key Takeaways

1. A vector is a dynamic array.
2. Indexing starts from 0.
3. `push_back()` adds an element at the end.
4. `pop_back()` removes the last element.
5. `size()` returns the number of elements.
6. `capacity()` returns allocated storage.
7. `insert()` and `erase()` can require shifting elements.
8. `resize()` changes size, whereas `reserve()` changes capacity.
9. Vectors support random access in O(1).
10. Vectors are one of the most useful STL containers for DSA.

---
