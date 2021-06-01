#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    dp[i][j]: s[i:j]是否为回文串
    dp[i][j] = dp[i+1][j-1] && s[i]==s[j]
    边界条件：只有一个或两个字符
*/

string longestPalindrome(string s) {
    int n = s.length();
    int max_len=1, begin_ind=0;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for(int i=n-1;i>=0;i--){
        dp[i][i] = true;
        for(int j=i+1;j<n;j++){
            if(j==i+1){
                dp[i][j] = s[i]==s[j];
            }else{
                dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
            }
            if(dp[i][j] && (j-i+1)>max_len){
                max_len = j-i+1;
                begin_ind = i;
            }
        }
    }
    return s.substr(begin_ind, max_len);
}

int main(){
    string s ="cbbd"; //"cbbdsadfdsabcddcba";
    cout<<longestPalindrome(s)<<endl;
    return 0;
}