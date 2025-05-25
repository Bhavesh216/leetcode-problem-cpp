#include<bits/stdc++.h>
using namespace std;

int main(){

    int h[10],i,n;
    cout<<"\n number of inputs ";
    cin>>n;
    cout<<"\n enter heights";
    for(i=0;i<n;i++){
        cin>>h[i];
    }

    vector<int>left(n);
    vector<int>right(n);

    left[0]=h[0];
    for(i=1;i<n;i++){
       left[i]=max(left[i-1],h[i]);
    }

    right[n-1]=h[n-1];
    for(i=n-2;i>=0;i--){
        right[i]=max(right[i+1],h[i]);
    }
    int ans=0;
    for(i=0;i<n;i++){
        ans+=(min(left[i],right[i])-h[i]);
    }
    cout<<ans;

    return 0;
}






class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // Edge case: empty array

        vector<int> left(n), right(n);

        // Compute left maximum heights
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        // Compute right maximum heights
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        // Calculate trapped water
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (min(left[i], right[i]) - height[i]);
        }

        return ans;
    }
};


