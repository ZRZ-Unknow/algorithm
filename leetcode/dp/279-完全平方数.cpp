#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    dp(n), dp[i]表示n=i时的解
    dp[i] = 1 + min(dp[i-1^2], dp[i-2^2], ..., dp[i-k^2])
*/



int numSquares(int n){
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<n+1;i++){
        int k=1;
        int _min = dp[i-1];
        while(i-k*k>=0){
            _min = min(_min, dp[i-k*k]);
            k++;
        }
        dp[i] = 1 + _min;
    }
    return dp[n];
}



int main(){
    cout<<numSquares(12)<<endl;
    return 0;
}