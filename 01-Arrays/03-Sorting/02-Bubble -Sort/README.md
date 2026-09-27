# Bubble Sort

Bubble Sort is a simple comparison-based sorting algorithm that repeatedly compares adjacent elements and swaps them when they are in the wrong order.

It is mainly useful for learning sorting, nested loops, swapping, algorithm analysis, and optimization.

---

## Core Idea

For ascending order:

```cpp
if (arr[j] > arr[j + 1])
    swap(arr[j], arr[j + 1]);
```

The larger element moves toward the end through repeated adjacent swaps.

### Pattern

```text
Compare → Swap if needed → Continue → Repeat
```

After every complete pass, the largest element in the remaining unsorted portion reaches its correct position.

---

## Example

Initial:

```text
[5, 3, 8, 1, 2]
```

### Pass 1

```text
[5, 3, 8, 1, 2]
 → [3, 5, 8, 1, 2]
 → [3, 5, 8, 1, 2]
 → [3, 5, 1, 8, 2]
 → [3, 5, 1, 2, 8]
```

`8` is now fixed.

### Pass 2

```text
[3, 5, 1, 2, 8]
 → [3, 1, 5, 2, 8]
 → [3, 1, 2, 5, 8]
```

`5` is now fixed.

### Pass 3

```text
[3, 1, 2, 5, 8]
 → [1, 3, 2, 5, 8]
 → [1, 2, 3, 5, 8]
```

### Final

```text
[1, 2, 3, 5, 8]
```

---

## 🔹 Algorithm

1. Start from the beginning of the array.
2. Compare two adjacent elements.
3. If they are in the wrong order, swap them.
4. Continue until the end of the unsorted portion.
5. The largest remaining element is now fixed at the end.
6. Reduce the unsorted portion.
7. Repeat until the array is sorted.

---

## 🔹 Pseudocode

```text
BubbleSort(array, n)

for i = 0 to n - 1

    for j = 0 to n - i - 1

        if array[j] > array[j + 1]

            swap(array[j], array[j + 1])
```

---

## 🔹 Why `n - i - 1`?

This is one of the most important parts to understand.

After each pass, one more largest element reaches its final position.

```text
Pass 1 → last element fixed
Pass 2 → last 2 elements fixed
Pass 3 → last 3 elements fixed
```

Therefore, the inner loop only needs to work on the remaining unsorted portion.

```cpp
j < n - i - 1
```

Do not memorize the formula without understanding this reason.

---

## 🔹 Optimized Bubble Sort

We can stop early if a complete pass performs no swaps.

```cpp
void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);

                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}
```

### Why?

For:

```text
[1, 2, 3, 4, 5]
```

the first pass performs no swaps.

Therefore, the array is already sorted and the algorithm can stop.

---

## 🔹 Complexity

| Case             |  Time |
| ---------------- | ----: |
| Best — optimized |  O(n) |
| Average          | O(n²) |
| Worst            | O(n²) |

### Space

```text
O(1)
```

Bubble Sort works in-place and uses only a constant amount of extra space.

---

## 🔹 Why O(n²)?

The number of comparisons is approximately:

```text
(n - 1) + (n - 2) + ... + 1
```

This becomes:

```text
n(n - 1) / 2
```

Ignoring constants and lower-order terms:

```text
O(n²)
```

---

## 🔹 Important Properties

```text
Comparison-based: Yes
In-place: Yes
Stable: Yes, in the normal implementation
Adaptive: Yes, when early-exit optimization is used
```

---

## 🔹 Ascending vs Descending

### Ascending

```cpp
if (arr[j] > arr[j + 1])
    swap(arr[j], arr[j + 1]);
```

### Descending

```cpp
if (arr[j] < arr[j + 1])
    swap(arr[j], arr[j + 1]);
```

---

## 🔹 Common Mistakes

### 1. Wrong loop boundary

Incorrect:

```cpp
for (int j = 0; j < n; j++)
```

when accessing:

```cpp
arr[j + 1]
```

This can access outside the array.

---

### 2. Forgetting the shrinking range

Using:

```cpp
j < n
```

unnecessarily repeats comparisons with already sorted elements.

---

### 3. Wrong comparison

Ascending:

```cpp
arr[j] > arr[j + 1]
```

Descending:

```cpp
arr[j] < arr[j + 1]
```

---

### 4. Incorrect best-case complexity

Unoptimized Bubble Sort:

```text
Best = O(n²)
```

Optimized with early exit:

```text
Best = O(n)
```

---

## 🔹 Active Recall

Try answering these without looking at the notes:

1. What is Bubble Sort?
2. Why does it compare adjacent elements?
3. What happens after one complete pass?
4. Why does the inner loop become smaller?
5. Why is the condition `n - i - 1`?
6. What happens if the array is already sorted?
7. How does the `swapped` variable help?
8. What is the worst-case complexity?
9. Why is the space complexity O(1)?
10. Is Bubble Sort stable?
11. How do you sort in descending order?
12. What is the difference between Bubble Sort and Selection Sort?

---


## 🔹 Real-World Learning Value

Bubble Sort is rarely selected for large production datasets because of its O(n²) behavior.

Its main value is understanding:

* sorting
* nested loops
* adjacent comparisons
* swapping
* loop boundaries
* in-place algorithms
* stability
* optimization
* time complexity

---

## 🔹 Interview Questions

### Conceptual

* What is Bubble Sort?
* Why is it called Bubble Sort?
* What happens after every pass?
* Why does the inner loop shrink?
* Is Bubble Sort stable?
* Is Bubble Sort in-place?

### Complexity

* What is its best-case complexity?
* What is its average-case complexity?
* What is its worst-case complexity?
* Why is the worst case O(n²)?
* How can the best case become O(n)?

### Coding

* Implement Bubble Sort.
* Implement descending Bubble Sort.
* Count swaps.
* Count comparisons.
* Implement early stopping.

---

## 🔹 Quick Revision

```text
Bubble Sort
    ↓
Compare adjacent elements
    ↓
Swap if they are in wrong order
    ↓
Largest remaining element reaches the end
    ↓
Reduce unsorted portion
    ↓
Repeat
```

### Complexity

```text
Best:    O(n)   → optimized
Average: O(n²)
Worst:   O(n²)
Space:   O(1)
```

### Key Rule

```cpp
arr[j] > arr[j + 1]
```

means ascending order.

### Most important understanding

> After every pass, the largest element of the remaining unsorted portion reaches its final position.

---
