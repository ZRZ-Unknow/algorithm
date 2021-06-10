#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


/*
    在一层处，如果没有重复字母，则要么加入s[index]，要么不加入s[index]，两者取最大
*/
bool isUnique(string& s, int& t) {
    //位压缩
    for (char c : s) {
        int i = c-'a';	//获取字符对应位
        //判断该位是否为0
        if (t & (1<<i)) {
            return false;
        }
        t |= (1<<i);
    }
    return true;
}

int dfs(vector<string>& arr, int index, int m){
    if(index >= arr.size()){
        return 0;
    }
    string tar = arr[index];
    int t = m;
    if(isUnique(tar, m)){
        //max(加入，不加入)
        int len1 = tar.length() + dfs(arr, index+1, m);
        int len2 = dfs(arr, index+1, t);
        return max(len1, len2);
    }
    return dfs(arr, index+1, t);

}
int maxLength(vector<string>& arr) {
    int m = 0;
    return dfs(arr, 0, m);
}

int main(){
    vector<string> arr = {"cha","r","act","ers"};
    cout<<maxLength(arr)<<endl;
    return 0;
}