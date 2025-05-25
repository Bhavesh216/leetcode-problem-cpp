#include<bits/stdc++.h>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size = 0;
    }

    void insert(int val){
        size++;
        int index = size;
        arr[index]=val;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void deleteFromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];

        size--;

        int i=1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};
int main(){
    heap h;
    int size;
    cin>>size;
    int t;
    // 50 55 53 52 54
    for(int i=0;i<size;i++){
        cin>>t;
        h.insert(t);
    }
    h.print();
    h.deleteFromHeap();
    h.print();
    return 0;
}