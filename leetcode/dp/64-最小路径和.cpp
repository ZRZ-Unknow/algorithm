#include <iostream>
#include <vector>
using namespace std;


/*
  dp[i][j]: 从[0,0]到[i,j]的最短路径
  当i>0,j=0时，dp[i][j] = dp[i-1][j] + grid[i][j]
  当i=0,j>0时，dp[i][j] = dp[i][j-1] + grid[i][j]
  当i>0,j>0时，dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]

*/

int minPathSum(vector<vector<int>>& grid) {
    if(grid.size()==0 || grid[0].size()==0) return 0;
    int row = grid.size(), col = grid[0].size();
    auto dp = vector<vector<int>>(row, vector <int> (col));   //Vector<类型>标识符(最大容量,初始所有值)
    dp[0][0] = grid[0][0];
    for(int i=1;i<row;i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(int j=1;j<col;j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            dp[i][j] = [](int a,int b)->int{return a<b?a:b;}(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[row-1][col-1];
}

int main(){
    vector<vector<int>> grid;
    vector<int> a = {1,3,1}, b = {1,5,1}, c = {4,2,1};
    grid.push_back(a); grid.push_back(b); grid.push_back(c);
    cout<<minPathSum(grid)<<endl;
    return 0;
}