// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     // Your code here
//     int arr[] = {1,2,3,4,5,6};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     n = n/2;
//     cout<<arr[n]<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    int arr[]= {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = n/2;
    for(int i=0;i<n;i++){
        if(i==m){
            continue;
        }
        else{
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}