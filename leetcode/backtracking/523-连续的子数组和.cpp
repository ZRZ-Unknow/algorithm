#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
前缀数组sum[i]:前i个数的和
设前缀abc, abcdef %k=rem:
   a+b+c = x*k+rem
   a+b+c+d+e+f = y*k+rem
   则d+e+f = (y-x)*k 得到和为k的倍数的子数组和
*/
bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> sums(n+1);
    sums[0] = 0;
    unordered_map<int, int> hash={{0,-1}};
    for(int i=1;i<n+1;i++){
        sums[i] = sums[i-1] + nums[i-1];
        int rem = sums[i]%k;
        if(hash.count(rem)){
            if((i-1-hash[rem])>1){
                return true;
            }
        }else{
            hash[rem] = i-1;
        }
    }
    return false;
}


int main(){
    vector<int> nums = {23,2,4,6,7};
    int k = 6;
    cout<<checkSubarraySum(nums, k)<<endl;
    return 0;
}