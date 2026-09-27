
#include<iostream>
using namespace std;
int main(){
    int arr[1000];
    int n,i;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the element in array : ";
    for(i = 0;i<n;i++){
        cin>>arr[i];
    }

    for(i=n-2;i>=0;i--){
        bool swapped = 0;
        for(int j = 0;j<=i;j++){
            if(arr[j]>arr[j+1]){
                swapped = 1;
                swap(arr[j],arr[j+1]);
            }
        }

        if(swapped == 0)
        break;
    }

    for(i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

---------

//WE also use loop this way

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {

    int arr[] = {5, 3, 8, 1, 2};
    int n = 5;

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

Output:

1 2 3 5 8

  -------

// Optimized Bubble Sort

We can stop early if a complete pass performs no swaps.

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
Why?

For:

[1, 2, 3, 4, 5]
