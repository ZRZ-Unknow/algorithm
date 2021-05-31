#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
  从小到大sort
  dp[i] 表示在输入数组 \textit{nums}nums 升序排列的前提下，以 \textit{nums}[i]nums[i] 为最大整数的「整除子集」的大小

*/

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // 第 1 步：动态规划找出最大子集的个数、最大子集中的最大整数
    vector<int> dp(n, 1);
    int max_size = 1, max_val = dp[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i] % nums[j]==0){
                dp[i] = max(dp[i], dp[j]+1);
            }
        } 
        if(dp[i]>max_size){
            max_size = dp[i];
            max_val = nums[i];
        }
    }
    vector<int> res;
    if(max_size == 1){
        res.push_back(nums[0]);
        return res;
    }
    for(int i=n-1;i>=0 && max_size>0;i--){
        if(max_val % nums[i]==0 && dp[i]==max_size){
            res.push_back(nums[i]);
            max_val = nums[i];
            max_size--;
        }
    }
    return res;
}

int main(){
    vector<int> a = {1,3,2};
    auto res = largestDivisibleSubset(a);
    for_each(res.begin(), res.end(), [](int a){cout<<a<<" ";});
    cout<<endl;
    return 0;
}