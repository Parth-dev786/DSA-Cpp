# Binary Search

## What is Binary Search?

Binary Search is a searching algorithm used to find an element in a **sorted search space**.

Instead of checking every element one by one, Binary Search checks the middle element and eliminates approximately half of the remaining search space after each comparison.

---

## Why Do We Need It?

Suppose we have:

```text
10 20 30 40 50 60 70
```

If we use Linear Search to find `60`, we may need to check several elements one by one.

Because the array is sorted, we can do better.

We check the middle:

```text
10 20 30 40 50 60 70
         ↑
        mid
```

Since:

```text
40 < 60
```

we know that `60` must be on the right side.

Therefore, the entire left half can be ignored.

This process continues until the element is found or no elements remain.

---

## Core Idea

```text
Check middle
     ↓
Compare with target
     ↓
Equal?
 /    \
Yes    No
 |      |
Found   Decide which half
        ↓
   Eliminate one half
        ↓
      Repeat
```

### Mental Model

> **Binary Search = Check the middle + eliminate half of the search space**

---

## Requirements

For basic Binary Search on an array:

1. The array should be sorted.
2. We need a target value to search for.
3. We maintain a search range using `low` and `high`.

---

## How It Works

Initially:

```cpp
low = 0;
high = n - 1;
```

Calculate the middle:

```cpp
int mid = low + (high - low) / 2;
```

Then compare:

### Target found

```cpp
arr[mid] == target
```

Return `mid`.

### Target is greater

```cpp
arr[mid] < target
```

Search the right half:

```cpp
low = mid + 1;
```

### Target is smaller

```cpp
arr[mid] > target
```

Search the left half:

```cpp
high = mid - 1;
```

Continue while:

```cpp
low <= high
```

If the loop ends, the target does not exist.

---

## Example

Array:

```text
10 20 30 40 50 60 70
```

Target:

```text
60
```

### Step 1

```text
low = 0
high = 6
mid = 3
```

```text
arr[mid] = 40
```

Since:

```text
40 < 60
```

search right:

```text
low = 4
```

### Step 2

```text
low = 4
high = 6
mid = 5
```

```text
arr[mid] = 60
```

Target found at:

```text
index = 5
```

---

## C++ Implementation

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {

    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;

    int target = 60;

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Element found at index: " << result;
    }
    else {
        cout << "Element not found";
    }

    return 0;
}
```

### Output

```text
Element found at index: 5
```

---

## Why `mid = low + (high - low) / 2`?

A common formula is:

```cpp
mid = (low + high) / 2;
```

It works for normal values, but:

```cpp
mid = low + (high - low) / 2;
```

is preferred because it avoids potential integer overflow when `low` and `high` are very large.

---

## Time Complexity

### Best Case

The target is found at the first middle check:

```text
O(1)
```

### Average Case

The search space is repeatedly divided approximately in half:

```text
O(log n)
```

### Worst Case

The search continues until the search space becomes empty:

```text
O(log n)
```

### Space Complexity

For the iterative implementation:

```text
O(1)
```

because only a few variables are used.

---

## Why is it O(log n)?

Every iteration approximately halves the search space:

```text
n
↓
n/2
↓
n/4
↓
n/8
↓
...
↓
1
```

Therefore, the number of iterations grows logarithmically.

### Key Comparison

Linear Search:

```text
n → n-1 → n-2 → ...
```

Binary Search:

```text
n → n/2 → n/4 → n/8 → ...
```

---

## When to Use

Use Binary Search when:

* The data is sorted.
* You need to repeatedly search for values.
* You can safely eliminate half of the search space after each comparison.

### Recognition Rule

Ask:

> **"After checking the middle, can I confidently eliminate half of the possible answers?"**

If yes, Binary Search may be applicable.

---

## When NOT to Use

Do not directly use basic Binary Search when:

* The array is unsorted.
* You cannot determine which half can be eliminated.
* The data is very small and a simple linear search is sufficient.

---

## Common Mistakes

### 1. Using Binary Search on an unsorted array

Incorrect:

```text
7 2 9 4 5
```

Basic Binary Search cannot safely eliminate half here.

---

### 2. Incorrect boundary update

Correct:

```cpp
low = mid + 1;
```

and:

```cpp
high = mid - 1;
```

Do not keep `mid` in the search range after determining that it is not the target.

---

### 3. Incorrect loop condition

Use:

```cpp
while (low <= high)
```

because the case `low == high` still represents one valid element that needs to be checked.

---

### 4. Forgetting the not-found case

If the loop finishes without finding the target:

```cpp
return -1;
```

---

### 5. Confusing index and value

If:

```text
arr = [10, 20, 30, 40]
```

and `30` is found:

```text
value = 30
index = 2
```

Binary Search code above returns the **index**, not the value.

---

## Self-Teaching Questions

1. What problem does Binary Search solve?
2. Why must the array be sorted for basic Binary Search?
3. What are `low`, `mid`, and `high`?
4. What happens when `arr[mid] == target`?
5. What happens when `arr[mid] < target`?
6. What happens when `arr[mid] > target`?
7. Why do we use `mid + 1` and `mid - 1`?
8. Why is Binary Search `O(log n)`?
9. Why is iterative Binary Search `O(1)` space?
10. What happens when the target doesn't exist?
11. Can Binary Search work on `[7, 2, 9, 4, 5]` directly? Why?
12. Can you explain Binary Search without looking at the code?

---

## Small Practice

Write Binary Search for:

```cpp
int arr[] = {5, 10, 15, 20, 25, 30, 35};
```

Search for:

```text
25
```

Then test:

```text
17
```

Do not use `sort()` or Linear Search.

---

## Quick Revision

### Definition

> Binary Search searches a **sorted search space** by repeatedly checking the middle and eliminating half of the search space.

### Variables

```cpp
low
mid
high
```

### Middle

```cpp
mid = low + (high - low) / 2;
```

### Target found

```cpp
arr[mid] == target
```

### Go right

```cpp
arr[mid] < target

low = mid + 1;
```

### Go left

```cpp
arr[mid] > target

high = mid - 1;
```

### Loop

```cpp
while (low <= high)
```

### Not found

```cpp
return -1;
```

### Complexity

```text
Best:    O(1)
Average: O(log n)
Worst:   O(log n)
Space:   O(1)  [iterative]
```

### One-line mental model

> **Middle → Compare → Eliminate half → Repeat**

---

