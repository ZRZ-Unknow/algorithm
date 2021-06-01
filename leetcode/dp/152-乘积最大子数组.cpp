#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
    这里和53-最大子序和的不同之处：当前位置的最优解未必是由前一个位置的最优解转移得到的
    dp[i]：以nums[i]结尾的最大乘积连续序列(正)
    dps[i]:以nums[i]结尾的最小乘积连续序列(负)
    target: max(dp[i]), i=0,...,n-1
    if nums[i]<0
      dp[i-1]和dps[i-1]对换
     dp[i] = max(dp[i-1]*nums[i], nums[i]) dps[i] = min(dps[i-1]*nums[i], nums[i])
    else dp[i]=dps[i]=0
*/

int maxProduct(vector<int>& nums) {
    int _max = nums[0], dpi = 1, dpii = 1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            int tmp = dpi;
            dpi = dpii;
            dpii = tmp;
        }
        dpi = max(dpi*nums[i], nums[i]);
        dpii = min(dpii*nums[i], nums[i]);
        _max = max(_max, dpi);
    } 
    return _max;
}

int main(){
    vector<int> nums = {0, -2,3,-2,0,4};
    cout<<maxProduct(nums)<<endl;
    return 0;
}