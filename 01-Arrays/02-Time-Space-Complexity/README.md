# Time & Space Complexity

Time and Space Complexity are used to analyze how efficiently an algorithm uses * time and memory * as the input size grows.

---

## 1. Why Complexity Matters

Two algorithms can solve the same problem but have very different performance.

For example:

```text
Algorithm A → O(n)
Algorithm B → O(n²)
```

For small inputs, the difference may not matter much. As the input becomes large, the difference can become significant.

Complexity analysis helps us choose algorithms that scale better.

---

## 2. What is `n`?

`n` usually represents the size of the input.

Examples:

* Array → number of elements
* String → number of characters
* Graph → number of vertices/edges depending on the analysis

Always identify what the input size represents before calculating complexity.

---

## 3. Time Complexity

Time complexity describes how the amount of computational work grows as the input size increases.

It does * not * mean the exact number of seconds an algorithm takes.

### Common Complexities

| Complexity   | Name         |
| ------------ | ------------ |
| `O(1)`       | Constant     |
| `O(log n)`   | Logarithmic  |
| `O(n)`       | Linear       |
| `O(n log n)` | Linearithmic |
| `O(n²)`      | Quadratic    |
| `O(n³)`      | Cubic        |
| `O(2ⁿ)`      | Exponential  |
| `O(n!)`      | Factorial    |

Time Complexity — Best to Worst

| Complexity     | Name         | Example                 |
| -------------- | ------------ | ----------------------- |
| **O(1)**       | Constant     | Array access            |
| **O(log n)**   | Logarithmic  | Binary Search           |
| **O(n)**       | Linear       | Array traversal         |
| **O(n log n)** | Linearithmic | Merge Sort              |
| **O(n²)**      | Quadratic    | Nested loops            |
| **O(n³)**      | Cubic        | 3 nested loops          |
| **O(2ⁿ)**      | Exponential  | Some recursive problems |
| **O(n!)**      | Factorial    | Generating permutations |

Order: O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)

For basic DSA, focus first on:

```text
O(1)
O(log n)
O(n)
O(n log n)
O(n²)
```

---

## 4. O(1) — Constant Time

The amount of work does not grow with `n`.

```cpp
int x = arr[0];
```

```text
Time: O(1)
```

`O(1)` does not necessarily mean exactly one operation. It means the growth is independent of the input size.

---

## 5. O(n) — Linear Time

The work grows approximately in proportion to the input size.

```cpp
for(int i = 0; i < n; i++) {
    cout << arr[i];
}
```

The loop runs approximately `n` times.

```text
Time: O(n)
```

---

## 6. O(n²) — Quadratic Time

Two loops that both depend on `n` often result in quadratic complexity.

```cpp
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        cout << i << " " << j;
    }
}
```

Approximately:

```text
n × n = n²
```

Therefore:

```text
Time: O(n²)
```

---

## 7. Consecutive Loops

```cpp
for(int i = 0; i < n; i++) {
    // O(n)
}

for(int j = 0; j < n; j++) {
    // O(n)
}
```

Total:

```text
O(n) + O(n)
= O(2n)
= O(n)
```

Constant factors are ignored in asymptotic analysis.

---

## 8. Dominant Term

Consider:

```text
O(n² + n + 10)
```

For large values of `n`, `n²` grows faster than the other terms.

Therefore:

```text
O(n² + n + 10) → O(n²)
```

Examples:

```text
O(5n)          → O(n)
O(n + 100)     → O(n)
O(n² + n)      → O(n²)
O(n³ + n² + n) → O(n³)
```

---

## 9. O(log n)

Logarithmic complexity commonly appears when the problem size is repeatedly reduced by a factor.

Example:

```text
n
n/2
n/4
n/8
n/16
...
```

The number of steps grows approximately as:

```text
log₂(n)
```

Therefore:

```text
O(log n)
```

This idea is important for algorithms such as Binary Search.

---

## 10. Important Loop Rule

Do not assume:

> Nested loop = O(n²)

Always analyze the actual number of iterations.

Example:

```cpp
for(int i = 0; i < n; i++) {
    for(int j = 0; j < 10; j++) {
        cout << j;
    }
}
```

The inner loop is constant:

```text
10
```

Therefore:

```text
n × 10 = O(n)
```

---

## 11. Space Complexity

Space complexity describes how memory usage grows with input size.

Example:

```cpp
int x = 10;
```

Uses constant additional memory:

```text
O(1)
```

Example:

```cpp
int arr[n];
```

Memory grows with `n`:

```text
O(n)
```

---

## 12. Auxiliary Space

Auxiliary space refers to the additional memory used by an algorithm apart from the input.

Example:

```cpp
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i];
    }
}
```

No additional array is created.

```text
Auxiliary Space: O(1)
```

---

## 13. Best, Average and Worst Case

An algorithm can behave differently for different inputs.

For a simple search:

```text
Best Case    → O(1)
Worst Case   → O(n)
```

Always check which case is being discussed.

---

## 14. How to Calculate Complexity

Use this process:

1. Identify the input size.
2. Analyze loops and operations.
3. Determine how many times each part executes.
4. Add the complexity of consecutive sections.
5. Multiply dependent nested loops when appropriate.
6. Keep the dominant term.
7. Ignore constant factors.

---

## 15. Common Mistakes

### ❌ Mistake 1

Thinking:

```text
O(n) = n seconds
```

Complexity describes growth, not exact execution time.

### ❌ Mistake 2

Assuming every nested loop is `O(n²)`.

Analyze the actual loop ranges.

### ❌ Mistake 3

Forgetting space complexity.

A solution should be analyzed for both time and memory.

### ❌ Mistake 4

Memorizing Big-O without understanding the code.

Always ask:

> How many times does this operation actually execute?

---

## 16. Quick Reference

```text
O(1)        → Constant
O(log n)    → Logarithmic
O(n)        → Linear
O(n log n)  → Linearithmic
O(n²)       → Quadratic
```

Important simplifications:

```text
O(2n)        → O(n)
O(n + n)     → O(n)
O(n² + n)    → O(n²)
O(n × 10)    → O(n)
```
