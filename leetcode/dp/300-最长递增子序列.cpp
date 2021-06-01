#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
    dp[i]:以nums[i]结尾的最长递增子序列
    dp[i] = max(dp[j]) + 1, 且满足 nums[j]<nums[i] 
    target = max(dp[i])
*/
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = 1;
    int _max = dp[0];
    for(int i=0;i<n;i++){
        int tmp = 0;
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i])
                tmp = max(tmp, dp[j]); 
        }
        dp[i] = tmp+1;
        _max = max(_max, dp[i]);
    }
    return _max;
}


int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}