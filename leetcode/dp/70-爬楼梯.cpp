#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
    dp[i] : 爬到第i阶的方法数
    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4]=
    dp[i] = dp[i-1] + dp[i-2]：最后一步可能为1也可能为2
*/

int climbStairs(int n) {
    if(n==0 || n==1 || n==2) return n;
    vector<int> dp;
    dp.push_back(1);
    dp.push_back(2);
    for(int i=2;i<n;i++){
        dp.push_back(dp[i-1]+dp[i-2]);
    }
    return dp[n-1];
}

int main(){
    cout<<climbStairs(3)<<endl;
    return 0;
}