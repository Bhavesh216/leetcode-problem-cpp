struct Item{
    int val;
    int weight;
    double ratio;
};
    
bool cmp(const Item& a, const Item& b){
    return a.ratio>b.ratio;
}
float fractionalKnapsack(int val[], int weight[], int n, int capacity)
{
    vector<Item> v;
  for(int i=0;i<n;i++){
    v.push_back({val[i],weight[i],(double) val[i]/weight[i]});
  }
    sort(v.begin(),v.end(),cmp);
    float totalval=0.0;
    for(int i=0;i<v.size();i++){
       if(v[i].weight<=capacity){
           totalval+=v[i].val;
           capacity-=v[i].weight;
       }
        else{
            totalval+=capacity*v[i].ratio;
            break;
        }
    }
    return totalval;
    
}