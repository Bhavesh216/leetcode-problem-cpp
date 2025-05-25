// #include <bits/stdc++.h>
// using namespace std;
// int maxDivide(int a, int b)
// {
//     while(a % b == 0)
//     {
//         a = a / b;
//     }
//     return a;
// }
// int isUgly(int n)
// {
//     n = maxDivide(n, 2);
//     n = maxDivide(n, 3);
//     n = maxDivide(n, 5);

//     return (n == 1) ? 1 : 0;
// }
// int getNthUgly(int N)
// {
//     int i = 1;
//     int cnt = 1;

//     while (N > cnt)
//     {
//         i++;
//         if (isUgly(i))
//         {
//             cnt++;
//         }
//     }
//     return i;
// }
// int main()
// {
//     int num;
//     cin >> num;
//     cout << getNthUgly(num);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int maxDiv(int a,int b){
    while(a%b==0){
        a=a/b;
    }
    return a;
}
int isUgly(int num){
    num = maxDiv(num,2);
    num = maxDiv(num,3);
    num = maxDiv(num,5);

    return (num==1)?1:0;
}
int getUgly(int N){
    int i=1;
    int cnt=1;
    while(N>cnt){
        i++;
        if(isUgly(i)){
            cnt++;
        }
    }
    return i;
}
int main() {
    int n;
    cin>>n;
    cout<<getUgly(n);
    
    return 0;
}