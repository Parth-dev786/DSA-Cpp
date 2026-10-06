# Peak Index in a Mountain Array

## 1. Problem

Given a **mountain array**, find the index of its peak element.

A mountain array:

```text
Increasing → Peak → Decreasing
```

Example:

```text
[0, 2, 5, 3, 1]
       ↑
     Peak
```

Answer: `2`

---

## 2. Core Concept

Use **Binary Search**.

At `mid`, compare it with its two neighbors:

```text
arr[mid - 1]   arr[mid]   arr[mid + 1]
       ←          ↑           →
```

### Case 1: `mid` is the peak

```cpp
arr[mid] > arr[mid - 1] &&
arr[mid] > arr[mid + 1]
```

→ `mid` is the answer.

### Case 2: Increasing side

```cpp
arr[mid] > arr[mid - 1]
```

We are moving upward, so the peak is on the **right**.

```cpp
start = mid + 1;
```

### Case 3: Decreasing side

Otherwise, we are on the decreasing side.

The peak is on the **left**.

```cpp
end = mid - 1;
```

### Key Idea

> **Check the peak first → otherwise identify the slope → eliminate half of the array.**

---

## 3. Algorithm

1. Set `start = 1`.
2. Set `end = n - 2`.
3. Find `mid`.
4. If `mid` is greater than both neighbors, return `mid`.
5. If `arr[mid] > arr[mid - 1]`, move right:
   `start = mid + 1`.
6. Otherwise, move left:
   `end = mid - 1`.
7. Continue until the peak is found.

We start from `1` and end at `n - 2` because we access:

```cpp
arr[mid - 1]
arr[mid + 1]
```

---

## 4. Code

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int start = 1;
        int end = arr.size() - 2;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // mid is the peak
            if (arr[mid] > arr[mid - 1] &&
                arr[mid] > arr[mid + 1]) {

                return mid;
            }

            // Increasing side
            else if (arr[mid] > arr[mid - 1]) {

                start = mid + 1;
            }

            // Decreasing side
            else {

                end = mid - 1;
            }
        }

        return -1;
    }
};
```

---

## 5. Dry Run

Given:

```text
arr = [0, 2, 5, 3, 1]
```

```text
Index:  0  1  2  3  4
Array:  0  2  5  3  1
            ↑
          Peak
```

### Initial

```text
start = 1
end = 3
```

### Find mid

```text
mid = start + (end - start) / 2
    = 1 + (3 - 1) / 2
    = 2
```

Now:

```text
arr[mid]     = 5
arr[mid - 1] = 2
arr[mid + 1] = 3
```

Check:

```text
5 > 2  ✓
5 > 3  ✓
```

Therefore `mid` is the peak.

```text
return 2;
```

### Answer

```text
Peak Index = 2
```

---

## 6. Complexity

```text
Time  : O(log n)
Space : O(1)
```

Binary search eliminates approximately half of the remaining elements in each iteration.

---

## 7. Common Mistakes

### Mistake 1: Checking only one side

To identify the peak directly, we need:

```cpp
arr[mid] > arr[mid - 1]
```

and

```cpp
arr[mid] > arr[mid + 1]
```

### Mistake 2: Wrong boundaries

Because we access `mid - 1` and `mid + 1`:

```cpp
start = 1;
end = arr.size() - 2;
```

### Mistake 3: Forgetting that `mid` can be the answer

When:

```cpp
arr[mid] > arr[mid - 1] &&
arr[mid] > arr[mid + 1]
```

immediately:

```cpp
return mid;
```

---

## 8. Remember

```text
                 mid
                  ↓
        [mid-1] [mid] [mid+1]

        ↑        ↑        ↑
     previous  current    next
```

### Peak

```cpp
arr[mid] > arr[mid - 1] &&
arr[mid] > arr[mid + 1]
```

→ `return mid`

### Increasing side

```cpp
arr[mid] > arr[mid - 1]
```

→ `start = mid + 1`

### Decreasing side

```text
otherwise
```

→ `end = mid - 1`

### One-line memory trick

> **Peak → return | Increasing → right | Decreasing → left**

---

## 9. Quick Revision

```text
start = 1
end = n - 2

while (start <= end):

    mid

    if mid > left AND mid > right
        return mid

    else if mid > left
        start = mid + 1

    else
        end = mid - 1
```

**Time:** `O(log n)`
**Space:** `O(1)`
