# Insertion Sort

Insertion Sort is a comparison-based sorting algorithm that builds the sorted array one element at a time.

The main idea is similar to arranging playing cards in your hand:

> Take one element and insert it into its correct position in the already sorted portion.

---

## What is the Problem?

Given an unsorted array:

```text
[5, 3, 4, 1, 2]
```

we want:

```text
[1, 2, 3, 4, 5]
```

Insertion Sort solves this by maintaining a sorted portion and inserting each new element into its correct position.

---

## Core Idea

Think of the array as:

```text
[ SORTED PART | UNSORTED PART ]
```

Initially:

```text
[5 | 3, 4, 1, 2]
```

Take `3` and insert it into the sorted part:

```text
[3, 5 | 4, 1, 2]
```

Take `4`:

```text
[3, 4, 5 | 1, 2]
```

Continue until the complete array is sorted.

---

## How It Works

For every element starting from index `1`:

1. Store the current element in `key`.
2. Look at elements to its left.
3. While an element is greater than `key`, shift it one position right.
4. Move left.
5. Insert `key` into the empty/correct position.

---

## Why Does the Loop Start at `1`?

The first element by itself is already sorted.

For:

```text
[5, 3, 4, 1, 2]
```

we initially consider:

```text
[5 | 3, 4, 1, 2]
```

Therefore:

```cpp
for (int i = 1; i < n; i++)
```

---

## Important Variables

```cpp
int key = arr[i];
int j = i - 1;
```

### `i`

The index of the element currently being inserted.

### `key`

The value that needs to be inserted into the sorted portion.

### `j`

Used to move backward through the sorted portion.

---

## C++ Implementation

```cpp
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {

    int arr[] = {5, 3, 4, 1, 2};
    int n = 5;

    insertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

### Output

```text
1 2 3 4 5
```

---

## Dry Run

Initial array:

```text
[5, 3, 4, 1, 2]
```

### Insert `3`

```text
[5 | 3, 4, 1, 2]
```

`5 > 3`, so shift `5`:

```text
[5, 5, 4, 1, 2]
```

Insert `3`:

```text
[3, 5, 4, 1, 2]
```

---

### Insert `4`

```text
[3, 5 | 4, 1, 2]
```

`5 > 4`, so shift:

```text
[3, 5, 5, 1, 2]
```

Insert `4`:

```text
[3, 4, 5, 1, 2]
```

---

### Insert `1`

```text
[3, 4, 5 | 1, 2]
```

Shift all larger elements:

```text
[3, 4, 5, 5, 2]
[3, 4, 4, 5, 2]
[3, 3, 4, 5, 2]
```

Insert `1`:

```text
[1, 3, 4, 5, 2]
```

---

### Insert `2`

```text
[1, 3, 4, 5 | 2]
```

Shift:

```text
[1, 3, 4, 5, 5]
[1, 3, 4, 4, 5]
[1, 3, 3, 4, 5]
```

Insert `2`:

```text
[1, 2, 3, 4, 5]
```

---

## Why `j + 1`?

After shifting, `j` points to the element just before the correct insertion position.

Example:

```text
[2, 5, 8]
```

Insert:

```text
4
```

After shifting `5`:

```text
[2, 5, 5, 8]
```

Now:

```text
j = 0
```

Since `2 > 4` is false, `4` belongs at:

```text
j + 1 = 1
```

So:

```cpp
arr[j + 1] = key;
```

---

## Why `j >= 0`?

This prevents accessing an invalid index.

Without it, `j` could become `-1` and the program could attempt to access:

```cpp
arr[-1]
```

So:

```cpp
while (j >= 0 && arr[j] > key)
```

means:

> Continue shifting while we are inside the array and the current element is larger than `key`.

---

## Time Complexity

### Best Case

Already sorted:

```text
[1, 2, 3, 4, 5]
```

Very little shifting is required.

```text
O(n)
```

### Average Case

```text
O(n²)
```

### Worst Case

Reverse sorted:

```text
[5, 4, 3, 2, 1]
```

Many elements must be shifted.

```text
O(n²)
```

The work is approximately:

```text
1 + 2 + 3 + ... + (n - 1)
```

which grows quadratically.

### Space Complexity

```text
O(1)
```

Insertion Sort sorts the array in-place.

---

## Important Properties

| Property         | Insertion Sort                        |
| ---------------- | ------------------------------------- |
| Comparison-based | Yes                                   |
| In-place         | Yes                                   |
| Stable           | Yes, with the standard `>` comparison |
| Best case        | O(n)                                  |
| Average case     | O(n²)                                 |
| Worst case       | O(n²)                                 |
| Extra space      | O(1)                                  |

---

## When to Use

Insertion Sort is useful for:

* Small datasets
* Nearly sorted data
* Learning sorting algorithms
* Understanding insertion and shifting
* Situations where elements are incrementally inserted into an ordered sequence

---

## When NOT to Use

Avoid choosing it as a general sorting solution for large random datasets because its average and worst-case complexity is:

```text
O(n²)
```

For such cases, more efficient sorting approaches or standard library sorting are generally preferred.

---

## Bubble Sort vs Insertion Sort

### Bubble Sort

```text
Compare adjacent elements
        ↓
Swap when necessary
        ↓
Largest element moves toward the end
```

### Insertion Sort

```text
Take next element
        ↓
Shift larger elements
        ↓
Insert element in correct position
```

The main difference is the strategy:

> Bubble Sort repeatedly swaps adjacent elements, while Insertion Sort builds a sorted portion and inserts each new element into it.

---

## Common Mistakes

### Mistake 1 — Starting from `i = 0`

Incorrect:

```cpp
for (int i = 0; i < n; i++)
```

Usually we start from:

```cpp
for (int i = 1; i < n; i++)
```

because the first element is already sorted by itself.

---

### Mistake 2 — Forgetting `key`

Incorrectly modifying the value before preserving it can cause the value being inserted to be lost.

Use:

```cpp
int key = arr[i];
```

---

### Mistake 3 — Using the wrong condition

For ascending order:

```cpp
arr[j] > key
```

For descending order:

```cpp
arr[j] < key
```

---

### Mistake 4 — Using `arr[j] = key`

The correct position after shifting is:

```cpp
arr[j + 1] = key;
```

---

### Mistake 5 — Forgetting the boundary check

Use:

```cpp
j >= 0
```

so that the algorithm doesn't access an invalid index.

---

## Self-Teaching Questions

1. What problem does Insertion Sort solve?
2. Why is the first element considered sorted?
3. Why does the outer loop start at `1`?
4. What does `key` represent?
5. Why do we shift elements?
6. Why don't we simply overwrite them?
7. What does `j` represent?
8. Why is the condition `arr[j] > key`?
9. Why do we finally write `arr[j + 1] = key`?
10. What happens when `key` is smaller than every previous element?
11. Why is the best case O(n)?
12. Why is the worst case O(n²)?
13. Why is the space complexity O(1)?
14. How is Insertion Sort different from Bubble Sort?

---

## Small Practice

### Task 1

Dry run:

```text
[5, 2, 4, 6, 1, 3]
```

Show the array after every insertion.

### Task 2

Write your own C++ implementation without using:

```cpp
sort()
```

### Task 3

Modify your program to sort in descending order.

---

## Quick Revision

### Mental Model

```text
[ SORTED | UNSORTED ]
       ↓
Take next element
       ↓
Shift larger elements right
       ↓
Insert key
       ↓
Sorted portion grows
```

### Important code

```cpp
for (int i = 1; i < n; i++) {

    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}
```

### Complexity

```text
Best:    O(n)
Average: O(n²)
Worst:   O(n²)
Space:   O(1)
```

### Remember

> **Insertion Sort builds a sorted portion one element at a time.**

---

