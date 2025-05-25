#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int firstUniqueChar(string str) {
  // Write your code here
  unordered_map<char, int> map;
    for(int i=0;i<str.size();i++){
        map[str[i]]++;
    }
    int num;
    for(int i=0;i<str.size();i++){
        if(map[str[i]]==1){
           return i;
        }
    }
    return -1;
}