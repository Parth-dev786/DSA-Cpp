# Sorting in C++

Sorting is a fundamental concept in Data Structures and Algorithms (DSA).

It is the process of **arranging data according to a specific ordering rule**.

The most common orders are:

- **Ascending Order:** Small → Large
- **Descending Order:** Large → Small

Example:

```text
Unsorted:
5  2  8  1  3

Ascending:
1  2  3  5  8

Descending:
8  5  3  2  1

-----------------------------------
How Does Sorting Work?

At a basic level, sorting follows this process:

Compare
   ↓
Decide
   ↓
Rearrange
   ↓
Repeat

For example:

5  2  8  1

The algorithm compares elements and rearranges them until the required order is achieved.

Final result:

1  2  5  8

Different sorting algorithms use different ways to perform these operations.

-> Ordering Rule

A sorting algorithm needs an ordering rule.

The ordering rule determines:

Which element should come before which?

Numbers

Ascending:

2 comes before 5

Descending:

5 comes before 2
Strings

Alphabetical order:

apple
ball
cat
Objects

Students can be sorted by:

Marks
Name
Roll number
Age

Therefore:

Sorting means arranging elements according to a defined ordering rule.

-> Sorting Is Not Only for Numbers

Sorting can be applied to different types of data.

Numbers
5  2  8  1

Sorted:

1  2  5  8
Characters
z  a  c  b

Sorted:

a  b  c  z
Strings
"cat"
"apple"
"ball"

Sorted:

"apple"
"ball"
"cat"
Objects

For example, students can be sorted by:

Marks
Name
Roll Number
Age
-> Why Are There Different Sorting Algorithms?

There is no single sorting algorithm that is ideal for every situation.

Different sorting algorithms can have different:

Time complexity
Space complexity
Number of comparisons
Number of swaps
Memory usage
Stability
Implementation complexity
Performance for different inputs

Therefore:

The choice of sorting algorithm depends on the problem requirements.

-> Important Sorting Properties

When studying a sorting algorithm, consider:

Property	Meaning
Time Complexity	How the amount of work grows with input size
Space Complexity	How much additional memory is required
Stability	Whether equal elements keep their relative order
In-Place	Whether the algorithm mainly rearranges the original data
Comparisons	Number of element comparisons
Swaps	Number of element rearrangements
------------------------------------------------------------------
-> Time Complexity of Sorting

Time complexity describes how the amount of work grows as the input size n increases.

Common sorting complexities include:

O(n²)
O(n log n)

Some algorithms can have different complexities for different cases:

Best Case
Average Case
Worst Case

When learning a sorting algorithm, understand why it has its particular complexity instead of simply memorizing it.
-----------------------------------------------
-> Space Complexity of Sorting

Space complexity describes how the additional memory requirement grows with input size.

A sorting algorithm may:

Rearrange elements inside the original array.
Use a small amount of extra memory.
Create additional arrays or data structures.

Therefore, analyze both:

Time Complexity
+
Space Complexity
------------------------------------------------

Some important function :-
#include <algorithm>

sort(arr, arr + n);

sort() — Descending Order
sort(arr, arr + n, greater<int>());

swap()
swap(a, b);

reverse():-
reverse(arr, arr + n);

min()
Returns the smaller value

max()
Returns the larger value.

is_sorted()

Very useful for checking whether an array/range is already sorted.

is_sorted(arr, arr + n);

---------------------------
sort(arr, arr + n);        // actually sorts
is_sorted(arr, arr + n);   // only checks



