#include<bits/stdc++.h>
use namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int maxsum=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_map<int,int> freq;

    for(int i=0;i<n;i++){
        freq[nums[i]]++;
    }
    for(int i=0;i<n;i++){
        int num=nums[i];
        if(freq[num]%2!=0){
            maxsum+=nums[i];
            freq[num]=0;
        }
    }
    cout<<maxsum;
    return 0;
}

//  int sum = 0;
//     for(auto &p : freq){
//         if(p.second % 2 != 0){  // odd frequency
//             sum += p.first;
//         }
//     }

//     cout << sum << "\n";
