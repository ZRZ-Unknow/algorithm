#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    dp[i][j]: s1[:i]与s2[:j]的最长公共子序列
    dp[i][0] = 0, dp[0][j] = 0
    dp[i][j] = dp[i-1][j-1] + 1 if s1[i-1]==s2[j-1]
    dp[i][j] = max( dp[i-1][j], dp[i][j-1] ) else
*/


int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=n;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    string text1 = "abcde", text2 = "ace" ;
    cout<<longestCommonSubsequence(text1, text2)<<endl;
    return 0;
}