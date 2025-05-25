void countFrequency(string str) {
  // write your code here
  unordered_map<char,int> map;
    for(int i=0;i<str.size();i++){
        map[str[i]]++;
    }
    
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(map[ch]!=-1){
          cout<<ch<<map[ch]<<" ";
          map[ch]=-1;
        }
     }
    cout<<endl;
}


