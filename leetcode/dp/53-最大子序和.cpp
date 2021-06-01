#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
    dp[i]：以nums[i]结尾的最大连续序列
    dp[i] = max(dp[i-1]+nums[i], nums[i])
*/

int maxSubArray(vector<int>& nums) {
    int _max = nums[0], dpi = 0;
    for(int i=0;i<nums.size();i++){
        dpi = max(dpi+nums[i], nums[i]);
        _max = max(_max, dpi);
    } 
    return _max;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
    return 0;
}