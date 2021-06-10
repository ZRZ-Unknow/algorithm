#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


/*
    用dfs遍历树直到遇到长度为n的开心数，加入到res中，此遍历是符合字典序的。
*/
void dfs(vector<string> &res, string tar, int n, int k){
    if(res.size() >= k){
        return;
    }
    if(tar.length() == n){
        res.push_back(tar);
    }else{
        char tmp[3] = {'a', 'b', 'c'};
        for(int i=0;i<3;i++){
            if(tar.size()==0 || tmp[i] != tar[tar.size()-1]){
                dfs(res, tar+tmp[i], n, k);
            }
        }
    }
}

string getHappyString(int n, int k) {
    vector<string> res;
    string s = "";
    dfs(res, s, n, k);
    if(res.size() < k){
        return "";
    }
    return res[k-1]; 
}


int main(){
    cout<<getHappyString(1, 4)<<endl;
    return 0;
}