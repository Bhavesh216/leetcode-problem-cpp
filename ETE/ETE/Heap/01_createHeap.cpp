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
        size = size + 1;
        int index  = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deletefromheap(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }

        // step 1 : put last element in 1st index
        arr[1] = arr[size];

        // step 2 : remove last element
        size--;

        // step3 : take root node to its correct position
        int i=1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return;
            }
        }
    }
};

int main(){

    heap h ;
    int size;
    cin>>size;
    vector<int> arr(size);
    int t;
    for(int i=0;i<size;i++){
        cin>>t;
        arr[i]=t;
    }
    for(int i=0;i<size;i++){
        h.insert(arr[i]);
    }
    h.print();
    h.deletefromheap();
    h.print();

    // cout<<"Using priority queue"<<endl;
    // // maxheap
    // priority_queue<int> pq;
    // pq.push(4);
    // pq.push(2);
    // pq.push(5);
    // pq.push(3);


    return 0;   
}