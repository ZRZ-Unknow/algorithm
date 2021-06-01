#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    dp[i][j]: s[i:j]子串中的最长回文
    dp[i][j] = dp[i+1][j-1] + 2 if s[i]==s[j]
    dp[i][j] = max(dp[i][j-1], dp[i+1][j]) if s[i]!=s[j]

*/


int longestPalindromeSubseq(string s) {
    int len = s.length();
    //auto f = vector<vector<int>>(len, vector<int>(len));
    vector<vector<int>> f(len, vector<int>(len));
    for(int i=len-1;i>=0;i--){
        f[i][i] = 1;
        if(i<len-1){
            f[i][i+1] = (s[i]==s[i+1])?2:1;
        }
        for(int j=i+2;j<len;j++){
            if(s[i]==s[j]){
                f[i][j] = f[i+1][j-1] + 2;
            }else{
                f[i][j] = [](int a, int b)->int{return a>b?a:b;}(f[i][j-1], f[i+1][j]);
            }
        }
    }
    return f[0][len-1];
}

int main(){
    string s = "cbbdsadfdsabcddcba";
    cout<<longestPalindromeSubseq(s)<<endl;
    return 0;
}