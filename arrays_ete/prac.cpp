#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"enter number of numbers for input";
    cin>>n;
    vector<int>vec(n);

    for(int i = 0; i < vec.size(); i++){
        cin>>vec[i];
    }
        
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout <<endl;
    return 0;
}