// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int arr[10],arr1[10],i,n,m,target;
//     cin>>n>>m;

//     for(i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for(j=0;j<m;j++){
//         cin>>arr1[j];
//     }
//     vector<int>v;

//     for(i=0;i<n;i++){
//         for(j=0;j<m;j++){
//             if(arr[i]==arr1[j]){
//                 target=arr[i];
//                 v.pushback(target);
//             }
//         }
//     }
// }
// for(i=0;i<v.size();i++){
//     cout<<v[i];
// }
#include<bits/stdc++.h>
using namespace std;

//no need to remove duplicates from the array if we have to find intersection

int main(){
    int n,m;
    cin>>n>>m;

    int arr[n], arr2[m];

    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int j=0; j<m; j++){
        cin>>arr2[j];
    }

    int i=0, j=0;

    while(i<n && j<m){
        if(arr[i]<arr2[j]){
            i++;
        }

        else if(arr[i]>arr2[j]){
            j++;
        }

        else if(arr[i]==arr2[j]){
            cout<<arr[i]<<" ";
            i++;
            j++;
        }
    }
}