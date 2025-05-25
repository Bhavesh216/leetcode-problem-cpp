#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    stack<int>st;
    
    for(int i=n; i>=0; i--){
        int count = 1;
        for(int j=i-1; j>=0; j--){
            if(arr[j]<arr[i]){
                count++;
            }
        }
        st.push(count);
    }

    int arr2[n];
    int i = 0;
    while(!st.empty()){
        arr2[i] = st.top();
        i++;
        st.pop();
    }

    for(int i=0; i<n; i++){
        cout<<arr2[i]<<" ";
    }
}