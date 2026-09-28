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





