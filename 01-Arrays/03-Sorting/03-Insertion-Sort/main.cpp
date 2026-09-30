#include<iostream>
using namespace std;
int main(){

    int arr[5];
     int element , i,n;
     cout<<"enter size : ";
     cin>>n;
    cout<<"enter elements";
   for(i = 0 ;i<n;i++){
        cin>>arr[i];
   }
    

    for(i=1;i<n;i++){
        for(int j =i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            else{
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

//Desceding order

// #include<iostream>
// using namespace std;
// int main(){

//     int arr[5];
//      int element , i,n;
//      cout<<"enter size : ";
//      cin>>n;
//     cout<<"enter elements";
//    for(i = 0 ;i<n;i++){
//         cin>>arr[i];
//    }
    

//     for(i=1;i<n;i++){
//         for(int j =i;j>0;j--){
//             if(arr[j]>arr[j-1]){
//                 swap(arr[j],arr[j-1]);
//             }
//             else{
//                 break;
//             }
//         }
//     }
//     for(i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }

// }


// ----> other way to write insertion code code 

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
----------------------------


DRY RUN 
    
# Insertion Sort

## Given Array

```text
[5, 3, 4, 1, 2]
```

Insertion Sort treats the first element as already sorted.

---

## Initial State

```text
Sorted      Unsorted
[5]         [3, 4, 1, 2]
```

---

## Pass 1 — `i = 1`

```text
key = 3
j = 0
```

Array:

```text
[5, 3, 4, 1, 2]
 ↑  ↑
 j key
```

Check:

```text
5 > 3 → Yes
```

Shift `5` to the right:

```text
[5, 5, 4, 1, 2]
```

Now:

```text
j = -1
```

Place `key = 3` at `j + 1 = 0`:

```text
[3, 5, 4, 1, 2]
```

Sorted part:

```text
[3, 5]
```

---

## Pass 2 — `i = 2`

```text
key = 4
j = 1
```

Array:

```text
[3, 5, 4, 1, 2]
    ↑  ↑
    j key
```

Check:

```text
5 > 4 → Yes
```

Shift `5`:

```text
[3, 5, 5, 1, 2]
```

Now:

```text
j = 0
```

Check:

```text
3 > 4 → No
```

Place `key = 4` at `j + 1 = 1`:

```text
[3, 4, 5, 1, 2]
```

Sorted part:

```text
[3, 4, 5]
```

---

## Pass 3 — `i = 3`

```text
key = 1
j = 2
```

Array:

```text
[3, 4, 5, 1, 2]
       ↑  ↑
       j key
```

### Step 1

```text
5 > 1 → Yes
```

Shift `5`:

```text
[3, 4, 5, 5, 2]
```

```text
j = 1
```

### Step 2

```text
4 > 1 → Yes
```

Shift `4`:

```text
[3, 4, 4, 5, 2]
```

```text
j = 0
```

### Step 3

```text
3 > 1 → Yes
```

Shift `3`:

```text
[3, 3, 4, 5, 2]
```

```text
j = -1
```

Stop because:

```text
j >= 0 → False
```

Place `key = 1` at `j + 1 = 0`:

```text
[1, 3, 4, 5, 2]
```

Sorted part:

```text
[1, 3, 4, 5]
```

---

## Pass 4 — `i = 4`

```text
key = 2
j = 3
```

Array:

```text
[1, 3, 4, 5, 2]
          ↑  ↑
          j key
```

### Step 1

```text
5 > 2 → Yes
```

Shift `5`:

```text
[1, 3, 4, 5, 5]
```

```text
j = 2
```

### Step 2

```text
4 > 2 → Yes
```

Shift `4`:

```text
[1, 3, 4, 4, 5]
```

```text
j = 1
```

### Step 3

```text
3 > 2 → Yes
```

Shift `3`:

```text
[1, 3, 3, 4, 5]
```

```text
j = 0
```

### Step 4

```text
1 > 2 → No
```

Stop.

Place `key = 2` at `j + 1 = 1`:

```text
[1, 2, 3, 4, 5]
```

---

# Final Result

```text
[1, 2, 3, 4, 5]
```

## Complete Dry Run at a Glance

| Pass | `i` | `key` | Sorted Part Before | Result            |
| ---- | --: | ----: | ------------------ | ----------------- |
| 1    |   1 |     3 | `[5]`              | `[3, 5]`          |
| 2    |   2 |     4 | `[3, 5]`           | `[3, 4, 5]`       |
| 3    |   3 |     1 | `[3, 4, 5]`        | `[1, 3, 4, 5]`    |
| 4    |   4 |     2 | `[1, 3, 4, 5]`     | `[1, 2, 3, 4, 5]` |

## Core Flow

```text
Pick key
   ↓
Compare with elements on the left
   ↓
If element > key
   ↓
Shift element one position right
   ↓
Move j backward
   ↓
Place key at j + 1
```




