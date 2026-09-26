# Selection Sort

Selection Sort is a simple comparison-based sorting algorithm that repeatedly selects the smallest element from the unsorted portion of an array and places it at the correct position.

---

## 1. What Problem Does Selection Sort Solve?

Selection Sort solves the problem of arranging elements in a particular order.

For example:

```text
Before:
[64, 25, 12, 22, 11]

After:
[11, 12, 22, 25, 64]
```

The main idea is:

```text
Find minimum → Place it correctly → Repeat
```

---

## 2. Why Do We Need Selection Sort?

A simple way to sort an array is to repeatedly find the element that should come next and place it at the correct position.

Selection Sort follows this idea directly.

It is useful for understanding:

- Comparison-based sorting
- Finding minimum/maximum
- Swapping elements
- Nested loops
- In-place sorting

---

## 3. Core Idea

Selection Sort divides the array logically into two parts:

```text
Sorted Portion | Unsorted Portion
```

Initially:

```text
[] | [64, 25, 12, 22, 11]
```

After the first pass:

```text
[11] | [25, 12, 22, 64]
```

After the second pass:

```text
[11, 12] | [25, 22, 64]
```

The sorted portion grows by one element after every pass.

---

## 4. How Selection Sort Works

For ascending order:

1. Start from the first index.
2. Assume the current element is the minimum.
3. Search the remaining unsorted portion.
4. If a smaller element is found, remember its index.
5. After the search is complete, swap the minimum with the current element.
6. Move to the next position.
7. Repeat until the array is sorted.

The important pattern is:

```text
Select → Place → Repeat
```

---

## 5. Example

Consider:

```text
[29, 10, 14, 37, 13]
```

### Pass 1

Minimum = `10`

```text
[10, 29, 14, 37, 13]
```

### Pass 2

Minimum of remaining elements = `13`

```text
[10, 13, 14, 37, 29]
```

### Pass 3

Minimum = `14`

```text
[10, 13, 14, 37, 29]
```

### Pass 4

Minimum = `29`

```text
[10, 13, 14, 29, 37]
```

Final sorted array:

```text
[10, 13, 14, 29, 37]
```
---

## 7. Important Variables

### `i`

Represents the position where the next minimum element should be placed.

```cpp
for (int i = 0; i < n - 1; i++)
```

### `minIndex`

Stores the index of the smallest element found in the unsorted portion.

```cpp
int minIndex = i;
```

### `j`

Used to search the remaining unsorted elements.

```cpp
for (int j = i + 1; j < n; j++)
```

---

## 8. Why Use `minIndex`?

We need the position of the minimum element so that we can swap it.

For example:

```text
[64, 25, 12, 22, 11]
                    ↑
                 minimum
```

The minimum value is `11`, but we also need to know its index.

Therefore, we store:

```cpp
minIndex
```

instead of only the minimum value.

---

## 9. Why Does `j` Start From `i + 1`?

The elements before `i` are already sorted.

Therefore, we only search the unsorted portion.

```text
Sorted | Unsorted
        ↑
        i
```

So the search begins at:

```cpp
j = i + 1
```

---

## 10. Why Swap Only Once?

Selection Sort first searches the entire unsorted portion.

It does not swap every time it finds a smaller element.

The process is:

```text
Search
  ↓
Find minimum
  ↓
Remember its index
  ↓
Swap once
```

This is an important part of Selection Sort.

---

## 11. Time Complexity

Selection Sort performs approximately:

```text
(n - 1) + (n - 2) + ... + 1
```

comparisons.

Therefore:

```text
Time Complexity = O(n²)
```

### Best Case

```text
O(n²)
```

### Average Case

```text
O(n²)
```

### Worst Case

```text
O(n²)
```

Even if the array is already sorted, Selection Sort still searches the remaining portion.

---

## 12. Space Complexity

Selection Sort works in-place.

It uses only a few extra variables such as:

```text
i
j
minIndex
```

Therefore:

```text
Auxiliary Space = O(1)
```

---

## 13. Ascending and Descending Order

### Ascending

Select the minimum element:

```cpp
if (arr[j] < arr[minIndex])
```

Example:

```text
1 2 3 4 5
```

### Descending

Select the maximum element.

The idea becomes:

```text
Find maximum → Place it at the beginning → Repeat
```

Example:

```text
5 4 3 2 1
```

---

## 14. Important Properties

| Property | Selection Sort |
|---|---|
| Type | Comparison-based |
| Best Case | `O(n²)` |
| Average Case | `O(n²)` |
| Worst Case | `O(n²)` |
| Auxiliary Space | `O(1)` |
| In-place | Yes |
| Stable | No, in the usual implementation |

---

## 15. When to Use

Selection Sort is useful for:

- Learning sorting concepts
- Learning nested loops
- Understanding selection and swapping
- Small datasets
- Understanding in-place sorting

It is especially useful while learning DSA.

---

## 16. When NOT to Use

Selection Sort is generally not suitable for large datasets because its time complexity is:

```text
O(n²)
```

When the input becomes large, more efficient sorting algorithms are generally preferred.

---

## 17. Common Mistakes

### Mistake 1: Starting `j` from `0`

Incorrect:

```cpp
for (int j = 0; j < n; j++)
```

Correct:

```cpp
for (int j = i + 1; j < n; j++)
```

---

### Mistake 2: Swapping immediately

Do not swap every time you find a smaller element.

First find the minimum, then swap.

---

### Mistake 3: Confusing index and value

```cpp
minIndex = j;
```

means:

```text
The minimum element is at index j.
```

It does not mean that `j` is the minimum value.

---

### Mistake 4: Forgetting to reset `minIndex`

For every new position:

```cpp
int minIndex = i;
```

must be set again.

---

## 18. Self-Teaching Questions

1. What problem does Selection Sort solve?
2. Why is it called Selection Sort?
3. What does `i` represent?
4. What does `minIndex` represent?
5. Why does `j` start from `i + 1`?
6. Why do we search the complete unsorted portion before swapping?
7. Why are there only `n - 1` passes?
8. Why is Selection Sort `O(n²)`?
9. Why is its auxiliary space `O(1)`?
10. Is Selection Sort stable in its usual implementation?
11. How would you modify it for descending order?
12. Can you explain Selection Sort without looking at the code?

---


### Important Points

- Select the minimum for ascending order.
- Select the maximum for descending order.
- `minIndex` stores the position of the minimum.
- Search starts from `i + 1`.
- Swap after finding the minimum.
- Sorted portion grows after every pass.
- Time Complexity = `O(n²)`
- Auxiliary Space = `O(1)`
- In-place = Yes
- Stable = No (usual implementation)

---
